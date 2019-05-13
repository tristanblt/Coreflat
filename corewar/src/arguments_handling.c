/*
** EPITECH PROJECT, 2019
** EPITECH 2018
** File description:
** arguments_handling
*/

#include "corewar.h"
#include "my.h"

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

bool argument_handling(int ac, char **av)
{
    argument_error_handling(ac, av);
    return (true);
}
