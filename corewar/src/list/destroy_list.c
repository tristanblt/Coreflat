/*
** EPITECH PROJECT, 2019
** destroy list
** File description:
** destroys the list
*/

#include "corewar.h"
#include <stdlib.h>

void delete_in_list(list_t *list)
{
    list->prev->next = list->next;
    list->next->prev = list->prev;
    free(list);
}

void clear_list(list_t *list)
{
    list_t *next = NULL;
    list_t *tmp = NULL;

    for (tmp = list->next; tmp != list; tmp = next) {
        next = tmp->next;
        free(tmp);
    }
    free(list);
}
