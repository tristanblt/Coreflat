/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** processes_manager
*/

#include "my.h"
#include "corewar.h"

proc_t **init_processes(champion_t **champions, list_t *memory)
{
    proc_t **procs = NULL;
    int n_champs;

    for (n_champs = 0; champions[n_champs]; n_champs++);
    procs = malloc(sizeof(proc_t *) * (n_champs + 2));
    if (procs == NULL)
        return (NULL);
    for (int i = 0; i < n_champs; i++) {
        procs[i] = malloc(sizeof(proc_t));
        if (procs[i] == NULL)
            return (NULL);
        procs[i]->pc = go_n_next(memory, champions[i]->start_offset);
        procs[i]->instruction = malloc(sizeof(instruction_t));
        if (!procs[i]->instruction)
            return (NULL);
        *procs[i]->instruction = (instruction_t){0};
        procs[i]->instruction->args = malloc(sizeof(int) * 4);
        if (!procs[i]->instruction->args)
            return (NULL);
    }
    return (procs);
}
