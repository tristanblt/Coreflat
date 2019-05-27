#!/bin/bash
if [ ! -f ../Makefile ]; then
    echo "We need the Makefile!"
    exit 84;
fi
echo "make corewar"
rm -f ../asm
rm -rf result
make fclean -C ../ && make re -C ../ && make clean -C ../
if [ -f ../corewar ]; then
    echo "corewar found"
else
    echo "[corewar not found]"
    exit 84;
fi
echo "Start test"
mkdir result
echo -e "-----Trace COREWAR ------\n" >> result/Trace
for entry in files/*
do
    name="${entry##/}"
    for entry2 in files2/*
    do
    name2="${entry2##/}"
    echo "[TEST] ${entry##*/} vs ${entry2##*/}" >> result/Trace
    ./corewar/corewar $name $name2 >> corewar/ref
    sed -i -e "s/Le joueur/The player/g" corewar/ref
    sed -i -e "s/ (/(/g" corewar/ref
    sed -i -e "s/est en vie/is alive/g" corewar/ref
    sed -i -e "s/a gagné/has won/g" corewar/ref
    ../corewar $name $name2 >> our
    if [ $? -eq 0 ];then
        diff -s our corewar/ref >> diff
        if [ $? -eq 0 ]; then
            echo -e "SUCCESS\n\n" >> result/Trace
        else
            echo -e "FAIL, Expected : \n\n" >> result/Trace
            cat corewar/ref >> result/Trace
            echo -e "Got : \n\n" >> result/Trace
            cat our >> result/Trace
            echo -e "\n\nDifference:\n\n" >> result/Trace
            cat diff >> result/Trace
        fi
        rm -f diff
    fi
    rm -f our
    rm -f corewar/ref
    done
done
echo "Done all tests, see result in result/Trace"
echo -e "All tests done" >> result/Trace