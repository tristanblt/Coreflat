/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** champion_manager
*/

#include "my.h"
#include "corewar.h"


champion_t *create_champion(char *path)
{
    char *file = NULL;
    int size = 0;
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return (NULL);
    if ((file = get_cor_file(path, &size)) == NULL)
        return (NULL);
    if ((champion->header = parse_header(&file, &size)) == NULL)
        return (NULL);
    if ((champion->instructions = parse_instructions(file, size)) == NULL)
        return (NULL);
    champion->nbr_live = 0;
    champion->alive = CYCLE_TO_DIE;
    champion->cycle_to_die = CYCLE_TO_DIE;
    return (champion);
}