/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool or(proc_t ***procs, int i)
{
    int first = get_value_from_instrution(procs[0][i], 0);
    int second = get_value_from_instrution(procs[0][i], 1);

    if ((*procs)[i]->instruction->description[0] == 3) {
        first -= (*procs)[i]->instruction->size;
        first = get_nb_from_mem((*procs)[i]->pc, IND_SIZE, first);
    }
    if ((*procs)[i]->instruction->description[1] == 3) {
        second -= (*procs)[i]->instruction->size;
        second = get_nb_from_mem((*procs)[i]->pc, IND_SIZE, first);
    }
    procs[0][i]->registers[procs[0][i]->instruction->args[2] - 1] \
= first | second;
    if ((first | second) == 0)
        procs[0][i]->carry = 1;
    else
        procs[0][i]->carry = 0;
    return (true);
}
