/*
** EPITECH PROJECT, 2019
** main
** File description:
** main disasm
*/

#include "disasm.h"
#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int display_help(char *name)
{
    my_printf("USAGE:\n\t\
%s [file_in] [file_out]\n\nDESCRIPTION\n\t\
file_in\t\tInput file, Must be a valid .cor\n\t\
file_out\tOutput file, optional\n", name);
    return (0);
}

int get_fd(int ac, char **av)
{
    if (ac <3)
        return (1);
    return (open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

int main(int ac, char **av)
{
    header_t *header = NULL;
    instruction_t **insts;
    int fd = 0;

    if (ac == 1)
        return (display_help(av[0]));
    if ((fd = get_fd(ac, av))==-1||!(insts = malloc(sizeof(instruction_t *))))
        return (84);
    insts[0] = NULL;
    if (!parse_header_and_instruction(&header, &insts, av[1])) {
        my_dprintf(2, "Error with file %s\n", av[1]);
        return (84);
    }
    compute_instructions_sizes(insts);
    fill_label_args(insts);
    write_header_disasm(header, fd);
    write_instructions(insts, fd);
    destroy_instructions(insts);
    free(header);
    fd != 1 ? close(fd) : 0;
    return (0);
}
