/*
** EPITECH PROJECT, 2019
** draw one instruction champ
** File description:
** asd
*/

#include "coreflat.h"

void draw_one_instruction_champ_1(cw_graph_t *cw_graph, int i,
instruction_t *instruction, sfColor color)
{
    draw_rect(cw_graph, (sfVector2f){30, 160 + i*39.3 + cw_graph->edit.cursor},
    (sfVector2f) {500, 39.3}, color);
    draw_text(cw_graph, op_tab[instruction->code - 1].mnemonique, 20,
    (sfVector2f){150, 165 + i * 39.3 + cw_graph->edit.cursor});
    draw_label_instr(cw_graph, i, instruction);
    draw_args_instr(cw_graph, i, instruction);
    sfCircleShape_setFillColor(cw_graph->buttons, (sfColor){200, 50, 50, 255});
    sfCircleShape_setPosition(cw_graph->buttons, (sfVector2f){490, 165 + i *
        39.3 + cw_graph->edit.cursor});
    sfCircleShape_setRadius(cw_graph->buttons, 13);
    sfText_setPosition(cw_graph->text.text, (sfVector2f){498, 166 + i * 39.3 +
        cw_graph->edit.cursor});
    sfText_setString(cw_graph->text.text, "x");
    sfText_setColor(cw_graph->text.text, SUBWINDOW_COLOR);
    sfRenderWindow_drawCircleShape(cw_graph->window->window, cw_graph->buttons,
    NULL);
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text,
    NULL);
}

void draw_one_instruction_champ_2(cw_graph_t *cw_graph, int i)
{
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfText_setString(cw_graph->text.text, "V");
    sfText_setPosition(cw_graph->text.text, (sfVector2f){481, 177 + i * 39.3 +
        cw_graph->edit.cursor});
    sfText_setRotation(cw_graph->text.text, 180);
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text,
    NULL);
    sfText_setRotation(cw_graph->text.text, 0);
    sfText_setPosition(cw_graph->text.text, (sfVector2f){470, 177 + i * 39.3 +
        cw_graph->edit.cursor});
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text,
    NULL);
}

int draw_one_instruction_champ_3(cw_graph_t *cw_graph, int i)
{
    if (is_in_rect(cw_graph, (sfVector2f){495, 166 + i * 39.3 +
            cw_graph->edit.cursor}, (sfVector2f){26, 26}) &&
        cw_graph->is_released)
        return (1);
    draw_one_instruction_champ_2(cw_graph, i);
    if (is_in_rect(cw_graph, (sfVector2f){470, 160 + i * 39.3 +
            cw_graph->edit.cursor}, (sfVector2f){10, 10}) &&
        cw_graph->is_released)
        return (2);
    if (is_in_rect(cw_graph, (sfVector2f){470, 185 + i * 39.3 +
            cw_graph->edit.cursor}, (sfVector2f){10, 10}) &&
        cw_graph->is_released)
        return (3);
    return (0);

}

int draw_one_instruction_champ(cw_graph_t *cw_graph, int i,
instruction_t *instruction)
{
    sfColor color = SUBWINDOW_COLOR;

    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
        (sfVector2f){30, 160 + i * 39.3 + cw_graph->edit.cursor}, (sfVector2f)
        {500, 39.3}))
        color = SELECTOR_COLOR_CLICKED;
    else if (is_in_rect(cw_graph, (sfVector2f){30, 160 + i * 39.3 +
        cw_graph->edit.cursor},
    (sfVector2f) {500, 39.3})) {
        color = SELECTOR_COLOR_HOVE;
    } else
        color = SUBWINDOW_COLOR;
    draw_one_instruction_champ_1(cw_graph, i, instruction, color);
    return (draw_one_instruction_champ_3(cw_graph, i));
}
