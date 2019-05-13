/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** processes_manager
*/

#include "my.h"
#include "corewar.h"

proc_t **push_proc(proc_t **arr, proc_t *add)
{
    proc_t **new_arr = NULL;
    int nb_elem_arr;
    int copy_elems;

    for (nb_elem_arr = 0; arr[nb_elem_arr] != NULL; nb_elem_arr++);
    new_arr = malloc(sizeof(proc_t *) * (nb_elem_arr + 2));
    if (new_arr == NULL)
        return (NULL);
    for (copy_elems = 0; copy_elems < nb_elem_arr; copy_elems++)
        new_arr[copy_elems] = arr[copy_elems];
    new_arr[copy_elems] = add;
    new_arr[copy_elems + 1] = NULL;
    free(arr);
    return (new_arr);
}

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
        if (!(procs[i]->instruction->args = malloc(sizeof(int) * 4)))
            return (NULL);
        procs[i]->champion = champions[i];
    }
    return (procs);
}
