/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** game_loop
*/

#include "coreflat.h"

bool display_views(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    switch (cw_graph->current_view)
    {
    case 0:
        if (!draw_corewar(cw_graph, champions, memory))
            return (false);
        break;
    case 1: draw_credits(cw_graph);
        break;
    }
    return (true);
}

bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    while (sfRenderWindow_isOpen(cw_graph->window->window)) {
        manage_events(cw_graph);
        draw_interface(cw_graph, champions);
        if (!display_views(cw_graph, champions, memory))
            return (false);
        sfRenderWindow_display(cw_graph->window->window);
    }
    return (true);
}