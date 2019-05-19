/*
** EPITECH PROJECT, 2019
** draw input number
** File description:
** draw input number
*/

#include "coreflat.h"
#include "my.h"

void draw_bar_white(cw_graph_t *cw_graph, sfVector2f pos)
{
    sfVector2f pos2 = (sfVector2f){pos.x + 504, pos.y + 4};
    sfVector2f rect_pos = (sfVector2f){pos.x + 31, pos.y + 4};

    pos = (sfVector2f){pos.x + 4, pos.y + 4};
    sfCircleShape_setPosition(cw_graph->buttons, pos);
    sfCircleShape_setRadius(cw_graph->buttons, 27);
    sfCircleShape_setFillColor(cw_graph->buttons, sfWhite);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    sfCircleShape_setPosition(cw_graph->buttons, pos2);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    sfRectangleShape_setFillColor(cw_graph->interface, sfWhite);
    sfRectangleShape_setPosition(cw_graph->interface, rect_pos);
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f){500, 54});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

void draw_bar_gradient(cw_graph_t *cw_graph, sfVector2f pos)
{
    sfVector2f pos2 = {pos.x + 500, pos.y};
    sfVector2f rect_pos = {pos.x + 31, pos.y};

    sfCircleShape_setPosition(cw_graph->buttons, pos);
    sfCircleShape_setRadius(cw_graph->buttons, 31);
    sfCircleShape_setFillColor(cw_graph->buttons, cw_graph->interface_gradient);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    sfCircleShape_setPosition(cw_graph->buttons, pos2);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    sfRectangleShape_setFillColor(cw_graph->interface,
    cw_graph->interface_gradient);
    sfRectangleShape_setPosition(cw_graph->interface, rect_pos);
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f){500, 62});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

void update_input(cw_graph_t *cw_graph, char *str, int size)
{
    int len = my_strlen(str);
    sfKeyCode code = cw_graph->window->event.key.code;
    char alpha_offset = 'a';

    (code == sfKeyBack && len) ? str[len - 1] = 0 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        alpha_offset = 'A';
    if (len > size)
        return;
    if ((code >= sfKeyA && code <= sfKeyZ) ||
        (code >= sfKeyNum0 && code <= sfKeyNum9) ||
        code == sfKeySpace || code == 56)
        str[len + 1] = 0;
    if (code >= sfKeyA && code <= sfKeyZ)
        str[len] = alpha_offset + code;
    if (code >= sfKeyNum0 && code <= sfKeyNum9)
        str[len] = 22 + code;
    if (code == sfKeySpace)
        str[len] = ' ';
    if (code == 56)
        str[len] = '_';
}

void update_input_nb(cw_graph_t *cw_graph, char *str, int size)
{
    int len = my_strlen(str);
    sfKeyCode code = cw_graph->window->event.key.code;

    (code == sfKeyBack && len) ? str[len - 1] = 0 : 0;
    if (len > size)
        return;
    if (code >= sfKeyNum0 && code <= sfKeyNum9) {
        str[len] = 22 + code;
        str[len + 1] = 0;
    }
}

void draw_input_bar(cw_graph_t *cw_graph, sfVector2f pos, char *str)
{
    draw_bar_gradient(cw_graph, pos);
    draw_bar_white(cw_graph, pos);
    pos.x += 20;
    pos.y += 17;
    sfText_setPosition(cw_graph->text.text, pos);
    sfText_setColor(cw_graph->text.text, SUBWINDOW_COLOR);
    if (!str[0]) {
        str = "Enter your champion's name";
        sfText_setColor(cw_graph->text.text, (sfColor){150, 150, 150, 255});
    }
    sfText_setString(cw_graph->text.text, str);
    sfRenderWindow_drawText(cw_graph->window->window,
                            cw_graph->text.text, NULL);
}

void draw_input_bar_nb(cw_graph_t *cw_graph, sfVector2f pos, char *str)
{
    draw_bar_gradient(cw_graph, pos);
    draw_bar_white(cw_graph, pos);
    pos.x += 20;
    pos.y += 17;
    sfText_setPosition(cw_graph->text.text, pos);
    sfText_setColor(cw_graph->text.text, SUBWINDOW_COLOR);
    if (!cw_graph->edit.buffer) {
        str = "Enter a number";
        sfText_setColor(cw_graph->text.text, (sfColor){150, 150, 150, 255});
    }
    sfText_setString(cw_graph->text.text, str);
    sfRenderWindow_drawText(cw_graph->window->window,
                            cw_graph->text.text, NULL);
}
