/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_register
*/

#include "coreflat.h"

void draw_register(cw_graph_t *cw_graph, int line, int col, int i)
{
    sfColor color = SELECTOR_COLOR;

    if (is_in_rect(cw_graph, (sfVector2f) {615 + col * 130, 390 + line * 64},
    (sfVector2f) {50, 50}) && cw_graph->is_released)
        printf("SELECT REGISTER r%i\n", i + 1);
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
    (sfVector2f) {615 + col * 130, 390 + line * 64}, (sfVector2f) {50, 50}))
        color = SELECTOR_COLOR_CLICKED;
    else if (is_in_rect(cw_graph, (sfVector2f) {615 + col * 130, 390 + line * 64},
    (sfVector2f) {50, 50}))
        color = SELECTOR_COLOR_HOVE;
    else
        color = SELECTOR_COLOR;
    sfCircleShape_setPosition(cw_graph->buttons,
    (sfVector2f) {615 + col * 130, 390 + line * 64});
    sfCircleShape_setRadius(cw_graph->buttons, 25);
    sfCircleShape_setFillColor(cw_graph->buttons, color);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    draw_text(cw_graph, int_to_str(i + 1), 25,
    (sfVector2f) {633 + col * 130 - (i > 8 ? 5 : 0), 399 + line * 64});
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