/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "coreflat.h"

int main(void)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();

    if (memory == NULL || !champions)
        return (EXIT_FAIL);
    srand((long) champions);
    champions[0] = NULL;
    if (!load_all_champions("bonus/champions/", &champions))
        return (EXIT_FAIL);
    if (!start_graphical_corewar(champions, memory))
        return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}
