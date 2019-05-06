/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** utils
*/

#include "asm.h"

bool line_is_empty(char *line)
{
    if (!line)
        return (true);
    for (int i = 0; line[i]; i++)
        if (line[i] != ' '&&line[i] != '\r'&&line[i] != '\n'&&line[i] != '\t')
            return (false);
    return (true);
}