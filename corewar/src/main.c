/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** wow
*/

#include "my.h"
#include "corewar.h"

int main(void)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();

    if (memory == NULL || !champions)
        return (EXIT_FAIL);
    *champions = NULL;
    // create chamption
    champion_t *temp;
    if ((temp = create_champion("test.cor")) == NULL)
        return (EXIT_FAIL);
    if ((champions = push_champion(champions, temp)) == NULL)
        return (EXIT_FAIL);
    // end create champion
    if (!load_champion_instructions_in_mem(champions, memory))
        return (EXIT_FAIL);
    if (!start_corewar(champions, memory))
        return (EXIT_FAIL);
    return (0);
}
