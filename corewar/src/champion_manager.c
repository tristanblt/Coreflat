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

champion_t *create_champion(char *path)
{
    char *file = NULL;
    int size = 0;
    champion_t *champion = malloc(sizeof(champion_t));
    static int champion_n = 1;

    if (champion == NULL)
        return (NULL);
    if ((file = get_cor_file(path, &size)) == NULL)
        return (NULL);
    if ((champion->header = parse_header(&file, &size)) == NULL)
        return (NULL);
    champion->instructions = file + size;
    if (parse_instructions(file, size) == false)
        return (NULL);
    champion->start_offset = -1;
    champion->registers = malloc(sizeof(int) * REG_NUMBER);
    if (champion->registers == NULL)
        return (NULL);
    for (int i = 0; i < REG_NUMBER; i++)
        champion->registers = 0;
    champion->registers[0] = champion_n;
    champion_n++;
    return (champion);
}