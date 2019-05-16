/*
** EPITECH PROJECT, 2019
** compute instruction size
** File description:
** completes instruction struct and returns prog size
*/

#include "asm.h"

int get_program_size(instruction_t **inst)
{
    int j = 0;
    int size = 0;
    int reversed_size = 0;

    for (; inst[j]; j++);
    if (!j)
        return (0);
    j--;
    size = inst[j]->cumulative_size + inst[j]->size;
    for (int i = 0; i < 4; i++) {
        reversed_size <<= 8;
        reversed_size |= size & 255;
        size >>= 8;
    }
    return (reversed_size);
}

int compute_instruction_size(instruction_t **instructions)
{
    for (int i = 0; instructions[i]; i++) {
        instructions[i]->size = get_instruction_size(instructions[i]);
        instructions[i]->cumulative_size = 0;
        if (i)
            instructions[i]->cumulative_size +=\
instructions[i-1]->cumulative_size + instructions[i-1]->size;
    }
    return (get_program_size(instructions));
}
