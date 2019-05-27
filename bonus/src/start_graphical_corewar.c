/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** start_graphical_corewar
*/

#include "coreflat.h"

bool start_graphical_corewar(champion_t **champions, list_t *memory)
{
    cw_graph_t *cw_graph = init_cw_graph();
    if (cw_graph == NULL)
        return (NULL);
    if (!game_loop(cw_graph, champions, memory))
        return (false);
    free_end(cw_graph, champions, memory);
    return (true);
}
