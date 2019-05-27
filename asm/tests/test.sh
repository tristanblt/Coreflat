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
    error=0
    name="${entry##/}"
    echo "[TEST] $name" >> result/Trace
    ./asm/asm $name
    if [ $? -eq 0 ];then
        hexdump -C `echo -ne "${entry##*/}" | sed -e "s/\.s/\.cor/g"` >> asm/ref
    else
        let "error += 1";
    fi
    rm -f `echo -ne "${entry##*/}" | sed -e "s/\.s/\.cor/g"`
    ../asm $name
    if [ $? -eq 0 ];then
        hexdump -C `echo -ne $name | sed -e "s/\.s/\.cor/g"` >> our
        diff -s our asm/ref >> diff
        if [ $? -eq 0 ]; then
            echo -e "SUCCESS\n\n" >> result/Trace
        else
            echo -e "FAIL, Expected : \n\n" >> result/Trace
            cat asm/ref >> result/Trace
            echo -e "Got : \n\n" >> result/Trace
            cat our >> result/Trace
            echo -e "\n\nDifference:\n\n" >> result/Trace
            cat diff >> result/Trace
        fi
    else
        let "error += 1";
    fi
    if [ $error == 2 ];then
        echo -e "SUCCESS\n\n" >> result/Trace
    else if [ $error == 1 ];then
        echo -e "INVALID RETURN\n\n" >> result/Trace
    fi
    fi
    rm -f diff
    rm -f our
    rm -f `echo -ne $name | sed -e "s/\.s/\.cor/g"`
    rm -f asm/ref
done
echo "Done all tests, see result in result/Trace"
echo -e "All tests done" >> result/Trace