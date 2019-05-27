/*
** EPITECH PROJECT, 2019
** move in list
** File description:
** moves n elements in the list
*/

#include "corewar.h"

list_t *go_next(list_t *list)
{
    if (list)
        list = list->next;
    return (list);
}

list_t *go_n_next(list_t *list, int nb)
{
    for (int i = 0; list && i < nb; i++)
        list = go_next(list);
    return (list);
}

list_t *go_prev(list_t *list)
{
    if (list)
        list = list->prev;
    return (list);
}

list_t *go_n_prev(list_t *list, int nb)
{
    for (int i = 0; list && i < nb; i++)
        list = go_prev(list);
    return (list);
}
