/*
** EPITECH PROJECT, 2019
** checks multiple label definitions
** File description:
** checks if a label is defined multiple times
*/

#include "asm.h"
#include "my.h"

int count_label_definitions(instruction_t **instructions, char *label)
{
    int count = 0;

    if (!label)
        return (1);
    for (int i = 0; instructions[i]; i++)
        if (instructions[i]->label && my_strcmp(instructions[i]->label, label))
            count++;
    if (count != 1)
        my_dprintf(2, "Multiple definitions of label: %s\n", label);
    return (count);
}

bool check_multiple_label_definitions(instruction_t **instructions)
{
    for (int i = 0; instructions[i]; i++)
        if (count_label_definitions(instructions, instructions[i]->label)!=1)
            return (true);
    return (false);
}
