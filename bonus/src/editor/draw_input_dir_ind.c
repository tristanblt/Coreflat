/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_input_dir_ind
*/

#include "coreflat.h"

void draw_input_dir_ind(cw_graph_t *cw_graph)
{
    sfColor color = SELECTOR_COLOR;
    sfVector2i mouse = sfMouse_getPosition(cw_graph->window->window);
    sfVector2f pos;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse && cw_graph->is_released)
        cw_graph->edit.number_selected = 0;
    if (cw_graph->edit.number_selected == 0)
        pos = (sfVector2f) {580, 800};
    else
        pos = (sfVector2f) {(int)mouse.x - 20, (int)mouse.y - 20};
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
    pos, (sfVector2f) {50, 50}) && cw_graph->edit.number_selected == 0 &&
    cw_graph->edit.register_selected == 0) {
        color = SELECTOR_COLOR_CLICKED;
        if (is_num(cw_graph->edit.buffer))
            cw_graph->edit.number_selected = 1;
        else
            cw_graph->edit.number_selected = 2;
    }
    else if (is_in_rect(cw_graph, pos, (sfVector2f) {50, 50}))
        color = SELECTOR_COLOR_HOVE;
    else
        color = SELECTOR_COLOR;
    sfCircleShape_setPosition(cw_graph->buttons, pos);
    sfCircleShape_setRadius(cw_graph->buttons, 25);
    sfCircleShape_setFillColor(cw_graph->buttons, color);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    draw_text(cw_graph, "n", 25,
    (sfVector2f) {18 + pos.x, 9 + pos.y});
    draw_text(cw_graph, "Type:", 20, (sfVector2f) {700, 815});
    draw_text(cw_graph, (cw_graph->edit.indirect_type ? "Indirect" : "Direct"), 20, (sfVector2f) {780, 815});
    draw_button(cw_graph, (sfVector2f) {950, 800}, cw_graph->interface_gradient, CHANGE_TYPE_TEXT);
}