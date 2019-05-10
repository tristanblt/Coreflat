/*
** EPITECH PROJECT, 2019
** argument type
** File description:
** checks arg types
*/

#include "asm.h"
#include "my.h"

bool argument_is_label(char *argument, int type)
{
    int start = 0;

    if (!type && argument[0] == DIRECT_CHAR)
        start++;
    if (type == T_DIR && argument[0] == DIRECT_CHAR)
        start++;
    if (argument[start] != LABEL_CHAR || !argument[start + 1])
        return (false);
    for (int i = start + 1; argument[i]; i++)
        if (!char_is_in_string(argument[i], LABEL_CHARS))
            return (false);
    return (true);
}

bool argument_is_direct(char *argument)
{
    bool neg = 0;

    if (argument_is_label(argument, T_DIR))
        return (true);
    if (argument[0] != DIRECT_CHAR || !argument[1])
        return (false);
    if (argument[1] == '-')
        neg = true;
    if (!is_num(&argument[1 + neg]))
        return (false);
    return (true);
}

bool argument_is_register(char *argument)
{
    int number;

    if (argument[0] != 'r' || !is_num(&argument[1]))
        return (false);
    number = my_get_nbr(&argument[1]);
    if (number < 1 || number > REG_NUMBER)
        return (false);
    return (true);
}

bool argument_is_indirect(char *argument)
{
    bool neg = argument[0] == '-';

    if (argument_is_label(argument, T_IND))
        return (true);
    if (is_num(argument + neg))
        return (true);
    return (false);
}

bool argument_is_valid(char *argument, char type)
{
    if (type & T_REG && argument_is_register(argument))
        return (true);
    if (type & T_DIR && argument_is_direct(argument))
        return (true);
    if (type & T_IND && argument_is_indirect(argument))
        return (true);
    return (false);
}
