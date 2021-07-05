	.name "Bill"
	.comment "Equilibre"

	sti r1, %:live, %1
	fork %:ok
	ld %100, r4
	ld %2, r5

live:	live %1

ok:
	sti r5, r4, r1
	add r4, r5, r4
	ld %0, r8
	zjmp %:live
