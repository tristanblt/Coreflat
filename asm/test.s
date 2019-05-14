	.name "Bill"
        .comment "Equilibre"

        sti r1 %:live %1

live:   live %123456789

fork:   fork %:live
        add r1 r2 r2
        sti r1 %100 r2
        zjmp %:live
