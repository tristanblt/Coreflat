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

    store_at_index_int(procs[0][i]->pc, value, (first + second - (*procs)[i]->instruction->size) % IDX_MOD);
    return (true);
}
