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
    champion_t **champions = NULL;

    // create chamption
    champion_t *temp;
    if ((temp = create_champion("test")) == NULL)
        return (84);
    //champions = push_champion(champions, temp);
    // end create champion
    start_cycle(&temp);
    return (0);
}
