/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool ld(proc_t ***procs, int i)
{
    int to_store = get_value_from_instrution(procs[0][i], 0);
    int reg = procs[0][i]->instruction->args[1] - 1;

    if ((*procs)[i]->instruction->description[0] == 3) {
        to_store = to_store % IDX_MOD - (*procs)[i]->instruction->size;
        to_store = get_nb_from_mem(procs[0][i]->pc, REG_SIZE, to_store);
    }
    procs[0][i]->registers[reg] = to_store;
    if (!to_store) {
        (*procs)[i]->carry = 1;
    } else
        (*procs)[i]->carry = 0;
    return (true);
}
