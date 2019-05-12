/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** processes_manager
*/

#include "my.h"
#include "corewar.h"

proc_t **init_processes(champion_t **champions)
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
        //procs[i]->pc = 
    }
    return (procs);
}