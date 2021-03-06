/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** wow
*/

#include "my.h"
#include "corewar.h"

int main(int ac, char **av)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    int dump = -1;

    if (memory == NULL || !champions)
        return (EXIT_FAIL);
    champions[0] = NULL;
    if (!argument_handling(ac, av, &champions, &dump))
        return (EXIT_FAIL);
    if (!load_champion_instructions_in_mem(champions, memory))
        return (EXIT_FAIL);
    if (!start_corewar(champions, memory, dump))
        return (EXIT_FAIL);
    destroy_champions(champions);
    clear_list(memory);
    return (EXIT_SUCCESS);
}
