KERNEL_STACK_SIZE = 65536;
OUTPUT_FORMAT(pei-i386);
OUTPUT_ARCH(i386);

ENTRY(__start);

SECTIONS
{
  . = SIZEOF_HEADERS;
  . = ALIGN(__section_alignment__);

  .text __image_base__ + (__section_alignment__ < 0x1000 ? . : __section_alignment__) :
  {
    __sinittext = .;
    *(.init.text .init.text.*);
    *(.meminit.text*);
    __einittext = .;

    *(.init);

    __stext = .;

    . = ALIGN(0);
    __noinstr_text_start = .;
    *(.noinstr.text);
    __cpuidle_text_start = .;

    . = ALIGN(0);
    ___cpuidle_text_start = .;
    *(.cpuidle.text)
    ___cpuidle_text_end = .;

    *(.ref.text);

    . = ALIGN(0);
    ___sched_text_start = .;
    *(.sched.text)
    ___sched_text_end = .;

    . = ALIGN(0);
    ___softirqentry_text_start = .;
    *(.softirqentry.text);
    ___softirqentry_text_end = .;

    /* Linux weak symbols */
    ___div64_32 = .;
    KEEP(*(.weak.___div64_32.default._div_s64_rem));
    _init_uts_ns = .;
    KEEP(*(.weak._init_uts_ns.default._linux_proc_banner));
    _linux_banner = .;
    KEEP(*(.weak._linux_banner.default._linux_proc_banner));
    _arch_prctl_spec_ctrl_get = .;
    KEEP(*(.weak._arch_prctl_spec_ctrl_get.default._early_initcall_stub));
    _arch_early_irq_init = .;
    KEEP(*(.weak._arch_early_irq_init.default.__local_bh_enable));
    _arch_dynirq_lower_bound = .;
    KEEP(*(.weak._arch_dynirq_lower_bound.default.__local_bh_enable));
    _sched_clock = .;
    KEEP(*(.weak._sched_clock.default._sched_clock_init));
    _clocksource_default_clock = .;
    KEEP(*(.weak._clocksource_default_clock.default._get_jiffies_64));
    _pgtable_cache_init = .;
    KEEP(*(.weak._pgtable_cache_init.default._reset_devices));

    *(.text);
    *(SORT(.text$*));
    *(.text.*);
    *(.gnu.linkonce.t.*);
    *(.glue_7t);
    *(.glue_7);

    *(.exit.text);
    *(.text.exit);

    ___CTOR_LIST__ = .;
    __CTOR_LIST__ = . ;
    LONG (-1);
    *(.ctors);
    *(.ctor);
    *(SORT(.ctors.*));
    LONG (0);

    ___DTOR_LIST__ = .;
    __DTOR_LIST__ = . ;
    LONG (-1);
    *(.dtors);
    *(.dtor);
    *(SORT(.dtors.*));
    LONG (0);
    *(.fini);
    *(.gcc_exc);

    PROVIDE (etext = .);
    PROVIDE (_etext = .);

    *(.gcc_except_table);

    __etext = .;
  }

  .data BLOCK(__section_alignment__) :
  {
    __data_start__ = . ;

    . = ALIGN(KERNEL_STACK_SIZE);
    _init_stack = .;
    KEEP(*(.data..init_task))
    . = _init_stack + (KERNEL_STACK_SIZE);

    . = ALIGN(32);
    ___start_init_task = .;
    KEEP(*(.data..init_thread_info))
    ___end_init_task = .;

    __sdata = .;

    ___init_begin = .;
    *(.init.data .init.data.*);
    *(.meminit.data*);
    *(.init.rodata .init.rodata.*);
    *(.meminit.rodata);
    ___init_end = .;

    ___start___param = .;
    KEEP(*(__param));
    ___stop___param = .;

    ___start_notes = .;
    KEEP(*(.note.*));
    ___stop_notes = .;

    *(.data);
    *(.data2);
    *(.ref.data);
    *(.data.* .gnu.linkonce.d.*);
    *(SORT(.data$*));

    ___start_rodata = .;
    *(.rodata);
    *(.rodata.*);
    . = ALIGN(32);
    ___end_rodata = .;

    ___start___ex_table = .;
    KEEP(*(__ex_table));
    ___stop___ex_table = .;

    ___start___modver = .;
    KEEP(*(__modver));
    ___stop___modver = .;


    ___setup_start = .;
    KEEP(*(.init.setup));
    ___setup_end = .;

    ___initcall_start = .;
    KEEP(*(.initcallearly.init));
    ___initcall0_start = .;
    KEEP(*(.initcall0.init));
    KEEP(*(.initcall0s.init));
    ___initcall1_start = .;
    KEEP(*(.initcall1.init));
    KEEP(*(.initcall1s.init));
    ___initcall2_start = .;
    KEEP(*(.initcall2.init));
    KEEP(*(.initcall2s.init));
    ___initcall3_start = .;
    KEEP(*(.initcall3.init));
    KEEP(*(.initcall3s.init));
    ___initcall4_start = .;
    KEEP(*(.initcall4.init));
    KEEP(*(.initcall4s.init));
    ___initcall5_start = .;
    KEEP(*(.initcall5.init));
    KEEP(*(.initcall5s.init));
    ___initcallrootfs_start = .;
    KEEP(*(.initcallrootfs.init));
    KEEP(*(.initcallrootfss.init));
    ___initcall6_start = .;
    KEEP(*(.initcall6.init));
    KEEP(*(.initcall6s.init));
    ___initcall7_start = .;
    KEEP(*(.initcall7.init));
    KEEP(*(.initcall7s.init));
    ___initcall_end = .;

    ___con_initcall_start = .;
    KEEP(*(.con_initcall.init));
    ___con_initcall_end = .;

    ___exitcall_begin = .;
    *(.exitcall.exit);
    ___exitcall_end = .;

    . = ALIGN(32);
    ___sched_class_highest = .;
    *(__stop_sched_class);
    *(__dl_sched_class);
    *(__rt_sched_class);
    *(__fair_sched_class);
    *(__idle_sched_class);
    ___sched_class_lowest = .;

    ___start_initcall_main = .;
    *(initcall_main);
    ___stop_initcall_main = .;

    *(.jcr);
    __edata = .;

    __data_end__ = . ;
    *(.data_cygwin_nocopy);
  }

  .rdata BLOCK(__section_alignment__) :
  {
    *(.rdata);
    *(SORT(.rdata$*));
    *(.jsdata.*);
    __rt_psrelocs_start = .;
    *(.rdata_runtime_pseudo_reloc);
    __rt_psrelocs_end = .;
  }

  __rt_psrelocs_size = __rt_psrelocs_end - __rt_psrelocs_start;
  ___RUNTIME_PSEUDO_RELOC_LIST_END__ = .;
  __RUNTIME_PSEUDO_RELOC_LIST_END__ = .;
  ___RUNTIME_PSEUDO_RELOC_LIST__ = . - __rt_psrelocs_size;
  __RUNTIME_PSEUDO_RELOC_LIST__ = . - __rt_psrelocs_size;

  .eh_frame BLOCK(__section_alignment__) :
  {
    *(.eh_frame*);
  }

  .pdata BLOCK(__section_alignment__) :
  {
    *(.pdata*);
  }

  .bss BLOCK(__section_alignment__) :
  {
    __bss_start__ = . ;
    ___bss_start = .;
    *(.dynbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON);
    ___bss_stop = .;
    __bss_end__ = . ;
  }

  .edata BLOCK(__section_alignment__) :
  {
    *(.edata);
  }

  /DISCARD/ :
  {
    *(.debug$S);
    *(.debug$T);
    *(.debug$F);
    *(.drectve);
    *(.note.GNU-stack);
    *(.gnu.lto_*);
    *(.modinfo);
  }

  .idata BLOCK(__section_alignment__) :
  {
    SORT(*)(.idata$2);
    SORT(*)(.idata$3);
    LONG (0);
    LONG (0);
    LONG (0);
    LONG (0);
    LONG (0);
    SORT(*)(.idata$4);
    __IAT_start__ = .;
    SORT(*)(.idata$5);
    __IAT_end__ = .;
    SORT(*)(.idata$6);
    SORT(*)(.idata$7);
  }

  .CRT BLOCK(__section_alignment__) :
  {
    ___crt_xc_start__ = . ;
    *(SORT(.CRT$XC*));
    ___crt_xc_end__ = . ;
    ___crt_xi_start__ = . ;
    *(SORT(.CRT$XI*));
    ___crt_xi_end__ = . ;
    ___crt_xl_start__ = . ;
    *(SORT(.CRT$XL*));
    ___crt_xp_start__ = . ;
    *(SORT(.CRT$XP*));
    ___crt_xp_end__ = . ;
    ___crt_xt_start__ = . ;
    *(SORT(.CRT$XT*));
    ___crt_xt_end__ = . ;
  }

  .tls BLOCK(__section_alignment__) :
  {
    ___tls_start__ = . ;
    *(.tls$AAA);
    *(.tls);
    *(.tls$);
    *(SORT(.tls$*));
    *(.tls$ZZZ);
    ___tls_end__ = . ;
  }

  .endjunk BLOCK(__section_alignment__) :
  {
    PROVIDE (end = .);
    PROVIDE ( _end = .);
     __end__ = .;
  }

  .rsrc BLOCK(__section_alignment__) :
  {
    *(.rsrc);
    *(.rsrc$*);
  }

  .reloc BLOCK(__section_alignment__) :
  {
    *(.reloc);
  }

  .stab BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.stab);
  }

  .stabstr BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.stabstr);
  }

  .debug_aranges BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_aranges);
  }

  .zdebug_aranges BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_aranges);
  }

  .debug_pubnames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_pubnames);
  }

  .zdebug_pubnames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_pubnames);
  }

  .debug_pubtypes BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_pubtypes);
  }

  .zdebug_pubtypes BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_pubtypes);
  }

  .debug_info BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_info .gnu.linkonce.wi.*);
  }

  .zdebug_info BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_info .zdebug.gnu.linkonce.wi.*);
  }

  .debug_abbrev BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_abbrev);
  }

  .zdebug_abbrev BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_abbrev);
  }

  .debug_line BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_line);
  }

  .zdebug_line BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_line);
  }

  .debug_frame BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_frame*);
  }

  .zdebug_frame BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_frame*);
  }

  .debug_str BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_str);
  }

  .zdebug_str BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_str);
  }

  .debug_loc BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_loc);
  }

  .zdebug_loc BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_loc);
  }

  .debug_macinfo BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_macinfo);
  }

  .zdebug_macinfo BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_macinfo);
  }

  .debug_weaknames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_weaknames);
  }

  .zdebug_weaknames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_weaknames);
  }

  .debug_funcnames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_funcnames);
  }

  .zdebug_funcnames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_funcnames);
  }

  .debug_typenames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_typenames);
  }

  .zdebug_typenames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_typenames);
  }

  .debug_varnames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_varnames);
  }

  .zdebug_varnames BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_varnames);
  }

  .debug_macro BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_macro);
  }

  .zdebug_macro BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_macro);
  }

  .debug_ranges BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_ranges);
  }

  .zdebug_ranges BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_ranges);
  }

  .debug_types BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_types .gnu.linkonce.wt.*);
  }

  .zdebug_types BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_types .gnu.linkonce.wt.*);
  }

  .debug_gdb_scripts BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.debug_gdb_scripts);
  }

  .zdebug_gdb_scripts BLOCK(__section_alignment__) (NOLOAD) :
  {
    *(.zdebug_gdb_scripts);
  }
}
