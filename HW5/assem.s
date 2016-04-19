//Blake Corley bacorley         worked with absilver

	.text
	.syntax unified
	.thumb
	.global	ADD
	.global	AND
	.global	ASR
	.global	BIC
	.global	CLZ
	.global	EOR
	.global	LSL
	.global	LSR
	.global	MVN
	.global	ORN
	.global	ORR
	.global	RBIT
	.global	REV
	.global	REV16
	.global	ROR
	.global	RSB
	.global	SUB
	.type	ADD, %function
	.type	AND, %function
	.type	ASR, %function
	.type	BIC, %function
	.type	CLZ, %function
	.type	EOR, %function
	.type	LSL, %function
	.type	LSR, %function
	.type	MVN, %function
	.type	ORN, %function
	.type	ORR, %function
	.type	RBIT, %function
	.type	REV, %function
	.type	REV16, %function
	.type	ROR, %function
	.type	RSB, %function
	.type	SUB, %function

	
ADD:	
	add r0, r1 
	bx lr 

AND:
	and r0, r1, #0xFF00
	bx lr

ASR:
	add r0, r1, #9  
	bx lr

BIC:
	bic r0, r1, #0xab00
	bx lr
	
CLZ:
	clz r0, r1
	bx lr

EOR:
	eor r0, r1, #0x1818
	bx lr

LSL:
	lsl r0 r1, #3 
	bx lr

LSR:
	lsr r0, r1, #3
	bx lr

MVN:
	mvn r0, r1, #3
	bx lr

ORN:
	orn r0, r1, r1
	bx lr

ORR:
	orr r0, r1, r1
	bx lr

RBIT:
	rbit r0, r1
	bx lr

REV:
	rev r0, r1
	bx lr

REV16:
	rev16 r0, r1
	bx lr

ROR:
	ror r0, r1, r1
	bx lr

RSB:
	rsb r0, r1, #1280
	bx lr

SUB:
	sub r0, r1, #2400
	bx lr
	
