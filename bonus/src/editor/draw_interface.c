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
    draw_rect(cw_graph, (sfVector2f) {30, 160}, (sfVector2f) {500, 710},
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
    draw_background(cw_graph);
    draw_editor_subwindows(cw_graph);
}