/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_selector
*/

#include "coreflat.h"

bool draw_selector_button(cw_graph_t *cw_graph, sfVector2f pos)
{
    bool ret = false;

    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) &&
    cw_graph->is_released) {
        ret = true;
    }
    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        sfRectangleShape_setFillColor(cw_graph->interface,
        SELECTOR_COLOR_CLICKED);
    else if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}))
        sfRectangleShape_setFillColor(cw_graph->interface,
        SELECTOR_COLOR_HOVE);
    else
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f)
    {pos.x, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {100, 100});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    return (ret);
}

void draw_more_less(cw_graph_t *cw_graph, sfVector2f pos)
{
    sfText_setString(cw_graph->text.text, "-");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 35, pos.y + 15});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, "+");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 200 + 35, pos.y + 15});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_selector(cw_graph_t *cw_graph, sfVector2i limiter, sfVector2f pos,
int *value)
{
    if (draw_selector_button(cw_graph, (sfVector2f){pos.x, pos.y})
        && *value > limiter.x)
        (*value)--;
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f)
    {pos.x + 100, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {100, 100});
    sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_MIDDLE_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfText_setString(cw_graph->text.text, int_to_str(*value));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 100 + 35, pos.y + 15});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    if (draw_selector_button(cw_graph, (sfVector2f){pos.x + 200, pos.y})
        && *value < limiter.y)
        (*value)++;
    draw_more_less(cw_graph, pos);
}