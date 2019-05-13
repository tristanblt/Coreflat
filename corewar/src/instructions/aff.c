/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool aff(proc_t ***procs, int i)
{
    int reg = procs[0][i]->instruction->args[0] - 1;

    if (reg < 0 && reg >= REG_NUMBER)
        return (true);
    my_printf("%c", procs[0][i]->registers[reg] % 256);
    return (true);
}