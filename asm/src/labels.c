/*
** EPITECH PROJECT, 2019
** labels
** File description:
** labels
*/

#include "asm.h"
#include "my.h"

void compute_instruction_size(instruction_t **instructions)
{
    for (int i = 0; instructions[i]; i++) {
        instructions[i]->size = get_instruction_size(instructions[i]);
        instructions[i]->cumulative_size = 0;
        if (i)
            instructions[i]->cumulative_size +=
                instructions[i-1]->cumulative_size + instructions[i-1]->size;
    }
}

int get_byte_difference(instruction_t **instructions, char *label,
int cum_size)
{
    int i = 0;

    for (; instructions[i]; i++)
        if (instructions[i]->label &&
            my_strcmp(instructions[i]->label, label))
            break;
    my_printf("%d %d\n", instructions[i]->cumulative_size, cum_size);
    return (instructions[i]->cumulative_size - cum_size);
}

bool label_is_defined(instruction_t **instructions, char *label)
{
    for (int i = 0; instructions[i]; i++)
        if (instructions[i]->label &&
            my_strcmp(instructions[i]->label, label))
            return (true);
    my_dprintf(2, "Undefined label: %s\n", label);
    return (false);
}

int label_get_value(instruction_t **instructions, int label)
{
    for (int i = 0; i < 4; i++)
        if (instructions[label]->label_args[i] &&
            !label_is_defined(instructions, instructions[label]->label_args[i]))
            return (-1);
        else if (instructions[label]->label_args[i])
            instructions[label]->args[i] = get_byte_difference(instructions,
instructions[label]->label_args[i], instructions[label]->cumulative_size);
    return (0);
}

int labels_get_values(instruction_t **instructions)
{
    if (check_multiple_label_definitions(instructions))
        return (-1);
    for (int i = 0; instructions[i]; i++)
        if (label_get_value(instructions, i))
            return (-1);
    return (0);
}
