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

    if (!to_add)
        return (false);
    if ((*procs)[i]->instruction->args[0] > 0)
        go_n_next(to_add->pc, (*procs)[i]->instruction->args[0]);
    else
        go_n_prev(to_add->pc, -(*procs)[i]->instruction->args[0]);
    if (!(*procs = push_proc(*procs, to_add)))
        return (false);
    return (true);
}
