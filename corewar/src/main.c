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

    // create chamption
    champion_t *temp;
    if ((temp = create_champion("test")) == NULL)
        return (EXIT_FAIL);
    if ((champions = push_champion(champions, temp)) == NULL)
        return (EXIT_FAIL);
    // end create champion
    if (!start_corewar(champions))
        return (EXIT_FAIL);
    return (0);
}
