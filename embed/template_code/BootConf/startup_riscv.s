    .section .init;
    .globl _prog_start;
    .type _prog_start,@function


_prog_start:
.option push
.option norelax
	la gp, _sdata
.option pop
	la sp, _estack
#ifdef SIMULATION
    li x26, 0x00
    li x27, 0x00
#endif

	/* Load data section */
	la a0, _sdata
	la a1, _sdata
	la a2, _edata
	bgeu a1, a2, 2f
1:
	lw t0, (a0)
	sw t0, (a1)
	addi a0, a0, 4
	addi a1, a1, 4
	bltu a1, a2, 1b
2:

	/* Clear bss section */
	la a0, _sbss
	la a1, _ebss
	bgeu a0, a1, 2f
1:
	sw zero, (a0)
	addi a0, a0, 4
	bltu a0, a1, 1b
2:

    call SystemInit
    call main

#ifdef SIMULATION
    li x26, 0x01
#endif

loop:
    j loop