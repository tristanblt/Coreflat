/*
** EPITECH PROJECT, 2019
** EPITECH 2018
** File description:
** arguments_handling
*/

#include "corewar.h"
#include "my.h"

int check_arguments(char **av, int i, int *buff)
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

bool check_champion_nb_error(champion_t ***champions)
{
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

bool add_champ_from_argument(char *path, int *n, int *a, champion_t ***champs)
{
    champion_t *to_add = NULL;

    if (!end_of_file_corewar(path, ".cor"))
        return (true);
    if (!(to_add = create_champion(path, *n, *a)))
        return (false);
    *champs = push_champion(*champs, to_add);
    if (!*champs)
        return (false);
    (*n)++;
    *a = -1;
    return (true);
}

bool argument_handling(int ac, char **av, champion_t ***champions, int *dump)
{
    int n = 1;
    int a = -1;
    int buff = 0;

    if (!argument_error_handling(ac, av))
        return (false);
    for (int i = 1; i < ac; i++) {
        if (!add_champ_from_argument(av[i], &n, &a, champions))
            return (false);
        switch (check_arguments(av, i, &buff)) {
        case 1: n = buff;
            break;
        case 2: a = buff;
            break;
        case 3: *dump = buff;
            break;
        }
    }
    if (!check_champion_nb_error(champions))
        return (false);
    return (true);
}
