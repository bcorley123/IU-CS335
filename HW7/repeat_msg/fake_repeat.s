	.Ltext0:
		.section	.rodata
	.LC0:
	0000 7A65726F 		.string	"zero"
	     00
	.LC1:
	0005 6F6E6500 		.string	"one"
		.text
		.globl	repeat_msg
repeat_msg:
	.LFB0:
		.cfi_startproc
	0000 55       		pushq	%rbp
		.cfi_def_cfa_offset 16
		.cfi_offset 6, -16
	0001 4889E5   		movq	%rsp, %rbp
		.cfi_def_cfa_register 6
	0004 4883EC20 		subq	$32, %rsp
	0008 897DEC   		movl	%edi, -20(%rbp)
	000b 8975E8   		movl	%esi, -24(%rbp)
	000e C745F400 		movl	$0, -12(%rbp)
	     000000
	0015 EB28     		jmp	.L2
	.L5:
	.LBB2:
	0017 837DEC00 		cmpl	$0, -20(%rbp)
	001b 750A     		jne	.L3
	001d 48C745F8 		movq	$.LC0, -8(%rbp)
	     00000000
	0025 EB08     		jmp	.L4
	.L3:
	0027 48C745F8 		movq	$.LC1, -8(%rbp)
	     00000000
	.L4:
	002f 488B45F8 		movq	-8(%rbp), %rax
	0033 4889C7   		movq	%rax, %rdi
	0036 E8000000 		call	puts
	     00
	.LBE2:
	003b 8345F401 		addl	$1, -12(%rbp)
	.L2:
	003f 8B45F4   		movl	-12(%rbp), %eax
	0042 3B45E8   		cmpl	-24(%rbp), %eax
	0045 72D0     		jb	.L5
	0047 C9       		leave
		.cfi_def_cfa 7, 8
	0048 C3       		ret
		.cfi_endproc
	.LFE0:
	.Letext0: