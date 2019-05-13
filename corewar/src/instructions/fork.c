/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

proc_t *create_new_proc(proc_t *proc)
{
    proc_t *new_proc = malloc(sizeof(proc_t));

    if (!new_proc)
        return (NULL);
    *new_proc = (proc_t){0};
    new_proc->champion = proc->champion;
    new_proc->carry = proc->carry;
    new_proc->is_active = true;
    new_proc->instruction = malloc(sizeof(instruction_t));
    *new_proc->instruction = (instruction_t){0};
    new_proc->registers = malloc(sizeof(register_t) * REG_NUMBER);
    if (!new_proc->registers || !new_proc->instruction)
        return (false);
    for (int i = 0; i < REG_NUMBER; i++)
        new_proc->registers[i] = proc->registers[i];
    return (new_proc);
}

bool fork_vm(proc_t ***procs, int i)
{
    proc_t *to_add = create_new_proc((*procs)[i]);

    if (!to_add)
        return (false);
    if ((*procs)[i]->instruction->args[0] > 0)
        go_n_next(to_add->pc, (*procs)[i]->instruction->args[0] % IDX_MOD);
    else
        go_n_prev(to_add->pc, -(*procs)[i]->instruction->args[0] % IDX_MOD);
    if (!(*procs = push_proc(*procs, to_add)))
        return (false);
    return (true);
}
