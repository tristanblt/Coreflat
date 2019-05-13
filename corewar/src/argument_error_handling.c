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
    if (my_strcmp(av[*i], "-n") || my_strcmp(av[*i], "-a") ||
        my_strcmp(av[*i], "-dump")) {
        if (!av[*i + 1] || !is_num(av[*i + 1]))
            return (false);
        if (av[*i][1] != 'd')
            *expected = true;
    }
    (*i)++;
    return (true);
}

bool argument_error_handling(char **av)
{
    int champions = 0;
    bool expected = false;

    for (int i = 1; av[i]; i++) {
        if (end_of_file(av[i], ".cor")) {
            champions++;
            expected = false;
        } else if (!is_option_valid(av, &expected, &i))
            return (false);
    }
    if (expected || champions < 2 || champions > 4)
        return (false);
    return (true);
}
