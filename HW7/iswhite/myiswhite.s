/* my_isdigit.s */

	        .text
	        .syntax unified
	        .thumb
	        .global myiswhite
		.type myiswhite, %function

myiswhite:
	        movs    r1, r0          @ copy arg
	        movs    r0, #0          @ 'true'
	        cmp     r1, #32        @ is the character below '0' in ASCII?
	        it      eq
	        moveq   r0, #1          @ yes, it's not a digit
		cmp     r1, #13        @ is the character below '0' in ASCII?
	        it      eq
	        moveq   r0, #1          @ yes, it's not a digit
		cmp     r1, #12        @ is the character below '0' in ASCII?
	        it      eq
	        moveq   r0, #1          @ yes, it's not a digit
		cmp     r1, #11        @ is the character below '0' in ASCII?
	        it      eq
	        moveq   r0, #1          @ yes, it's not a digit
		cmp     r1, #10        @ no, see if it's above '9' is ASCII
	        it      eq
	        moveq   r0, #1 			@ yes, it's not a digit
		cmp	r1, #9
		it	eq
	        moveq   r0, #1          @ yes, it's not a digit

	        bx      lr              @ return to caller