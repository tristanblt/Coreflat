/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "coreflat.h"

int main(int ac, char **av)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();

    champions[0] = NULL;
    if (memory == NULL || !champions)
        return (EXIT_FAIL);
    if (!argument_handling(ac, av, &champions))
        return (EXIT_FAIL);
    if (!load_champion_instructions_in_mem(champions, memory))
        return (EXIT_FAIL);
    if (!start_graphical_corewar(champions, memory))
        return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}
