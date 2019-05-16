/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool ldi(proc_t ***procs, int i)
{
    int index_1 = get_value_from_instrution((*procs)[i], 0);
    int index_2 = get_value_from_instrution((*procs)[i], 1);
    int sum = 0;
    int reg = (*procs)[i]->instruction->args[2] - 1;

    if (!registers_are_valid((*procs)[i]->instruction))
        return (true);
    if ((*procs)[i]->instruction->description[0] == 3) {
        index_1 = index_1 % IDX_MOD - (*procs)[i]->instruction->size;
        index_1 = get_nb_from_mem((*procs)[i]->pc, IND_SIZE, index_1);
    }
    sum = (index_1 + index_2) % IDX_MOD - (*procs)[i]->instruction->size;
    (*procs)[i]->registers[reg] = \
get_nb_from_mem((*procs)[i]->pc, REG_SIZE, sum);
    if (!(*procs)[i]->registers[reg])
        (*procs)[i]->carry = 1;
    else
        (*procs)[i]->carry = 0;
    return (true);
}
