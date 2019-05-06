/*
** EPITECH PROJECT, 2019
** instruction
** File description:
** size
*/

#include "asm.h"
#include "my.h"

int get_instruction_size(instruction_t *instruction)
{
    int size = 2;

    if (has_one_argument(instruction->code))
        return (1 + DIR_SIZE);
    if (!instruction->description)
        return (0);
    for (int i = 0; instruction->description[i] != -1; i++) {
        if (instruction->description[i] == T_REG)
            size += 1;
        if (instruction->description[i] == T_DIR)
            size += DIR_SIZE;
        if (instruction->description[i] == T_IND)
            size += IND_SIZE;
    }
    return (size);
}
