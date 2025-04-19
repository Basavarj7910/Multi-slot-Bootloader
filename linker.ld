ENTRY(Reset_Handler)
MEMORY
{
	FLASH(rx): ORIGIN = 0x08000000, LENGTH = 32K
	SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 128K
	SHARED_FLASH(rx): ORIGIN = 0x08008000, LENGTH = 16K
}

SECTIONS
{
	.text : {
		*(.isr_vector)
		*(.text)
		*(.rodata)
		_etext = .;
	} > FLASH
    
    .common_apis  0x08008000: {
        KEEP(*(.common_apis))
    } > SHARED_FLASH

	.data : {
		_sdata = .;
		*(.data)
		_edata = .;
	} > SRAM AT > FLASH

	.bss : {
		_sbss = .;
		*(.bss)
		_ebss = .;
	} > SRAM

}
