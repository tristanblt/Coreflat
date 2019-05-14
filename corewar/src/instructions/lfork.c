/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool lfork(proc_t ***procs, int i)
{
    proc_t *to_add = create_new_proc((*procs)[i]);
    int offset = ((*procs)[i]->instruction->args[0] - 1 - IND_SIZE);

    if (!to_add)
        return (false);
    if ((*procs)[i]->instruction->args[0] > 0)
        go_n_next(to_add->pc, offset);
    else
        go_n_prev(to_add->pc, -offset);
    if (!(*procs = push_proc(*procs, to_add)))
        return (false);
    return (true);
}
