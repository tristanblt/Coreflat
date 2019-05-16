/*
** EPITECH PROJECT, 2019
** compute instructions sizes
** File description:
** computes the sizes of the instructions
*/

#include "disasm.h"

void compute_instructions_sizes(instruction_t **insts)
{
    for (int i = 0; insts[i]; i++) {
        insts[i]->size = 2;
        if (has_one_argument(insts[i]->code))
            insts[i]->size = 1;
        for (int j = 0; insts[i]->description[j]; j++)
            insts[i]->size += get_arg_size(insts[i]->description[j],
insts[i]->code);
        if (i)
            insts[i]->cumulative_size=insts[i-1]->cumulative_size
                +insts[i-1]->size;
    }
}
