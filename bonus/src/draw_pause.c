/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** menu_pause
*/

#include "coreflat.h"

void draw_pause(cw_graph_t *cw_graph)
{
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {90, 170});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {990, 630});
    sfRectangleShape_setFillColor(cw_graph->interface, SUBWINDOW_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    draw_button(cw_graph, (sfVector2f){500, 350},
    cw_graph->interface_gradient, PLAY_TEXT);
    draw_button(cw_graph, (sfVector2f){500, 420},
    cw_graph->interface_gradient, MAIN_MENU_RES_TEXT);
    draw_button(cw_graph, (sfVector2f){500, 590},
    cw_graph->interface_gradient, EXIT_TEXT);
}