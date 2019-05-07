/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "test.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

list_t *creat_list(void)
{
    list_t *list = NULL;

    list = malloc(sizeof(list_t));
    if (list == NULL)
        return (NULL);
    list->next = list;
    list->prev = list;
    return (list);
}

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

void delete_in_list(list_t *list)
{
    list->prev->next = list->next;
    list->next->prev = list->prev;
    free(list);
}

void add_to_next(list_t *list, int val)
{
    list_t *new = NULL;

    new = malloc(sizeof(list_t));
    if (new != NULL) {
        new->val = val;
        new->prev = list;
        new->next = list->next;
        list->next->prev = new;
        list->next = new;
    }
}

void add_to_prev(list_t *list, int val)
{
    list_t *new = NULL;

    new = malloc(sizeof(list_t));
    if (new != NULL) {
        new->val = val;
        new->next = list;
        new->prev = list->prev;
        list->prev->next = new;
        list->prev = new;
    }
}

void add_n_to_next(list_t *list, int nb, int val)
{
    for (int i = 0; i < nb; i++)
        add_to_next(list, val);
}

void add_n_to_prev(list_t *list, int nb, int val)
{
    for (int i = 0; i < nb; i++)
        add_to_prev(list, val);
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

int main(int ac, char **av)
{
    list_t *list = NULL;
    list_t *tmp = NULL;

    list = creat_list();
    for (int i = 1; i < 10; i++)
        add_to_next(list, i);
    add_n_to_next(list, 5, 0);
    list = go_n_next(list, 5);
    for (tmp = list->next; tmp != list; tmp = tmp->next)
        printf("%d\n", tmp->val);
    clear_list(list);
    return (0);
}