/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_editor
*/

#include "coreflat.h"

void draw_edition(cw_graph_t *cw_graph)
{
    draw_background(cw_graph);
}

bool draw_editor(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    cw_graph->edit.step = 5;
    if (cw_graph->edit.step < 5)
        draw_configuration(cw_graph);
    else
        draw_edition(cw_graph);
    return (true);
}