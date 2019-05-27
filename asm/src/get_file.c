/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_file
*/

#include "my.h"
#include "asm.h"

char **push(char **arr, char *add)
{
    char **new_arr = NULL;
    int nb_elem_arr;
    int copy_elems;

    for (nb_elem_arr = 0; arr[nb_elem_arr] != NULL; nb_elem_arr++);
    new_arr = malloc(sizeof(char *) * (nb_elem_arr + 2));
    if (new_arr == NULL)
        return (NULL);
    for (copy_elems = 0; copy_elems < nb_elem_arr; copy_elems++)
        new_arr[copy_elems] = arr[copy_elems];
    new_arr[copy_elems] = add;
    new_arr[copy_elems + 1] = NULL;
    free(arr);
    return (new_arr);
}

char **get_file(FILE *fd)
{
    char **to_ret = malloc(sizeof(char *));
    char *line = NULL;
    size_t size = 0;

    if (to_ret == NULL)
        return (NULL);
    to_ret[0] = NULL;
    while (getline(&line, &size, fd) != -1) {
        if (line == NULL)
            return (NULL);
        to_ret = push(to_ret, line);
        if (to_ret == NULL)
            return (NULL);
        line = NULL;
    }
    if (line)
        free(line);
    return (to_ret);
}
