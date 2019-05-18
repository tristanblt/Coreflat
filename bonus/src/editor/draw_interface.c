/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_interface
*/

#include "coreflat.h"

void draw_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape_setPosition(cw_graph->interface, pos);
    sfRectangleShape_setSize(cw_graph->interface, size);
    sfRectangleShape_setFillColor(cw_graph->interface, color);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

void draw_editor_subwindows(cw_graph_t *cw_graph)
{
    draw_rect(cw_graph, (sfVector2f) {30, 30}, (sfVector2f) {500, 100},
    SUBWINDOW_COLOR);
    draw_rect(cw_graph, (sfVector2f) {560, 30}, (sfVector2f) {550, 300},
    SUBWINDOW_COLOR);
    draw_rect(cw_graph, (sfVector2f) {560, 360}, (sfVector2f) {550, 300},
    SUBWINDOW_COLOR);
    draw_rect(cw_graph, (sfVector2f) {560, 690}, (sfVector2f) {550, 180},
    SUBWINDOW_COLOR);
    draw_rect(cw_graph, (sfVector2f) {1140, 30}, (sfVector2f) {430, 630},
    SUBWINDOW_COLOR);
    draw_rect(cw_graph, (sfVector2f) {1140, 690}, (sfVector2f) {430, 180},
    SUBWINDOW_COLOR);
}

void draw_editor_interface(cw_graph_t *cw_graph)
{
    draw_rect(cw_graph, (sfVector2f) {0, 0}, (sfVector2f) {1600, 160},
    BACKGROUND_COLOR);
    draw_rect(cw_graph, (sfVector2f) {530, 0}, (sfVector2f) {1070, 900},
    BACKGROUND_COLOR);
    draw_rect(cw_graph, (sfVector2f) {0, 870}, (sfVector2f) {1600, 30},
    BACKGROUND_COLOR);
    draw_editor_subwindows(cw_graph);
    draw_text(cw_graph, cw_graph->edit.header->prog_name, 35, (sfVector2f){60, 55});
}
