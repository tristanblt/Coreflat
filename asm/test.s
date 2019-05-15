	.name "Bill"
        .comment "Equilibre"

    sti r1 %:live %1
    ld %1 r2
    ld %100 r3

live:   live %123456789

        add r2 r3 r3
        sti r1 r2 r3
        zjmp %:live
