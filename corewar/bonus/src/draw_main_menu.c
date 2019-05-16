/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_main_menu
*/

#include "coreflat.h"

bool draw_main_menu(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    champions = (void *)champions;
    memory = (void *)memory;
    draw_background(cw_graph);
    sfText_setString(cw_graph->text.text, WINDOW_NAME);
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {225, 250});
    sfText_setCharacterSize(cw_graph->text.text, 70);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_button(cw_graph, (sfVector2f) {250, 370}, cw_graph->interface_gradient,
    "Begin the war");
    draw_button(cw_graph, (sfVector2f) {250, 440}, cw_graph->interface_gradient,
    "Help");
    draw_button(cw_graph, (sfVector2f) {250, 510}, cw_graph->interface_gradient,
    "Credits");
    draw_button(cw_graph, (sfVector2f) {250, 580}, cw_graph->interface_gradient,
    "Exit");
    return (true);
}