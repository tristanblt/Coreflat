    .name "Querelle des Noyaux"
    .comment "La Querelle des Noyaux est une evenement historique prenant place initialement dans nos coeurs"

        sti r1 %:live %1
        ld %4 r4

start:  ldi r2 %0 r3
        sti r3 r2 %:end
        add r2 r4 r2
live:   live %1
        xor r2 %42 r16
        zjmp %:start
        ld %0 r2
        fork %:start
end:
