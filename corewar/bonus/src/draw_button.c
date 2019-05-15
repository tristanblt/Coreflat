/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_button
*/

#include "coreflat.h"
#include "my.h"

bool is_in_rect(cw_graph_t *cw_graph, sfVector2f pos, sfVector2f size)
{
    sfVector2i mouse =
    sfMouse_getPosition((sfWindow *)cw_graph->window->window);

    if (mouse.x >= pos.x && mouse.x <= pos.x + size.x &&
        mouse.y >= pos.y && mouse.y <= pos.y + size.y)
        return (true);
    return (false);
}

void draw_button_form(cw_graph_t *cw_graph, sfVector2f pos, sfColor color)
{
    sfRectangleShape_setPosition(cw_graph->interface,
    (sfVector2f) {pos.x, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {150, 50});
    sfRectangleShape_setFillColor(cw_graph->interface, color);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfCircleShape_setPosition(cw_graph->buttons,
    (sfVector2f) {pos.x - 25, pos.y});
    sfCircleShape_setRadius(cw_graph->buttons, 25);
    sfCircleShape_setFillColor(cw_graph->buttons, color);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    sfCircleShape_setPosition(cw_graph->buttons,
    (sfVector2f) {pos.x + 125, pos.y});
    sfCircleShape_setRadius(cw_graph->buttons, 25);
    sfCircleShape_setFillColor(cw_graph->buttons, color);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
}

void draw_button_text(cw_graph_t *cw_graph, sfVector2f pos,
char *name)
{
    sfText_setString(cw_graph->text.text, name);
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 75 - 5.5 * my_strlen(name), pos.y + 10});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_button(cw_graph_t *cw_graph, sfVector2f pos, sfColor color,
char *name)
{
    if (is_in_rect(cw_graph, (sfVector2f) {pos.x - 25, pos.y},
        (sfVector2f) {200, 50}) && cw_graph->is_released)
        cw_graph->current_view = !cw_graph->current_view;
    if (is_in_rect(cw_graph, (sfVector2f) {pos.x - 25, pos.y},
        (sfVector2f) {200, 50}) && sfMouse_isButtonPressed(sfMouseLeft))
        color = (sfColor) {0, 0, 0, 255};
    else if (is_in_rect(cw_graph, (sfVector2f) {pos.x - 25, pos.y},
        (sfVector2f) {200, 50}))
        color = (sfColor) {50, 50, 50, 255};
    draw_button_form(cw_graph, pos, color);
    draw_button_text(cw_graph, pos, name);
}