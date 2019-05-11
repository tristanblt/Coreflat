/*
** EPITECH PROJECT, 2019
** add to list
** File description:
** adds elem to list
*/

#include <stdlib.h>
#include "corewar.h"

void add_next(list_t *list, int val)
{
    list_t *new = NULL;
    static int id = 0;

    new = malloc(sizeof(list_t));
    if (new != NULL) {
        new->val = val;
        new->id = id;
        new->prev = list;
        new->next = list->next;
        list->next->prev = new;
        list->next = new;
        id++;
    }
}

void add_prev(list_t *list, int val)
{
    list_t *new = NULL;
    static int id = 0;

    new = malloc(sizeof(list_t));
    if (new != NULL) {
        new->val = val;
        new->next = list;
        new->prev = list->prev;
        list->prev->next = new;
        list->prev = new;
        new->id = id;
        id++;
    }
}

void add_n_next(list_t *list, int nb, int val)
{
    for (int i = 0; i < nb; i++)
        add_next(list, val);
}

void add_n_prev(list_t *list, int nb, int val)
{
    for (int i = 0; i < nb; i++)
        add_prev(list, val);
}
