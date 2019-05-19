/*
** EPITECH PROJECT, 2019
** get_int_from_mem
** File description:
** return an int of size
*/

#include "corewar.h"
#include "my.h"

int get_nb_from_mem(list_t *mem, int size, int offset)
{
    int nb = 0;

    if (offset > 0)
        mem = go_n_next(mem, offset);
    else
        mem = go_n_prev(mem, -offset);
    for (int i = 0; i < size; i++) {
        nb <<= 8;
        nb |= mem->val & 0xFF;
        mem = mem->next;
    }
    return (nb);
}
