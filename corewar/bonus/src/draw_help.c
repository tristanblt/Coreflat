/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_help
*/

#include "coreflat.h"

bool draw_help(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    champions = (void *)champions;
    memory = (void *)memory;
    draw_background(cw_graph);
    sfText_setString(cw_graph->text.text, DRAW_HELP_TEXT);
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {250, 200});
    sfText_setCharacterSize(cw_graph->text.text, 25);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_button(cw_graph, (sfVector2f) {250, 750}, cw_graph->interface_gradient, MAIN_MENU_TEXT);
    return (true);
}