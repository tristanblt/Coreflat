/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool st(proc_t ***procs, int i)
{
    int value = get_value_from_instrution(procs[0][i], 0);
    int offset = 0;

    if (procs[0][i]->instruction->description[1] == 1)
        procs[0][i]->registers[procs[0][i]->instruction->args[1] - 1] = value;
    else if (procs[0][i]->instruction->description[1] == 3) {
        offset = (*procs)[i]->instruction->args[1] % IDX_MOD - (*procs)[i]->instruction->size;
        store_at_index_int(procs[0][i]->pc, value, (offset));
    }
    return (true);
}
