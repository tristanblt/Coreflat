/*
** EPITECH PROJECT, 2019
** create list
** File description:
** creates an the list
*/

#include "corewar.h"
#include <stdlib.h>
#include "op.h"
#include "my.h"

int get_list_len(list_t *list)
{
    list_t *head = list;
    int len = 1;

    while (list->next != head) {
        len++;
        list = list->next;
    }
    return (len);
}

list_t *create_list(void)
{
    list_t *list = NULL;
    int size = 0;

    list = malloc(sizeof(list_t));
    if (list == NULL)
        return (NULL);
    list->val = 0;
    list->next = list;
    list->prev = list;
    add_n_next(list, MEM_SIZE - 1, 0);
    if ((size = get_list_len(list)) != MEM_SIZE) {
        my_dprintf(2, "Couldn't allocate enough space %d\n", MEM_SIZE);
        clear_list(list);
        return (NULL);
    }
    return (list);
}
