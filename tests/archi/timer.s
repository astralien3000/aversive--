	.file	"timer.cpp"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	__vector_10
	.type	__vector_10, @function
__vector_10:
/* prologue: naked */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	in r18,__SREG__
	lds r24,toogle
	lds r25,toogle+1
	sbiw r24,0
	breq .L2
	ldi r24,lo8(-1)
	out 0x18,r24
	rjmp .L3
.L2:
	out 0x18,__zero_reg__
.L3:
	out __SREG__,r18
/* #APP */
 ;  16 "timer.cpp" 1
	reti
 ;  0 "" 2
/* epilogue start */
/* #NOAPP */
	.size	__vector_10, .-__vector_10
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r24,lo8(1)
	out 0x33,r24
	ldi r24,lo8(2)
	out 0x39,r24
	ldi r24,lo8(-1)
	out 0x12,r24
	ldi r24,0
	ldi r25,0
	ret
	.size	main, .-main
.global	toogle
	.section .bss
	.type	toogle, @object
	.size	toogle, 2
toogle:
	.zero	2
	.ident	"GCC: (GNU) 4.7.2"
.global __do_clear_bss
