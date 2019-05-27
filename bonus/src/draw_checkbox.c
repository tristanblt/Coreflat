/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_checkbox
*/

#include "coreflat.h"

void draw_checkbox_x(cw_graph_t *cw_graph, sfVector2f pos)
{
    sfText_setString(cw_graph->text.text, "X");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 27, pos.y});
    sfText_setCharacterSize(cw_graph->text.text, 80);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_checkbox(cw_graph_t *cw_graph, sfVector2f pos, bool *value)
{
    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) &&
    cw_graph->is_released) {
        *value = !(*value);
        cw_graph->g_setts.pass_step += *value ? 1 : -1;
    }
    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        sfRectangleShape_setFillColor(cw_graph->interface,
        SELECTOR_COLOR_CLICKED);
    else if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_HOVE);
    else
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f)
    {pos.x, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {100, 100});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    if (*value)
        draw_checkbox_x(cw_graph, pos);
}
