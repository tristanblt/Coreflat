/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_header
*/

#include "my.h"
#include "disasm.h"
#include <fcntl.h>
#include <unistd.h>

int reverse_bytes_disasm(unsigned int x)
{
    unsigned int out = 0;
    unsigned int byte;

    for (int i = 0; i < 4; ++i) {
        byte = (x >> 8 * i) & 0xff;
        out |= byte << (24 - 8 * i);
    }
    return (out);
}

int reverse_bytes_two_disasm(unsigned int x)
{
    unsigned int out = 0;
    unsigned int byte;

    for (int i = 0; i < 2; ++i) {
        byte = (x >> 8 * i) & 0xff;
        out |= byte << (8 - 8 * i);
    }
    return (out);
}

header_t *parse_header_disasm(char *file_path, char **file_content)
{
    int fd = open(file_path, O_RDONLY);
    header_t *header = malloc(sizeof(header_t));

    if (fd == -1 || !header)
        return (NULL);
    *header = (header_t){0};
    if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
        return (NULL);
    header->magic = reverse_bytes_disasm(header->magic);
    header->prog_size = reverse_bytes_disasm(header->prog_size);
    if (header->magic != COREWAR_EXEC_MAGIC || header->prog_size < 0 ||
    !(*file_content = malloc(sizeof(char) * (header->prog_size + 1)))) {
        (free(header), close(fd));
        return (NULL);
    }
    (*file_content)[header->prog_size] = 0;
    if (read(fd, *file_content, header->prog_size) != header->prog_size) {
        (free(header), close(fd), free(*file_content));
        return (NULL);
    } close(fd);
    return (header);
}
