/*
** EPITECH PROJECT, 2019
** free
** File description:
** free utils
*/

#include <stdlib.h>
#include "corewar.h"

void destroy_instruction(instruction_t *instruction)
{
    if (!instruction)
        return;
    if (instruction->args)
        free(instruction->args);
    if (instruction->description)
        free(instruction->description);
    free(instruction);
}

void destroy_champions(champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->instructions)
            free(champions[i]->instructions);
        if (champions[i]->header)
            free(champions[i]->header);
        free(champions[i]);
    }
    free(champions);
}

void destroy_processes(proc_t **procs)
{
    for (int i = 0; procs[i]; i++) {
        destroy_instruction(procs[i]->instruction);
        if (procs[i]->registers)
            free(procs[i]->registers);
        free(procs[i]);
    }
    free(procs);
}
