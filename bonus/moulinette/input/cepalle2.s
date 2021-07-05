.name "fsfad"
.comment "Ha."

    sti  r1, %:l1, %1
l1: live %1
    fork %:l1
    ld %57672193, r2
    st r2, 56
