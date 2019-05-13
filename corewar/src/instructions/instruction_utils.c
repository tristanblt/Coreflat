/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instruction_utils
*/

#include "corewar.h"
#include "my.h"

int get_value_from_instrution(proc_t *proc, int arg)
{
    if (proc->instruction->description[arg] == T_REG)
        return (proc->registers[proc->instruction->args[arg]]);
    return (proc->instruction->args[arg]);
}

void store_at_index_two(list_t *pc, int value, int index)
{
    list_t *mem;

    if (index > 0)
        mem = go_n_next(mem, index);
    else
        mem = go_n_prev(mem, -index);
    for (int i = 0; i < 2; i++) {
        mem->val = value & 0xFF00;
        value <<= 8;
        mem = mem->next;
    }
}

void store_at_index_two(list_t *pc, int value, int index)
{
    list_t *mem;

    if (index > 0)
        mem = go_n_next(mem, index);
    else
        mem = go_n_prev(mem, -index);
    for (int i = 0; i < 4; i++) {
        mem->val = value & 0xFF000000;
        value <<= 8;
        mem = mem->next;
    }
}