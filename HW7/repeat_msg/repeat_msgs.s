        
repeat_msg:
	.LFB11:
	        .cfi_startproc
	        movq    %rbx, -40(%rsp)
	        movq    %r12, -24(%rsp)
	        movl    %edi, %ebx
	        .cfi_offset 12, -32
	        .cfi_offset 3, -48
	        movq    %rbp, -32(%rsp)
	        movq    %r13, -16(%rsp)
	        movl    %esi, %r12d
	        movq    %r14, -8(%rsp)
	        subq    $40, %rsp
	        .cfi_def_cfa_offset 48
	        .cfi_offset 14, -16
	        .cfi_offset 13, -24
	        .cfi_offset 6, -40
	        testl   %esi, %esi
	        je      .L6
	        xorl    %ebp, %ebp
	        movl    $.LC1, %r14d
	        movl    $.LC0, %r13d
	        .p2align 4,,10
	        .p2align 3
	.L5:
	        testl   %ebx, %ebx
	        movq    %r13, %rdi
	        cmove   %r14, %rdi
	        addl    $1, %ebp
	        call    puts
	        cmpl    %r12d, %ebp
	        jb      .L5
	.L6:
	        movq    (%rsp), %rbx
	        movq    8(%rsp), %rbp
	        movq    16(%rsp), %r12
	        movq    24(%rsp), %r13
	        movq    32(%rsp), %r14
	        addq    $40, %rsp
	        .cfi_def_cfa_offset 8
	        ret
	        .cfi_endproc
	.LFE11:
	        .size   repeat_msg, .-repeat_msg
	        .ident  "GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	        .section        .note.GNU-stack,"",@progbits
	