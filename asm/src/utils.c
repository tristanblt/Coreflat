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

int get_arg_number(int code)
{
    for (int i = 0; op_tab[i].code; i++)
        if (op_tab[i].code == code)
            return (op_tab[i].nbr_args);
    return (0);
}

bool uses_indexes_asm(int code)
{
    if (code == IC_ldi || code == IC_lldi || code == IC_fork ||
        code == IC_lfork || code == IC_zjmp || code == IC_sti)
        return (true);
    return (false);
}
