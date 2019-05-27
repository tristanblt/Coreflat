/*
** EPITECH PROJECT, 2019
** instruction
** File description:
** size
*/

#include "asm.h"
#include "my.h"

int get_arg_size_asm(instruction_t *inst, int arg)
{
    if (has_one_argument_asm(inst->code)) {
        if (uses_indexes_asm(inst->code))
            return (1 + IND_SIZE);
        return (1 + REG_SIZE);
    }
    if (inst->description[arg] == T_REG)
        return (1);
    if (inst->description[arg] == T_DIR) {
        if (uses_indexes_asm(inst->code))
            return (IND_SIZE);
        return (REG_SIZE);
    }
    if (inst->description[arg] == T_IND)
        return (IND_SIZE);
    return (0);
}

int get_instruction_size(instruction_t *instruction)
{
    int size = 2;

    if (has_one_argument_asm(instruction->code))
        return (get_arg_size_asm(instruction, 0));
    if (!instruction->description)
        return (0);
    for (int i = 0; instruction->description[i] != -1; i++)
        size += get_arg_size_asm(instruction, i);
    return (size);
}
