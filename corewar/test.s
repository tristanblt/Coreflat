    .name "test"
    .comment ""

    sti r1 %:live %1
    ld %4 r2
    ld %100 r3
    ld %123123123 r4

live:   live %123456789
    sti r4 r2 r3
    add r2 r3 r3
    ld %0 r8
    zjmp %:live
