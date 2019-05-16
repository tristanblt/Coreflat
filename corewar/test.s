    .name "Querelle des Noyaux"
    .comment "La Querelle des Noyaux est une evenement historique prenant place initialement dans nos coeurs"

        sti r1 %:live %1
        ld %4 r4
        ld %64 r15

start:  ldi r2 %:start r3
        sti r3 r2 %64
        add r2 r4 r2
live:   live %1
        sub r2 r15 r16
        zjmp %:fork
        ld %0 r16
        zjmp %:start
fork:   ld %0 r2
end:
