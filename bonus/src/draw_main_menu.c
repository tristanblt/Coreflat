/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_main_menu
*/

#include "coreflat.h"

void draw_button_main_menu(cw_graph_t *cw_graph)
{
    draw_button(cw_graph, (sfVector2f) {250, 320}, cw_graph->interface_gradient,
    BEGIN_TEXT);
    draw_button(cw_graph, (sfVector2f) {250, 390}, cw_graph->interface_gradient,
    EDITOR_TEXT);
    draw_button(cw_graph, (sfVector2f){250, 460}, cw_graph->interface_gradient,
    VISUALISER_TEXT);
    draw_button(cw_graph, (sfVector2f) {250, 530}, cw_graph->interface_gradient,
    SETTINGS_TEXT);
    draw_button(cw_graph, (sfVector2f) {250, 600}, cw_graph->interface_gradient,
    HELP_TEXT);
    draw_button(cw_graph, (sfVector2f) {250, 670}, cw_graph->interface_gradient,
    CREDITS_TEXT);
    draw_button(cw_graph, (sfVector2f) {250, 740}, cw_graph->interface_gradient,
    EXIT_TEXT);
}

bool draw_main_menu(cw_graph_t *cw_graph, champion_t **champions,
list_t *memory)
{
    champions = (void *)champions;
    memory = (void *)memory;
    draw_background(cw_graph);
    sfText_setString(cw_graph->text.text, WINDOW_NAME);
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {225, 200});
    sfText_setCharacterSize(cw_graph->text.text, 70);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_button_main_menu(cw_graph);
    return (true);
}
