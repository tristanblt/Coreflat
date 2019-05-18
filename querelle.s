    .name "Querelle des noyaux"
    .comment "meilleure querelle de l'histoire"


    st r1 :buffer
    st r6 -4
    ld :buffer r1
    sti r1 %:loop_back %1
    sti r1 %:loop_front %1
    ld %4 r4
    ld %48 r5
    ld %0 r7
    fork %:loop_back
    fork %:loop_front
    zjmp %:start

buffer: st r1 r1

loop_back: live %123123123
    ldi %-5 r3 r1
    sti r1 %-173 r3
    add r3 r4 r3
    xor r5 r3 r6
    zjmp %:end_loop_back
    ld %0 r7
    zjmp %:loop_back
end_loop_back:   xor r3 r3 r3
    zjmp %-207

start:  sti r1 %:live_0 %1
    sti r1 %:live_1 %1
    sti r1 %:live_2 %1
    sti r1 %:live_3 %1
    sti r1 %:live_4 %1
    sti r1 %:live_5 %1
    sti r1 %:live_6 %1

fork_loop:  fork %:loop_back
    fork %:loop_front
    fork %:fork_loop

live_0: live %666
live_1: live %666
live_2: live %666
live_3: live %666
live_4: live %666
live_5: live %666
live_6: live %666
    zjmp %:live_0


loop_front: live %123123123
    ldi %-5 r3 r1
    sti r1 %48 r3
    add r3 r4 r3
    xor r5 r3 r6
    zjmp %:end_loop_front
    ld %0 r7
    zjmp %:loop_front
end_loop_front: xor r3 r3 r3
    zjmp %5
