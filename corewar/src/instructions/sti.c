/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool sti(proc_t ***procs, int i)
{
    int value = get_value_from_instrution(procs[0][i], 0);
    int first = get_value_from_instrution(procs[0][i], 1);
    int second = get_value_from_instrution(procs[0][i], 2);

    if (!registers_are_valid((*procs)[i]->instruction))
        return (true);
    if ((*procs)[i]->instruction->description[1] == 3) {
        first -= (*procs)[i]->instruction->size;
        first = get_nb_from_mem((*procs)[i]->pc, IND_SIZE, first % IDX_MOD);
    }
    store_at_index_int((*procs)[i]->pc, value, (first + second - (*procs)[i]->instruction->size) % IDX_MOD);
    return (true);
}
