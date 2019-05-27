/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_settings
*/

#include "coreflat.h"

bool draw_settings(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    champions = (void *)champions;
    memory = (void *)memory;
    draw_background(cw_graph);
    draw_text(cw_graph, "Volume:", 20, (sfVector2f){225, 370});
    draw_selector(cw_graph, (sfVector2i){0, 9}, (sfVector2f){225, 400},
    &cw_graph->g_setts.volume);
    draw_button(cw_graph, (sfVector2f){250, 530},
    cw_graph->interface_gradient, MAIN_MENU_TEXT);
    return (true);
}