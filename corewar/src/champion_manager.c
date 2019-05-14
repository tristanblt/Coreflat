/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** champion_manager
*/

#include "my.h"
#include "corewar.h"

champion_t **push_champion(champion_t **arr, champion_t *add)
{
    champion_t **new_arr = NULL;
    int nb_elem_arr;
    int copy_elems;

    for (nb_elem_arr = 0; arr[nb_elem_arr] != NULL; nb_elem_arr++);
    new_arr = malloc(sizeof(champion_t *) * (nb_elem_arr + 2));
    if (new_arr == NULL)
        return (NULL);
    for (copy_elems = 0; copy_elems < nb_elem_arr; copy_elems++)
        new_arr[copy_elems] = arr[copy_elems];
    new_arr[copy_elems] = add;
    new_arr[copy_elems + 1] = NULL;
    free(arr);
    return (new_arr);
}

champion_t *create_champion(char *path, int n, int a)
{
    char *file = NULL;
    int size = 0;
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return (NULL);
    *champion = (champion_t){0};
    if ((file = get_cor_file(path, &size)) == NULL)
        return (NULL);
    if ((champion->header = parse_header(&file, &size)) == NULL)
        return (NULL);
    champion->instructions = file;
    if (parse_instructions(file, size) == false)
        return (NULL);
    champion->start_offset = a;
    champion->prog_number = n;
    return (champion);
}
