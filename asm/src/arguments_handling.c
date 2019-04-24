/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** arguments_handling
*/

#include "my.h"
#include "asm.h"

bool my_puterr(char *str)
{
    write(2, str, my_strlen(str));
    return (false);
}

bool arguments_handling(int ac, char **av)
{
    int fd;

    if (ac != 2)
        return (my_puterr("Not enough arguments (-h for help)"));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (my_puterr("[file_name] is not a file (-h for help)"));
    close(fd);
    return (true);
}