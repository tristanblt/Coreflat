#!/bin/bash
if [ ! -f ../Makefile ]; then
    echo "We need the Makefile!"
    exit 84;
fi
echo "make asm"
rm -f ../asm
rm -rf result
make fclean -C ../ && make re -C ../ && make clean -C ../
if [ -f ../asm ]; then
    echo "asm found"
else
    echo "[asm not found]"
    exit 84;
fi
echo "Start test"
mkdir result
echo -e "-----Trace ASM ------\n" >> result/Trace
for entry in files/*
do
    name="${entry##/}"
    echo "[TEST] $name" >> result/Trace
    ./asm/asm $name
    hexdump -C `echo -ne "${entry##*/}" | sed -e "s/\.s/\.cor/g"` >> asm/ref
    rm -f `echo -ne "${entry##*/}" | sed -e "s/\.s/\.cor/g"`
    ../asm $name
    hexdump -C `echo -ne $name | sed -e "s/\.s/\.cor/g"` >> our
    diff -s our asm/ref >> diff
    if [ $? -eq 0 ]; then
        echo -e "SUCCESS\n\n" >> result/Trace
    else
        echo "FAIL, Expected : \n\n" >> result/Trace
        cat asm/ref >> result/Trace
        echo -e "Got : \n\n" >> result/Trace
        cat our >> result/Trace
        echo -e "\n\nDifference:\n\n" >> result/Trace
        cat diff >> result/Trace
    fi
    rm -f diff
    rm -f our
    rm -f `echo -ne $name | sed -e "s/\.s/\.cor/g"`
    rm -f asm/ref
done
echo "Done all tests, see result in result/Trace"
echo -e "All tests done" >> result/Trace