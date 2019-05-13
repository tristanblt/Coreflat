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

bool argument_handling(int ac, char **av, champion_t ***champions)
{
    champion_t *temp;
    int n = 0;
    int a = 0;

    argument_error_handling(ac, av);
    for (int i = 1; i < ac; i++) {
        if ((temp = add_champion(av[i], n, a))) {
            *champions = push_champion(*champions, temp);
        }
    }
    return (true);
}
