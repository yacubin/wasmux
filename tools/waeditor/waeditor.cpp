#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <string>
#include <vector>

#include <wasmux/wasm_header.h>
#include <wasmux/wasm_module.h>
#include <wasmux/cxx/Leb128.h>

struct Options {
  bool addUserMemory{false};
  const char* filename{nullptr};
};

struct WasmSection {
  uint8_t id;
  std::vector<uint8_t> data;
};

struct WasmModule {
  struct wasm_header header;
  std::vector<WasmSection> sections;

  void dump() const;
  bool writeTo(const char* filename) const;

  struct MemoryInfo {
    std::string module;
    std::string name;
    uint32_t minValue;
    uint32_t maxValue;
    bool shared;
  };

  const WasmSection* getSectionById(uint8_t id) const;
  bool getImportMemory(MemoryInfo& result) const;
  void addImportMemory(const MemoryInfo& result);
};

static size_t getName(const uint8_t* data, const uint8_t* end, std::string& result)
{
  uint32_t length;
  uint32_t lengthSize = wasmux::readLeb128(data, end - data, length);
  if (lengthSize == 0) {
    printf("[waeditor] Length of name has wrong format\n");
    return 0;
  }
  data += lengthSize;
  if (end < data + length) {
    printf("[waeditor] Unexpected end of name reached\n");
    return 0;
  }
  result.resize(length);
  memcpy(&result[0], data, length);
  return lengthSize + length;
}

void WasmModule::dump() const
{
  printf("[waeditor] Magic 0x%04X\n", this->header.magic);
  printf("[waeditor] Version %u\n", this->header.version);
  printf("[waeditor] Sections:\n");

  for (const auto& iter : this->sections) {
    printf("[waeditor]   %s (size %llu)\n", wa_strsecid(iter.id), static_cast<unsigned long long>(iter.data.size()));
  }
}

const WasmSection* WasmModule::getSectionById(uint8_t id) const
{
  for (const auto& iter : this->sections) {
    if (iter.id == id)
      return &iter;
  }
  return nullptr;
}

bool WasmModule::getImportMemory(MemoryInfo& result) const
{
  const WasmSection* importSection = getSectionById(WASM_SECTION_IMPORT_ID);
  auto sectionData = importSection->data.data();
  auto sectionEnd = sectionData + importSection->data.size();

  while (sectionData < sectionEnd) {
    uint32_t vectorCount;
    uint32_t vectorCountSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, vectorCount);
    if (vectorCountSize == 0) {
      printf("[waeditor] Import vector count format is wrong\n");
      return false;
    }
    sectionData += vectorCountSize;
    for (size_t i = 0; i < vectorCount; i++) {
      std::string mod;
      size_t modSize = getName(sectionData, sectionEnd, mod);
      if (modSize == 0) {
          printf("[waeditor] Import module format is wrong\n");
          return false;
      }
      sectionData += modSize;

      std::string name;
      size_t nameSize = getName(sectionData, sectionEnd, name);
      if (nameSize == 0) {
          printf("[waeditor] Import name format is wrong\n");
          return false;
      }
      sectionData += nameSize;

      if (sectionEnd <= sectionData) {
          printf("[waeditor] Import desc format is wrong\n");
          return false;
      }

      uint8_t importId = *sectionData++;
      switch (importId) {
      case WASM_IMPORT_FUNC_ID: {
        uint32_t typeidx;
        size_t typeidxSize =  wasmux::readLeb128(sectionData, sectionEnd - sectionData, typeidx);
        if (typeidxSize == 0) {
          printf("[waeditor] Unexpected end of typeidx reached\n");
          return 0;
        }
        sectionData += typeidxSize;
        printf("[waeditor]   typeidx %u\n", typeidx);
        break;
      }
      case WASM_IMPORT_MEM_ID: {
        uint32_t minValue;
        uint32_t maxValue;
        bool hasMaxValue = false;
        bool shared = false;

        uint8_t memtype = *sectionData++;
        if (memtype == 0x03) {
          shared = true;
          hasMaxValue = true;

          size_t minValueSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, minValue);
          if (minValueSize == 0) {
              printf("[waeditor] Import mem min format is wrong\n");
              return false;
          }
          sectionData += minValueSize;

          size_t maxValueSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, maxValue);
          if (maxValueSize == 0) {
              printf("[waeditor] Import mem max format is wrong\n");
              return false;
          }
          sectionData += maxValueSize;
        }
        else {
          printf("[waeditor] Unknown import memtype\n");
          return false;
        }
        result.module = std::move(mod);
        result.name = std::move(name);
        result.minValue = minValue;
        result.maxValue = maxValue;
        result.shared = shared;
        return true;;
      }
      default:
        printf("[waeditor] Unknown import id - %u\n", importId);
        return false;
      }
    }
  }

  return false;
}

void WasmModule::addImportMemory(const MemoryInfo& result)
{
  WasmSection* importSection = const_cast<WasmSection*>(getSectionById(WASM_SECTION_IMPORT_ID));
  auto& bytes = importSection->data;

  wasmux::Leb128Traits<uint32_t>::Buffer buffer;

  size_t modLengthSize = wasmux::writeLeb128(result.module.length(), buffer);
  bytes.insert(bytes.end(), buffer, buffer + modLengthSize);
  bytes.insert(bytes.end(), result.module.data(), result.module.data() + result.module.length());

  size_t nameLengthSize = wasmux::writeLeb128(result.name.length(), buffer);
  bytes.insert(bytes.end(), buffer, buffer + nameLengthSize);
  bytes.insert(bytes.end(), result.name.data(), result.name.data() + result.name.length());

  bytes.push_back(WASM_IMPORT_MEM_ID);
  bytes.push_back(0x03);

  size_t minValueSize = wasmux::writeLeb128(result.minValue, buffer);
  bytes.insert(bytes.end(), buffer, buffer + minValueSize);

  size_t maxValueSize = wasmux::writeLeb128(result.maxValue, buffer);
  bytes.insert(bytes.end(), buffer, buffer + maxValueSize);

  bytes[0]++; // FIXME
}

static bool fileWrite(FILE* file, const void* data, size_t size)
{
  return fwrite(data, 1, size, file) == size;
}

bool WasmModule::writeTo(const char* filename) const
{
  FILE* file = fopen(filename, "wb");
  if (!file) {
    printf("[waeditor] File '%s' not exists\n", filename);
    return false;
  }
  
  if (!fileWrite(file, &this->header.magic, sizeof(this->header.magic))) {
    printf("[waeditor] Can not write to '%s'\n", filename);
    fclose(file);
    return false;
  }

  if (!fileWrite(file, &this->header.version, sizeof(this->header.version))) {
    printf("[waeditor] Can not write to '%s'\n", filename);
    fclose(file);
    return false;
  }

  for (const auto& iter : this->sections) {
    wasmux::Leb128Traits<uint32_t>::Buffer buffer;
    size_t sectionLengthSize = wasmux::writeLeb128(iter.data.size(), buffer);

    if (!fileWrite(file, &iter.id, sizeof(iter.id))) {
      printf("[waeditor] Can not write to '%s'\n", filename);
      fclose(file);
      return false;
    }
    if (!fileWrite(file, buffer, sectionLengthSize)) {
      printf("[waeditor] Can not write to '%s'\n", filename);
      fclose(file);
      return false;
    }
    if (!fileWrite(file, iter.data.data(), iter.data.size())) {
      printf("[waeditor] Can not write to '%s'\n", filename);
      fclose(file);
      return false;
    }
  }

  return true;
}

bool readBytesFromFile(const char* filename, std::vector<uint8_t>& result)
{
  FILE* file = fopen(filename, "rb");
  if (!file) {
    printf("[waeditor] File '%s' not exists\n", filename);
    return false;
  }

  fseek(file, 0L, SEEK_END);
  long long fileSize = ftell(file);
  fseek(file, 0L, SEEK_SET);

  result.resize(fileSize);

  uint8_t* data = result.data();
  while (fileSize) {
    size_t sz = fread(data, 1, fileSize, file);
    if (sz != fileSize) {
      printf("[waeditor] Cannot read '%s'\n", filename);
      return false;
    }
    fileSize -= sz;
  }

  fclose(file);
  return true;
}

static inline size_t getUint8(const void* ptr, uint8_t& value)
{
  value = *reinterpret_cast<const uint8_t*>(ptr);
  return sizeof(value);
}

static inline size_t getUint32LE(const void* ptr, uint32_t& value)
{
  memcpy(&value, ptr, sizeof(value));
  return sizeof(value);
}

static bool printModule(const std::vector<uint8_t>& bytes, WasmModule& module)
{
  const uint8_t* data = bytes.data();
  const uint8_t* pos = data;
  const uint8_t* end = data + bytes.size();

  // magic
  {
    uint32_t magic;

    if (end < pos + sizeof(magic)) {
      printf("[waeditor] Not enough data for magic\n");
      return false;
    }

    pos += getUint32LE(pos, magic);
    if (magic != WASM_MAGIC) {
      printf("[waeditor] Magic is not correct 0x%04X\n", magic);
      return false;
    }

    printf("[waeditor] Magic 0x%04X\n", magic);
    module.header.magic = magic;
  }

  // version
  {
    uint32_t version;

    if (end < pos + sizeof(version)) {
      printf("[waeditor] Not enough data for version\n");
      return false;
    }

    pos += getUint32LE(pos, version);
    if (version != WASM_VERSION) {
      printf("[waeditor] Version is not correct 0x%04X\n", version);
      return false;
    }

    printf("[waeditor] Version %u\n", version);
    module.header.version = version;
  }

  while (pos < end) {
    uint8_t sectionId;

    const uint8_t* sectionPos = pos;

    pos += getUint8(pos, sectionId);
    switch (sectionId) {
    case WASM_SECTION_CUSTOM_ID:
    case WASM_SECTION_TYPE_ID:
    case WASM_SECTION_IMPORT_ID:
    case WASM_SECTION_FUNCTION_ID:
    case WASM_SECTION_TABLE_ID:
    case WASM_SECTION_MEMORY_ID:
    case WASM_SECTION_GLOBAL_ID:
    case WASM_SECTION_EXPORT_ID:
    case WASM_SECTION_START_ID:
    case WASM_SECTION_ELEMENT_ID:
    case WASM_SECTION_CODE_ID:
    case WASM_SECTION_DATA_ID:
    case WASM_SECTION_DATA_COUNT_ID:
      break;
    default:
      printf("[waeditor] Unknown section id %i\n", sectionId);
      return false;
    }

    uint32_t contentSize;

    uint32_t sectionSizeOffset = static_cast<uint32_t>(pos - data);
    uint32_t sectionSizeSize = wasmux::readLeb128(pos, end - pos, contentSize);

    if (sectionSizeSize == 0) {
      printf("[waeditor] Size format is wrong\n");
      return false;
    }
    
    pos += sectionSizeSize;

    std::vector<uint8_t> sectionBytes;
    sectionBytes.insert(sectionBytes.end(), pos, pos + contentSize);
    module.sections.push_back({sectionId, std::move(sectionBytes)});

    printf("[waeditor] %s section, size %u\n", wa_strsecid(sectionId), contentSize);
    {
      const uint8_t* sectionData = pos;
      const uint8_t* sectionEnd = sectionData + contentSize;

      switch (sectionId) {
      case WASM_SECTION_IMPORT_ID: {
        while (sectionData < sectionEnd) {
          uint32_t vectorCount;
          uint32_t vectorCountSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, vectorCount);
          if (vectorCountSize == 0) {
            printf("[waeditor] Import vector count format is wrong\n");
            return false;
          }
          sectionData += vectorCountSize;
          for (size_t i = 0; i < vectorCount; i++) {
            std::string mod;
            size_t modSize = getName(sectionData, sectionEnd, mod);
            if (modSize == 0) {
                printf("[waeditor] Import module format is wrong\n");
                return false;
            }
            sectionData += modSize;

            std::string name;
            size_t nameSize = getName(sectionData, sectionEnd, name);
            if (nameSize == 0) {
                printf("[waeditor] Import name format is wrong\n");
                return false;
            }
            sectionData += nameSize;

            if (sectionEnd <= sectionData) {
                printf("[waeditor] Import desc format is wrong\n");
                return false;
            }

            uint8_t importId = *sectionData++;
            switch (importId) {
            case WASM_IMPORT_FUNC_ID: {
              uint32_t typeidx;
              size_t typeidxSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, typeidx);
              if (typeidxSize == 0) {
                printf("[waeditor] Unexpected end of typeidx reached\n");
                return 0;
              }
              sectionData += typeidxSize;
              printf("[waeditor]   typeidx %u\n", typeidx);
              break;
            }
            case WASM_IMPORT_MEM_ID: {
              uint32_t minValue;
              uint32_t maxValue;
              bool hasMaxValue = false;
              bool shared = false;
              if (sectionEnd <= sectionData) {
                printf("[waeditor] Unexpected end of memtype reached\n");
                return 0;
              }
              uint8_t memtype = *sectionData++;
              if (memtype == 0x03) {
                shared = true;
                hasMaxValue = true;

                size_t minValueSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, minValue);
                if (minValueSize == 0) {
                    printf("[waeditor] Import mem min format is wrong\n");
                    return false;
                }
                sectionData += minValueSize;

                size_t maxValueSize = wasmux::readLeb128(sectionData, sectionEnd - sectionData, maxValue);
                if (maxValueSize == 0) {
                    printf("[waeditor] Import mem max format is wrong\n");
                    return false;
                }
                sectionData += maxValueSize;

                printf("[waeditor]   memory (min %u max %u shared)\n", minValue, maxValue);
              }
              else {
                printf("[waeditor] Unknown import memtype\n");
                return false;
              }
              break;
            }
            default:
              printf("[waeditor] Unknown import id - %u\n", importId);
              return false;
            }
          }
        }
        break;
        }
        default:
          sectionData = sectionEnd;
          break;
      };

      if (sectionData != sectionEnd) {
        printf("[waeditor] There is extra data left in the section\n");
        return false;
      }
    }
  
    pos += contentSize;
  }

  return true;
}

int main(int argc, char** argv)
{  
  Options options;

  for (int i = 1; i < argc; i++) {
    const char* iter = argv[i];
    if (!strcmp(iter, "--add-user-memory")) {
      options.addUserMemory = true;
      continue;
    }
    else if (!options.filename) {
      options.filename = iter;
      continue;
    }
    else {
      printf("[waeditor] Unknown parameter '%s'\n", iter);
      return EXIT_FAILURE;
    }
  }

  if (!options.filename) {
    printf("[waeditor] File name missing\n");
    return EXIT_FAILURE;
  }

  std::vector<uint8_t> bytes;
  if (!readBytesFromFile(options.filename, bytes)) {
    printf("[waeditor] File '%s' not exists\n", options.filename);
    return EXIT_FAILURE;
  }
  
  WasmModule module;
  if (!printModule(bytes, module)) {
    printf("[waeditor] Module '%s' is wrong\n", options.filename);
    return EXIT_FAILURE;
  }

  module.dump();

  WasmModule::MemoryInfo meminfo;
  if (!module.getImportMemory(meminfo)) {
    printf("[waeditor] Cannot get import memory\n");
    return EXIT_FAILURE;
  }
  meminfo.module = "user";
  meminfo.name = "memory";
  module.addImportMemory(meminfo);

  std::string filename2 = options.filename;
  /* filename2 += ".bkp";
  if (!module.writeTo(filename2.c_str())) {
    printf("[waeditor] Cannot write file '%s'\n", filename2.c_str());
    return EXIT_FAILURE;
  }*/

  printf("[waeditor] SUCCESS\n");
  return EXIT_SUCCESS;
}
