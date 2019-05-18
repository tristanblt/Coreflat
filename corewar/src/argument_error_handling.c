/*
** EPITECH PROJECT, 2019
** argument error handling
** File description:
** handles error for arguments
*/

#include "my.h"
#include "corewar.h"

bool is_option_valid(char **av, bool *expected, int *i)
{
    if (my_strcmp(av[*i], "-n") || my_strcmp(av[*i], "-a") ||\
my_strcmp(av[*i], "-dump")) {
        if (!av[*i + 1] || !is_num(av[*i + 1]))
            return (false);
        if (av[*i][1] != 'd')
            *expected = true;
    } else
        return (false);
    (*i)++;
    return (true);
}

bool argument_error_handling(int ac, char **av)
{
    int champions = 0;
    bool expected = false;
    int fd = 0;

    for (int i = 1; i < ac; i++) {
        if (end_of_file_corewar(av[i], ".cor") &&
        (fd = open(av[i], O_RDONLY)) != -1) {
            close(fd);
            champions++;
            expected = false;
        } else if (!is_option_valid(av, &expected, &i))
            return (false);
    }
    if (expected || champions < 2 || champions > 4)
        return (false);
    return (true);
}
