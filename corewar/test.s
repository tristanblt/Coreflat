    .name "test"
    .comment ""

sti r1 %:live %1
ld %0 r2
live: live %1
fork %100
zjmp %100