/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_game2
*/

#include "coreflat.h"

bool init_edition(cw_graph_t *cw_graph)
{
    cw_graph->edit = (editor_t) {0};
    cw_graph->edit.buffer = malloc(sizeof(char) * 14);
    if (cw_graph->edit.buffer == NULL)
        return (false);
    for (int i = 0; i < 14; i++)
        cw_graph->edit.buffer[i] = 0;
    cw_graph->edit.number_selected = false;
}