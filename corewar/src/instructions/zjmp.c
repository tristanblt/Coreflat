/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool zjmp(proc_t ***procs, int i)
{
    int index = procs[0][i]->instruction->args[0] % IDX_MOD - 1 - IND_SIZE;

    if (procs[0][i]->carry != 1)
        return (true);
    if (index > 0)
        procs[0][i]->pc = go_n_next(procs[0][i]->pc, index);
    else if (index < 0)
        procs[0][i]->pc = go_n_prev(procs[0][i]->pc, -index);
    return (true);
}
