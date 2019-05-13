/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instruction_utils
*/

#include "corewar.h"
#include "my.h"

int get_value_from_instrution(proc_t *proc, int arg)
{
    if (proc->instruction->description[arg] == T_REG)
        return (proc->champion->registers[proc->instruction->args[arg]]);
    return (proc->instruction->args[arg]);
}