                .syntax unified
	        .thumb
	        .text
		.global repeat
	        .type repeat, %function




repeat:
	        push    {lr}     @ save return address on stack
	        ldr     r2, [r0]   @  msg_id =  r2, num_repetitions = r1
		cbnz	r1, loop
		@cmp     r1, r2
	        @it      hi
	        @blhi    loop
		bl	exit


loop:
	        cmp     r1, r2
	        it      lo
		bllo	exit
		cmp     r3, #0
	        it      ne
	        bne    putone
	        b      putzero


putone:
	        adds    r2, #1
	        ldr     r0, =one
	        bl      puts
	        b      loop


putzero:
	        adds    r2, #1
	        ldr     r0, =zero
	        bl      puts
	        b      loop

exit:
	pop	{pc}
	@bx 	lr





	        .data
zero:
	        .ascii "zero"
	        .byte 0
one:
	        .ascii "one"
	        .byte 0
	