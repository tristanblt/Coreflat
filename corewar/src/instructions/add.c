/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool add(proc_t ***procs, int i)
{
    int add = 0;

    add = procs[0][i]->registers[procs[0][i]->instruction->args[0] - 1] +
    procs[0][i]->registers[procs[0][i]->instruction->args[1] - 1];
    procs[0][i]->registers[procs[0][i]->instruction->args[2] - 1] = add;
    if (add == 0)
        procs[0][i]->carry = 1;
    else
        procs[0][i]->carry = 0;
    return (true);
}
