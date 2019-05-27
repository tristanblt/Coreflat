/*
** EPITECH PROJECT, 2019
** dump memory
** File description:
** dumps the memory
*/

#include "corewar.h"
#include "my.h"

void convert_int_to_hexa(int nb, char *str, int size, bool null)
{
    char *base = "0123456789ABCDEF";

    for (int i = size - 1; i >= 0; i--) {
        str[i] = base[nb & 15];
        nb >>= 4;
    }
    for (int i = 0; str[i]; i++)
        if (str[i] == '0' && null && i != size - 1)
            str[i] = ' ';
        else
            null = false;
}

void dump_memory(list_t *mem)
{
    char nb[3] = {0};
    char line[6] = {0};

    for (int i = 0; i < MEM_SIZE; i++) {
        convert_int_to_hexa(mem->val, nb, 2, false);
        if (!(i % 32)) {
            convert_int_to_hexa(i, line, 5, true);
            my_printf("%s : ", line);
        }
        my_printf("%s%c", nb, (i % 32) != 31 ? ' ' : '\n');
        mem = mem->next;
    }
}
