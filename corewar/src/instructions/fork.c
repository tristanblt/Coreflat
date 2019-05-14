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
    new_proc->registers = malloc(sizeof(int) * REG_NUMBER);
    if (!new_proc->registers || !new_proc->instruction)
        return (false);
    for (int i = 0; i < REG_NUMBER; i++)
        new_proc->registers[i] = proc->registers[i];
    *new_proc->instruction = (instruction_t){0};
    new_proc->instruction->args = malloc(sizeof(int) * 4);
    if (!new_proc->instruction->args)
        return (NULL);
    new_proc->pc = proc->pc;
    return (new_proc);
}

bool fork_vm(proc_t ***procs, int i)
{
    proc_t *to_add = create_new_proc((*procs)[i]);
    int offset = ((*procs)[i]->instruction->args[0] - 1 - IND_SIZE) % IDX_MOD;

    if (!to_add)
        return (false);
    if (offset > 0)
        to_add->pc = go_n_next(to_add->pc, offset);
    else
        to_add->pc = go_n_prev(to_add->pc, -offset);
    if (!(*procs = push_proc(*procs, to_add)))
        return (false);
    return (true);
}
