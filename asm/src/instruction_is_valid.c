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
    int arguments = 0;
    int expected = 0;

    while (line[arguments])
        arguments++;
    while (expected < 4 && types[expected])
        expected++;
    if (arguments != expected)
        return (false);
    for (int i = 0; line[i]; i++)
        if (!argument_is_valid(line[i], types[i]))
            return (false);
    return (true);
}

char *get_label(char *instruction)
{
    char *label = my_strdup(instruction);

    if (!label)
        return (NULL);
    label[my_strlen(label) - 1] = 0;
    return (label);
}

char instruction_get_code(char **line, char **label_name)
{
    bool label = is_a_label(line[0]);
    int i = 0;

    if (label && !(*label_name = get_label(line[0])))
        return (-1);
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
