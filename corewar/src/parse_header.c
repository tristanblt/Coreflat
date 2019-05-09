/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_header
*/

#include "my.h"
#include "corewar.h"

int reverse_bytes(unsigned int x)
{
    unsigned int out = 0;
    unsigned int byte;

    for(int i = 0; i < 4; ++i) {
        byte = (x >> 8 * i) & 0xff;
        out |= byte << (24 - 8 * i);
    }
    return out;
}

int reverse_bytes_two(unsigned int x)
{
    unsigned int out = 0;
    unsigned int byte;

    for(int i = 0; i < 2; ++i) {
        byte = (x >> 8 * i) & 0xff;
        out |= byte << (8 - 8 * i);
    }
    return out;
}

char *copy_str(char *str, int size)
{
    char *ret = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));

    if (ret == NULL)
        return (NULL);
    for (int i = 0; i < size && str[i]; i++) {
        
    }
    ret[PROG_NAME_LENGTH] = 0;
    return (ret);
}

header_t *parse_header(char **file, int *size)
{
    header_t *header = NULL;

    if (COREWAR_EXEC_MAGIC != reverse_bytes(*(int *)(*file)))
        return (NULL);
    *file += 4;
    *size -= 4;
    header = malloc(sizeof(header_t));
    for (int i = 0; i < PROG_NAME_LENGTH && file[0][i]; i++)
        header->prog_name[i] = file[0][i];
    *file += PROG_NAME_LENGTH + 8;
    *size -= PROG_NAME_LENGTH + 8;
    for (int i = 0; i < COMMENT_LENGTH && file[0][i]; i++)
        header->comment[i] = file[0][i];
    *file += COMMENT_LENGTH + 4;
    *size -= COMMENT_LENGTH + 4;
    return (header);
}