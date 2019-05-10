/*
** EPITECH PROJECT, 2019
** instruction
** File description:
** size
*/

#include "asm.h"
#include "my.h"

int get_arg_size(instruction_t *inst, int arg)
{
    if (has_one_argument(inst->code)) {
        if (uses_indexes(inst->code))
            return (3);
        return (5);
    }
    if (inst->description[arg] == T_REG)
        return (1);
    if (inst->description[arg] == T_DIR) {
        if (uses_indexes(inst->code))
            return (2);
        return (4);
    }
    if (inst->description[arg] == T_IND)
        return (2);
    return (0);
}

int get_instruction_size(instruction_t *instruction)
{
    int size = 2;

    if (has_one_argument(instruction->code))
        return (get_arg_size(instruction, 0));
    if (!instruction->description)
        return (0);
    for (int i = 0; instruction->description[i] != -1; i++)
        size += get_arg_size(instruction, i);
    return (size);
}
