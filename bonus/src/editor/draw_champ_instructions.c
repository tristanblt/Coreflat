/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_champ_instructions
*/

#include "coreflat.h"

void display_hover_instruction(cw_graph_t *cw_graph, int i)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)cw_graph->window->window);
    int dec = 0;

    draw_rect(cw_graph, (sfVector2f) {(int)mouse.x, (int)mouse.y},
    (sfVector2f) {150, 180}, SELECTOR_COLOR);
    draw_text(cw_graph, op_tab[i].mnemonique, 40,
    (sfVector2f) {(int)mouse.x + 20, (int)mouse.y + 10});
    for (int j = 0; j < op_tab[i].nbr_args; j++) {
        if (op_tab[i].type[j] & T_REG) {
            draw_text(cw_graph, "Reg", 16,
            (sfVector2f) {(int)mouse.x + 20 + dec * 40, (int)mouse.y + 70 + j * 30});
            dec++;
        }
        if (op_tab[i].type[j] & T_DIR) {
            draw_text(cw_graph, "Dir", 16,
            (sfVector2f) {(int)mouse.x + 20 + dec * 40, (int)mouse.y + 70 + j * 30});
            dec++;
        }
        if (op_tab[i].type[j] & T_IND) {
            draw_text(cw_graph, "Ind", 16,
            (sfVector2f) {(int)mouse.x + 20 + dec * 35, (int)mouse.y + 70 + j * 30});
            dec++;
        }
        dec = 0;
    }
}

void draw_one_instruction(cw_graph_t *cw_graph, int i, int *hover)
{
    sfColor color = SUBWINDOW_COLOR;

    if (is_in_rect(cw_graph, (sfVector2f){1140, 30 + i * 39.3},
    (sfVector2f) {430, 39.3}) && cw_graph->is_released)
        printf("ADDING INSTRUCTION \"%s\"\n", op_tab[i].mnemonique);
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
    (sfVector2f){1140, 30 + i * 39.3}, (sfVector2f) {430, 39.3}))
        color = SELECTOR_COLOR_CLICKED;
    else if (is_in_rect(cw_graph, (sfVector2f){1140, 30 + i * 39.3},
    (sfVector2f) {430, 39.3})) {
        color = SELECTOR_COLOR_HOVE;
        *hover = i;
    }
    else
        color = SUBWINDOW_COLOR;
    draw_rect(cw_graph, (sfVector2f){1140, 30 + i * 39.3},
    (sfVector2f) {430, 39.3}, color);
    draw_text(cw_graph, op_tab[i].mnemonique, 20,
    (sfVector2f){1200, 37 + i * 39.3});
}

void draw_champ_instructions(cw_graph_t *cw_graph)
{
    int hover = -1;

    for (int i = 0; op_tab[i].code; i++)
        draw_one_instruction(cw_graph, i, &hover);
    if (hover != -1)
        display_hover_instruction(cw_graph, hover);
}