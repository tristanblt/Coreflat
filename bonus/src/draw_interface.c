/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_interface
*/

#include "coreflat.h"

void draw_background(cw_graph_t *cw_graph)
{
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1600, 900});
    sfRectangleShape_setFillColor(cw_graph->interface, BACKGROUND_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

void draw_header(cw_graph_t *cw_graph)
{
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1600, 80});
    sfRectangleShape_setFillColor(cw_graph->interface,
    cw_graph->interface_gradient);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfText_setString(cw_graph->text.text, WINDOW_NAME);
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {25, 15});
    sfText_setCharacterSize(cw_graph->text.text, 35);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_subwindows(cw_graph_t *cw_graph)
{
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {30, 110});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1110, 760});
    sfRectangleShape_setFillColor(cw_graph->interface, SUBWINDOW_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {1170, 110});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {400, 260});
    sfRectangleShape_setFillColor(cw_graph->interface, SUBWINDOW_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {1170, 400});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {400, 470});
    sfRectangleShape_setFillColor(cw_graph->interface, SUBWINDOW_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

void draw_buttons(cw_graph_t *cw_graph)
{
    char *text = cw_graph->g_setts.corewar_launched ? PAUSE_TEXT : PLAY_TEXT;
    draw_button(cw_graph, (sfVector2f){1400, 15}, BACKGROUND_COLOR, text);
}

void draw_interface(cw_graph_t *cw_graph, champion_t **champions)
{
    draw_background(cw_graph);
    draw_header(cw_graph);
    draw_subwindows(cw_graph);
    draw_buttons(cw_graph);
    draw_icons(cw_graph, champions);
}
