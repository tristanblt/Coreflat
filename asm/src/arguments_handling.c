/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** arguments_handling
*/

#include "my.h"
#include "asm.h"

bool end_of_file(char *path, char *end)
{
    int n = my_strlen(path) - 1;
    int i = 0;

    if (n <= my_strlen(end) - 1)
        return (false);
    for (i = n; path[i] != '.'; i--);
    path += i;
    if (!my_strcmp(path, end))
        return (false);
    return (true);
}

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
    if (my_strlen(av[1]) == 0)
        return (my_puterr("[file_name] can't be empty (-h for help)"));
    if (!end_of_file(av[1], ".s"))
        return (my_puterr("[file_name] need to be a \".s\" file (-h for help)"));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (my_puterr("[file_name] is not a file (-h for help)"));
    close(fd);
    return (true);
}