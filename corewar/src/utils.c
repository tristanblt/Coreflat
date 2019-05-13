/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "corewar.h"

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
