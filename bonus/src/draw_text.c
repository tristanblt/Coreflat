/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_text
*/

#include "coreflat.h"

void draw_text(cw_graph_t *cw_graph, char *name, int size, sfVector2f pos)
{
    sfText_setString(cw_graph->text.text, name);
    sfText_setPosition(cw_graph->text.text, pos);
    sfText_setCharacterSize(cw_graph->text.text, size);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text,
    NULL);
}

void draw_text_no_color(cw_graph_t *cw_graph, char *name, int size,
sfVector2f pos)
{
    sfText_setString(cw_graph->text.text, name);
    sfText_setPosition(cw_graph->text.text, pos);
    sfText_setCharacterSize(cw_graph->text.text, size);
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text,
    NULL);
}