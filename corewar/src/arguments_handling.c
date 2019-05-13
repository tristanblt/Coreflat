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

champion_t *add_champion(char *path, int n, int a)
{
    champion_t *temp;

    if (!end_of_file(path, ".cor"))
        return (NULL);
    if ((temp = create_champion(path, n, a)) == NULL)
        return (NULL);
    return (temp);
}

int fill_arguments(char **av, int i, int *buff)
{
    if (my_strcmp(av[i], "-n")) {
        *buff = my_get_nbr(av[i + 1]);
        return (1);
    }
    if (my_strcmp(av[i], "-a")) {
        *buff = my_get_nbr(av[i + 1]);
        return (2);
    }
    if (my_strcmp(av[i], "-dump")) {
        *buff = my_get_nbr(av[i + 1]);
        return (3);
    }
    return (0);
}

bool argument_handling(int ac, char **av, champion_t ***champions)
{
    champion_t *temp;
    int n = 1;
    int a = -1;
    int dump = -1;
    int buff = 0;

    if (!argument_error_handling(av))
        return (false);
    for (int i = 1; i < ac; i++) {
        if ((temp = add_champion(av[i], n, a))) {
            *champions = push_champion(*champions, temp);
            n = n + 1;
            a = -1;
        }
        switch (fill_arguments(av, i, &buff)) {
        case 1: n = buff;
            i += 1;
            break;
        case 2: a = buff;
            i += 1;
            break;
        case 3: dump = buff;
            i += 1;
            break;
        }
        if (*champions == NULL)
            return (false);
    }
    for (int i = 0, error = 0; champions[0][i]; i++) {
        for (int j = 0; champions[0][j]; j++) {
            error = i != j && champions[0][i]->prog_number ==
            champions[0][j]->prog_number ? 1 : error;
        }
        if (error)
            return (false);
    }
    return (true);
}
