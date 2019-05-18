/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** writing_in_file
*/

#include "asm.h"
#include "my.h"

void write_n_zeros(int n, int fd)
{
    int temp = 0;

    for (int i = 0; i < n; i++) {
        write(fd, &temp, 1);
    }
}

void write_header_asm(header_t *header, int fd)
{
    write(fd, header, sizeof(header_t));
}

void write_description(char *description, int fd)
{
    char c = 0;
    int i = 0;

    for (i = 0; description[i] != -1; i++) {
        if (description[i] == T_REG)
            c += 1;
        if (description[i] == T_DIR)
            c += 2;
        if (description[i] == T_IND)
            c += 3;
        c <<= 2;
    }
    for (; i < 3; i++)
        c <<= 2;
    write(fd, &c, 1);
}

void write_reverse_bytes(int arg, char size, int fd)
{
    int i = 0;
    int temp = arg;
    int max = size * 8 - 8;

    for (i = 0; i < size; i++) {
        temp = arg;
        temp >>= max;
        max -= 8;
        write(fd, &temp, 1);
    }
}

void write_with_good_size(char c, int arg, int fd, int code)
{
    if (c == T_REG)
        write_reverse_bytes(arg, 1, fd);
    if (c == T_DIR) {
        if (uses_indexes_asm(code))
            write_reverse_bytes(arg, IND_SIZE, fd);
        else
            write_reverse_bytes(arg, DIR_SIZE, fd);
    }
    if (c == T_IND)
        write_reverse_bytes(arg, IND_SIZE, fd);
}
