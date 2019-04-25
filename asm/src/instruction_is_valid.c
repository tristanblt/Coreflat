/*
** EPITECH PROJECT, 2019
** is valid instruction
** File description:
** checks if the line is a valid instruction
*/

#include "asm.h"
#include "my.h"

bool char_is_in_string(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (true);
    return (false);
}

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

bool arguments_are_valid(args_type_t *types, char **line)
{
    for (int i = 0; line[i]; i++)
        if (!argument_is_valid(line[i], types[i]))
            return (false);
    return (true);
}

char instruction_get_code(char **line)
{
    bool label = is_a_label(line[0]);
    int i = 0;

    if (label && !line[1])
        return (0);
    while (op_tab[i].mnemonique) {
        if (my_strcmp(op_tab[i].mnemonique, line[label]))
            break;
        i++;
    }
    if (!op_tab[i].mnemonique ||
        !arguments_are_valid(op_tab[i].type, line + 1 + label))
        return (-1);
    return (op_tab[i].code);
}
