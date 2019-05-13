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

    if (memory == NULL || !champions)
        return (EXIT_FAIL);
    if (!argument_handling(ac, av, &champions))
        return (false);
    for (int i = 0; champions[i]; i++) {
        printf("%s\n", champions[i]->header->prog_name);
    }
    return ('a');
    if (!load_champion_instructions_in_mem(champions, memory))
        return (EXIT_FAIL);
    if (!start_corewar(champions, memory))
        return (EXIT_FAIL);
    return (0);
}
