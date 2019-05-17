/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "disasm.h"
#include <stddef.h>

int get_arg_size(char arg, int code)
{
    if (arg == 1)
        return (1);
    else if (arg == 2 && !uses_indexes(code))
        return (DIR_SIZE);
    return (IND_SIZE);
}

char *get_inst_name(int code)
{
    for (int i = 0; op_tab[i].code; i++)
        if (code == op_tab[i].code)
            return (op_tab[i].mnemonique);
    return (NULL);
}

bool uses_indexes(int code)
{
    if (code == IC_ldi || code == IC_lldi || code == IC_fork ||
        code == IC_lfork || code == IC_zjmp || code == IC_sti)
        return (true);
    return (false);
}

bool is_instruction_code_valid(char code)
{
    for (int i = 0; op_tab[i].code; i++)
        if (op_tab[i].code == code)
            return (true);
    return (false);
}

bool has_one_argument(int code)
{
    if (code == IC_live || code == IC_zjmp || code == IC_fork ||
        code == IC_lfork)
        return (true);
    return (false);
}
