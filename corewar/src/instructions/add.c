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

    for (int j = 0; j < 3; j++)
        if (procs[0][i]->champion->registers[procs[0][i]->instruction->args[i]] < 0 &&
        procs[0][i]->champion->registers[procs[0][i]->instruction->args[i]] >= REG_NUMBER)
            return (true);
    add = procs[0][i]->champion->registers[procs[0][i]->instruction->args[0]] +
    procs[0][i]->champion->registers[procs[0][i]->instruction->args[1]];
    procs[0][i]->champion->registers[procs[0][i]->instruction->args[2]] = add;
    if (add == 0)
        procs[0][i]->carry = 1;
    else
        procs[0][i]->carry = 0;
    return (true);
}