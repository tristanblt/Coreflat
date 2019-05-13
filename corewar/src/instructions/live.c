/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

bool live(proc_t ***procs, int i)
{
    my_printf("The player %i(%s) is alive.",
    procs[0][i]->champion->registers[0],
    procs[0][i]->champion->header->prog_name);
    procs[0][i]->champion->last_live = 0;
    return (true);
}