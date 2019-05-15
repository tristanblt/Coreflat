/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_credits
*/

#include "coreflat.h"

void draw_credits(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, DRAW_CREDITS_TEXT);
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {60, 140});
    sfText_setCharacterSize(cw_graph->text.text, 25);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}