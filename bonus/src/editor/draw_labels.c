/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_labels
*/

#include "coreflat.h"

void draw_label(cw_graph_t *cw_graph, int line, int col, int i)
{
    draw_text(cw_graph, cw_graph->edit.instructions[i]->label, 25,
    (sfVector2f) {580 + col * 130 - (i > 8 ? 5 : 0), 40 + line * 64});
}

void draw_labels(cw_graph_t *cw_graph)
{
    int col = 0;
    int line = 0;

    for (int i = 0; cw_graph->edit.instructions[i]; i++) {
        if (!cw_graph->edit.instructions[i]->label)
            continue;
        draw_label(cw_graph, line, col, i);
        col++;
        if (col == 4) {
            col = 0;
            line++;
        }
    }
}