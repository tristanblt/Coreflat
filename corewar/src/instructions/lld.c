/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool lld(proc_t ***procs, int i)
{
    int arg = get_value_from_instrution(procs[0][i], 0);
    int res = get_nb_from_mem(procs[0][i]->pc, 4, arg);

    procs[0][i]->registers[get_value_from_instrution(procs[0][i], 1)] = res;
    return (true);
}