.name    "pdd"
.comment "pdd"

	sti	r1, %:live, %1
	fork	%:live
begin:	ld	%76, r1
	ld	%40, r6
	ld	%1, r7
	ld	%15, r4
	ld	%15, r5
	sub	r4, r5, r3
	zjmp	%:attack
live:	live	%2
	ld	%0, r4
	zjmp	%:live
attack:	ld	%65, r8
	st	r8, 100
	aff	r1
	add	r6, r7, r7
	sti	r7, r7, r1
	ld	%15, r4
	ld	%15, r5
	sub	r4, r5, r3
	zjmp	%:attack
