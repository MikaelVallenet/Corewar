.name           "42"
#.name           "422"
#.comment        "Just a basic Winner Program"
.comment        "2Just a basic Winner Program"
#%1

test2:   #la


test2: #ici

test3:#coucou

test4:#%45
entree:	nb_live	%42#, %3		# entree
	ld	%0,r5#
	ld	%0,r5
	zjmp %:bite

tir:	sti	r1,%:tirb,%1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11

	ld	%4,r3
tirf:	nb_live	%42 # :test
	fork	%:tirop#999
	nb_live	%742
	sub	r3,r5,r3#,#%4
	zjmp	%:top
	ld	%0,r11
	fork	%:tirvd
	nb_live	%42
	sti	r10,%-0 ,%0
	sti	r10,%-404,%0
	sti	r10,%-303,%0
	sti	r10,%-202,%0
	ld	%0,r11
	zjmp	%:tirf

tirop:	ld	%368,r2
	ld	%0,r3
	ld	%4,r4

tirb:	nb_live	%1
	sti	r10,%-510,r2
	sti	r10,%-510,r3
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2,r4,r2
	zjmp	%:tirop
	ld	%0,r11
	zjmp	%:tirb
	zjmp	%:infi

p32deb:	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

p32:	sub	r6,r4,r6
	add	r6,r6,r11
	ldi	%:p32deb,r6,r7
	sti	r7,%-510,r11
p32li:	nb_live	%1
	ld	%0,r10
	sti	r7,%-250,r6
	zjmp	%-192

tirvd:	zjmp	%:tirvd2

bite:	sti     r1,%:copie,%2
        ldi     %:copie,%3,r2   # met le ld a l'entree
        sti     r2,%:entree,%-4
        ldi     %:copie,%-1,r2
        sti     r2,%:entree,%-8

	sti	r1,%:p32li,%1
	sti	r1,%:b0,%1

	ld	%0,r2
	ld	%8,r3		# prepare les fork
	ld	%1,r4
	ld	%0,r6

b0:	nb_live	%1		# boucle fork
	sub	r3,r4,r3
	zjmp	%:tart
	fork	%:b1
	st	r5,r2
	xor	r10,r10,r10	# pour rien
	add	r10,r10,r10	# pour rien
	add	r6,r6,r6
	ld	%0,r10
	zjmp	%:b0
b1:	add	r2,r4,r2
	add	r6,r6,r6
	add	r6,r4,r6
	ld	%0,r10
	zjmp	%:b0


top:	nb_live	%42
	ld	%9,r3
	sti	r3,%:p32deb,%-6
	ld	%2,r3
	sti	r3,%:p32deb,%-16
	ld	%0,r3
	zjmp	%:topd


infi:	sti	r1,%:l0,%1
	sti	r1,%:l1,%1
	sti	r1,%:l2,%1
	sti	r1,%:l3,%1
	sti	r1,%:l4,%1
	sti	r1,%:l5,%1
	sti	r1,%:l6,%1
	sti	r1,%:l7,%1
	sti	r1,%:l8,%1
	sti	r1,%:l9,%1
	sti	r1,%:l10,%1

l0:	nb_live	%1
l1:	nb_live	%1
l2:	nb_live	%1
l3:	nb_live	%1
l4:	nb_live	%1
l5:	nb_live	%1
l6:	nb_live	%1
l7:	nb_live	%1
l8:	nb_live	%1
l9:	nb_live	%1
l10:	nb_live	%1
	zjmp	%:l0


p1:	zjmp	%:infi

        nb_live    %0              # pour boucher l'entree
copie:  ld      %1,r1


tart:	sti	r1,%:p64li,%1
	or	r2,r2,r2	# selection vers les modules
	zjmp	%:p64
	sub	r2,r4,r2
	zjmp	%:p32
	ld	%0,r2
	zjmp	%:infi


tirvd2:	zjmp	%:tirdow

topd:	ld	%9,r3
	sti	r3,%:fin,%-6
	ld	%2,r3
	sti	r3,%:fin,%-16
	ld	%0,r3
	zjmp	%:infi

p64deb:	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

p64:	ld	%10,r8
	sub	r6,r8,r6
	and	r6,%2147483648,r8
	zjmp	%:cont
	ld	%118,r8
	add	r6,r8,r6
cont:	add	r6,r6,r6
	ld	%272,r8
	ld	%29,r9
	ldi	%:p64deb,r6,r7
	sti	r7,r8,r6
	sti	r7,r9,r6
p64li:	nb_live	%1
	ld	%0,r10
	zjmp	%186

tirdow:	ld	%425,r2
	ld	%0,r3
	ld	%4,r4

tird:	nb_live	%42
	sti	r10,%:fin,r2
	sti	r10,%:fin,r3
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2,r4,r2
	zjmp	%:tirdow
	ld	%0,r11
	zjmp	%:tird
	zjmp	%:p1

fin:	nb_live	%633

fin1:
#p64li:
