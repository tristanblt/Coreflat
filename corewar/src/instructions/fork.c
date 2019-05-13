/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool fork_vm(proc_t ***procs, int i)
{
    proc_t *to_add = malloc(sizeof(proc_t));

    if (!to_add)
        return (false);
    *to_add = (proc_t){0};
    to_add->carry = (*procs)[i]->carry;
    to_add->champion = (*procs)[i]->champion;
    to_add->is_active = true;
    to_add->instruction = malloc(sizeof(instruction_t));

    return (true);
}
