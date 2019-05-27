/*
** EPITECH PROJECT, 2019
** is valid instruction
** File description:
** checks if the line is a valid instruction
*/

#include "asm.h"
#include "my.h"

bool is_a_label(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i && str[i] == LABEL_CHAR && !str[i + 1])
            return (true);
        if (!char_is_in_string(str[i], LABEL_CHARS))
            return (false);
    }
    return (false);
}

bool arguments_are_valid(args_type_t *types, char **line, int nb)
{
    int arguments = 0;
    int expected = 0;

    while (line[arguments])
        arguments++;
    while (expected < 4 && types[expected])
        expected++;
    if (arguments != expected) {
        my_dprintf(2, "Line %d: Expected %d argument(s)\n", nb+1, expected);
        return (false);
    }
    for (int i = 0; line[i]; i++)
        if (!argument_is_valid(line[i], types[i])) {
            my_dprintf(2, "Line %d: Argument %d: Wrong argument type\n",
            nb+1, i+1);
            return (false);
        }
    return (true);
}

char *get_instruction_label(char *instruction)
{
    char *label = my_strdup(instruction);

    if (!label)
        return (NULL);
    label[my_strlen(label) - 1] = 0;
    return (label);
}

char *get_label_asm(char *arg)
{
    if (arg[0] == DIRECT_CHAR)
        arg++;
    if (arg[0] == LABEL_CHAR)
        arg++;
    return (my_strdup(arg));
}

char instruction_get_code(char **line, char **label_name, char **labels, int nb)
{
    bool label = is_a_label(line[0]);
    int i = 0;

    if (label && !(*label_name = get_instruction_label(line[0])))
        return (-1);
    if (label && !line[1])
        return (0);
    for (;op_tab[i].mnemonique; i++)
        if (my_strcmp(op_tab[i].mnemonique, line[label]))
            break;
    if (!op_tab[i].mnemonique)
        return (-1+my_dprintf(2, "Line %d: Unknown instruction: %s\n",  \
nb+1, labels[label]+1)%1);
    if (!arguments_are_valid(op_tab[i].type, line + 1 + label, nb))
        return (-1);
    for (int j = label + 1, arg = 0; line[j]; j++, arg++)
        if (argument_is_label(line[j], 0)&&
            !(labels[arg]=get_label_asm(line[j])))
            return (-1);
    return (op_tab[i].code);
}
