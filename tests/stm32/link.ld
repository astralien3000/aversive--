/*
   Default linker script for STM32F10x_512K_64K
   Copyright RAISONANCE S.A.S. 2008

   Modified for High Density devices
   by Francois Gervais, August 2009
   Modified for C++ support with the help of generic.ld
   from CodeSourcery G++ Lite
   by Francois Gervais, Septembre 2009

   Modifications for F4FEZ templates 2010

   Modified for AUSBEE support
   by Kevin JOLY 2013
 */
/* include the common STM32F10x sub-script */
/* Common part of the linker scripts for STM32 devices*/
/* default stack sizes. 

   These are used by the startup in order to allocate stacks for the different modes.
 */
__Stack_Size = 1024 ;
PROVIDE ( _Stack_Size = __Stack_Size ) ;
__Stack_Init = _estack - __Stack_Size ;
/*"PROVIDE" allows to easily override these values from an object file or the commmand line.*/
PROVIDE ( _Stack_Init = __Stack_Init ) ;
/*
   There will be a link error if there is not this amount of RAM free at the end.
 */
_Minimum_Stack_Size = 0x100 ;
/* include the memory spaces definitions sub-script */
/*
   Linker subscript for STM32F10x definitions with 512K Flash and 64K RAM */
/* Memory Spaces Definitions */
MEMORY
{
    RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 10K
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32K
    FLASHB1 (rx) : ORIGIN = 0x00000000, LENGTH = 0
    EXTMEMB0 (rx) : ORIGIN = 0x00000000, LENGTH = 0
    EXTMEMB1 (rx) : ORIGIN = 0x00000000, LENGTH = 0
    EXTMEMB2 (rx) : ORIGIN = 0x00000000, LENGTH = 0
    EXTMEMB3 (rx) : ORIGIN = 0x00000000, LENGTH = 0
}
/* higher address of the user mode stack */
_estack = ORIGIN(RAM)+LENGTH(RAM);
/* include the sections management sub-script for FLASH mode */
/* Sections Definitions */
SECTIONS
{
    /* for Cortex devices, the beginning of the startup code is stored in the .isr_vector section, which goes to FLASH */
    .isr_vector :
    {
        _stext = .;
        . = ALIGN(4);
        KEEP(*(.isr_vector)) /* Startup code */
            . = ALIGN(4);
    } >FLASH
    /* for some STRx devices, the beginning of the startup code is stored in the .flashtext section, which goes to FLASH */
    .flashtext :
    {
        . = ALIGN(4);
        *(.flashtext) /* Startup code */
            . = ALIGN(4);
    } >FLASH
    /* the program code is stored in the .text section, which goes to Flash */
    .text :
    {
        . = ALIGN(4);
        *(.text .text.* .gnu.linkonce.t.*)
            *(.plt)
            *(.gnu.warning)
            *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
            *(.ARM.extab* .gnu.linkonce.armextab.*)
            *(.gcc_except_table)
    } >FLASH
    .eh_frame_hdr : ALIGN (4)
    {
        KEEP (*(.eh_frame_hdr))
    } >FLASH
    .eh_frame : ALIGN (4)
    {
        KEEP (*(.eh_frame))
    } >FLASH
    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } >FLASH
    __exidx_end = .;
    .rodata : ALIGN (4)
    {
        *(.rodata .rodata.* .gnu.linkonce.r.*)
            . = ALIGN(4);
        KEEP(*(.init))
            . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
            __preinit_array_end = .;
        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
            KEEP (*(.init_array))
            __init_array_end = .;
        . = ALIGN(4);
        KEEP(*(.fini))
            . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
            KEEP (*(SORT(.fini_array.*)))
            __fini_array_end = .;
        . = ALIGN(4);
        KEEP (*crtbegin.o(.ctors))
            KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
            KEEP (*(SORT(.ctors.*)))
            KEEP (*crtend.o(.ctors))
            . = ALIGN(4);
        KEEP (*crtbegin.o(.dtors))
            KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
            KEEP (*(SORT(.dtors.*)))
            KEEP (*crtend.o(.dtors))
            . = ALIGN(4);
        _etext = .;
        /* This is used by the startup in order to initialize the .data secion */
        _sidata = _etext;
    } >FLASH
    PROVIDE ( _sflash = _stext );
    PROVIDE ( _eflash = _etext );
    /* This is the initialized data section
       The program executes knowing that the data is in the RAM
       but the loader puts the initial values in the FLASH (inidata).
       It is one task of the startup to copy the initial values from FLASH to RAM. */
    .data : AT ( _sidata )
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _sdata = . ;
        KEEP(*(.jcr))
            *(.got.plt) *(.got)
            *(.shdata)
            *(.data .data.* .gnu.linkonce.d.*)
            . = ALIGN(4);
        /* This is used by the startup in order to initialize the .data secion */
        _edata = . ;
    } >RAM
    /* This is the uninitialized data section */
    .bss :
    {
        . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _sbss = .;
        *(.shbss)
            *(.bss .bss.* .gnu.linkonce.b.*)
            *(COMMON)
            . = ALIGN(4);
        /* This is used by the startup in order to initialize the .bss secion */
        _ebss = . ;
        . = ALIGN(4);
    } >RAM
    /* Heap start after the last allocate block */
    PROVIDE ( _sheap = _ebss );
    PROVIDE ( _eheap = __Stack_Init );
    /* Heap end before the stack */
    /* This is the user stack section 
       This is just to check that there is enough RAM left for the User mode stack
       It should generate an error if it's full.
     */
    ._usrstack :
    {
        . = ALIGN(4);
        _susrstack = . ;
        . = . + _Minimum_Stack_Size ;
        . = ALIGN(4);
        _eusrstack = . ;
    } >RAM
}
