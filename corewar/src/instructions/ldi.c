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
    int query = get_value_from_instrution(procs[0][i], 0);
    int add = get_value_from_instrution(procs[0][i], 1);
    int temp = 0;
    int sum = 0;
    int reg = get_value_from_instrution(procs[0][i], 2);

    if (!registers_are_valid((*procs)[i]->instruction))
        return (true);
    if ((*procs)[i]->instruction->description[0] == 3) {
        query = (query - (*procs)[i]->instruction->size) % IDX_MOD;
        if (query > 0)
            temp = get_nb_from_mem(procs[0][i]->pc, IND_SIZE, query);
        else
            temp = get_nb_from_mem(procs[0][i]->pc, IND_SIZE, -query);
    }
    sum = add + temp;
    if (query > 0)
        procs[0][i]->registers[reg] = get_nb_from_mem(procs[0][i]->pc, IND_SIZE, sum % IDX_MOD);
    else
        procs[0][i]->registers[reg] = get_nb_from_mem(procs[0][i]->pc, IND_SIZE, -sum % IDX_MOD);
    return (true);
}
