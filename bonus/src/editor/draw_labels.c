/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_labels
*/

#include "coreflat.h"

void draw_label(cw_graph_t *cw_graph, int line, int col, int i)
{
    sfColor color = SUBWINDOW_COLOR;

    if (cw_graph->is_released && is_in_rect(cw_graph,
        (sfVector2f) {560 + col * 110, 30+line*45}, (sfVector2f) {110, 45}))
        strcpy(cw_graph->edit.buffer, cw_graph->edit.instructions[i]->label);
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
        (sfVector2f) {560+col*110, 30 + line * 45}, (sfVector2f) {110, 45}))
        color = SELECTOR_COLOR_CLICKED;
    else if (is_in_rect(cw_graph, (sfVector2f) {560 + col * 110, 30 + line*45},
    (sfVector2f) {110, 45})) {
        color = SELECTOR_COLOR_HOVE;
    }
    draw_rect(cw_graph, (sfVector2f) {560 + col * 110, 30 + line * 45},
    (sfVector2f) {110, 45}, color);
    draw_text(cw_graph, cw_graph->edit.instructions[i]->label, 18,
    (sfVector2f) {570 + col * 110, 40 + line * 45});
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
        if (col == 5) {
            col = 0;
            line++;
        }
    }
}