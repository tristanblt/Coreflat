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

int instruction_is_valid(char **line)
{
    bool label = is_a_label(line[0]);
    int id = 0;

    if (label && !line[1])
        return (0);
    if ((id = get_instruction_id(line[0])) < 1)
        return (-1);
    //checker si les arguments sont bons (nombres et types)
    return (id);
}
