/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_register
*/

#include "coreflat.h"

void draw_register_circle(cw_graph_t *cw_graph, sfVector2f lc, int i,
sfVector2f pos)
{
    sfColor color = SELECTOR_COLOR;

    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
    pos, (sfVector2f) {50, 50}) && cw_graph->edit.register_selected == 0 &&
    cw_graph->edit.number_selected == false) {
        color = SELECTOR_COLOR_CLICKED;
        cw_graph->edit.register_selected = i + 1;
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
    draw_text(cw_graph, int_to_str(i + 1), 25,
    (sfVector2f) {18 + pos.x - (i > 8 ? 5 : 0), 9 + pos.y});
    (void)lc;
}

void draw_register(cw_graph_t *cw_graph, int line, int col, int i)
{
    sfVector2i mouse=sfMouse_getPositionRenderWindow(cw_graph->window->window);
    sfVector2f pos;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse &&
        cw_graph->is_released)
        cw_graph->edit.register_selected = 0;
    if (cw_graph->edit.register_selected != i + 1)
        pos = (sfVector2f) {615 + col * 130, 390 + line * 64};
    else
        pos = (sfVector2f) {(int)mouse.x - 20, (int)mouse.y - 20};
    draw_register_circle(cw_graph, (sfVector2f){line, col}, i, pos);
}

void draw_registers(cw_graph_t *cw_graph)
{
    int col = 0;
    int line = 0;

    for (int i = 0; i < REG_NUMBER; i++) {
        draw_register(cw_graph, line, col, i);
        col++;
        if (col == 4) {
            col = 0;
            line++;
        }
    }
}
