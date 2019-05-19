/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_champ_instructions
*/

#include "coreflat.h"
#include "my.h"

void draw_arg_instr(cw_graph_t *cw_graph, int i,
instruction_t *instruction, int j)
{
    int dec = 0;
    sfColor color = (sfColor) {255, 255, 255, 255};

    if (op_tab[instruction->code - 1].type[j] & T_REG) {
        draw_text_no_color(cw_graph, "R", 16,
        (sfVector2f) {160 + dec * 20 + j * 80, 170 + i * 39.3 + cw_graph->edit.cursor});
        dec++;
    }
    if (op_tab[instruction->code - 1].type[j] & T_DIR) {
        draw_text_no_color(cw_graph, "D", 16,
        (sfVector2f) {160 + dec * 20 + j * 80, 170 + i * 39.3 + cw_graph->edit.cursor});
        dec++;
    }
    if (op_tab[instruction->code - 1].type[j] & T_IND) {
        draw_text_no_color(cw_graph, "I", 16,
        (sfVector2f) {160 + dec * 20 + j * 80, 170 + i * 39.3 + cw_graph->edit.cursor});
        dec++;
    }
}

void draw_args_instr(cw_graph_t *cw_graph, int i,
instruction_t *instruction)
{
    for (int j = 0; j < op_tab[i].nbr_args; j++) {
        draw_arg_instr(cw_graph, i, instruction, j);
    }
}

void swap_instructions(instruction_t **inst_1, instruction_t **inst_2)
{
    instruction_t *tmp = *inst_1;

    *inst_1 = *inst_2;
    *inst_2 = tmp;
}

int draw_one_instruction_champ(cw_graph_t *cw_graph, int i,
instruction_t *instruction)
{
    sfColor color = SUBWINDOW_COLOR;

    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
    (sfVector2f){30, 160 + i * 39.3 + cw_graph->edit.cursor}, (sfVector2f) {500, 39.3}))
        color = SELECTOR_COLOR_CLICKED;
    else if (is_in_rect(cw_graph, (sfVector2f){30, 160 + i * 39.3 + cw_graph->edit.cursor},
    (sfVector2f) {500, 39.3})) {
        color = SELECTOR_COLOR_HOVE;
    }
    else
        color = SUBWINDOW_COLOR;
    draw_rect(cw_graph, (sfVector2f){30, 160 + i * 39.3 + cw_graph->edit.cursor},
    (sfVector2f) {500, 39.3}, color);
    draw_text(cw_graph, op_tab[instruction->code - 1].mnemonique, 20,
    (sfVector2f){60, 165 + i * 39.3 + cw_graph->edit.cursor});
    draw_args_instr(cw_graph, i, instruction);
    sfCircleShape_setFillColor(cw_graph->buttons, (sfColor){200, 50, 50, 255});
    sfCircleShape_setPosition(cw_graph->buttons, (sfVector2f){490, 165 + i * 39.3 + cw_graph->edit.cursor});
    sfCircleShape_setRadius(cw_graph->buttons, 13);
    sfText_setPosition(cw_graph->text.text, (sfVector2f){498, 166 + i * 39.3 + cw_graph->edit.cursor});
    sfText_setString(cw_graph->text.text, "x");
    sfText_setFillColor(cw_graph->text.text, SUBWINDOW_COLOR);
    sfRenderWindow_drawCircleShape(cw_graph->window->window, cw_graph->buttons, NULL);
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text, NULL);
    if (is_in_rect(cw_graph, (sfVector2f){495, 166 + i * 39.3 + cw_graph->edit.cursor}, (sfVector2f){26, 26}) && cw_graph->is_released)
        return (1);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfText_setString(cw_graph->text.text, "V");
    sfText_setPosition(cw_graph->text.text, (sfVector2f){481, 177 + i * 39.3 + cw_graph->edit.cursor});
    sfText_setRotation(cw_graph->text.text, 180);
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text, NULL);
    sfText_setRotation(cw_graph->text.text, 0);
    sfText_setPosition(cw_graph->text.text, (sfVector2f){470, 177 + i * 39.3 + cw_graph->edit.cursor});
    sfRenderWindow_drawText(cw_graph->window->window, cw_graph->text.text, NULL);
    if (is_in_rect(cw_graph, (sfVector2f){470, 160 + i * 39.3 + cw_graph->edit.cursor}, (sfVector2f){10, 10}) && cw_graph->is_released)
        return (2);
    if (is_in_rect(cw_graph, (sfVector2f){470, 185 + i * 39.3 + cw_graph->edit.cursor}, (sfVector2f){10, 10}) && cw_graph->is_released)
        return (3);
    return (0);
}

void remove_instruction(cw_graph_t *cw_graph, int *i, bool *removed)
{
    free(cw_graph->edit.instructions[*i]->description);
    free(cw_graph->edit.instructions[*i]->args);
    free(cw_graph->edit.instructions[*i]->label_args);
    free(cw_graph->edit.instructions[*i]);
    for (int j = *i; cw_graph->edit.instructions[j]; j++)
        cw_graph->edit.instructions[j] = cw_graph->edit.instructions[j + 1];
    (*i)--;
    (*removed) = true;
}

void draw_champ_instructions(cw_graph_t *cw_graph)
{
    bool removed = false;
    bool moved = false;
    int ret = 0;

    for (int i = 0; cw_graph->edit.instructions[i]; i++) {
        ret = draw_one_instruction_champ(cw_graph, i, cw_graph->edit.instructions[i]);
        if (ret == 1 && !removed)
            remove_instruction(cw_graph, &i, &removed);
        if (ret == 2 && !moved && i) {
            swap_instructions(&cw_graph->edit.instructions[i], &cw_graph->edit.instructions[i - 1]);
            moved = true;
        } else if (ret == 3 && !moved && cw_graph->edit.instructions[i + 1]) {
            swap_instructions(&cw_graph->edit.instructions[i], &cw_graph->edit.instructions[i + 1]);
            moved = true;
        }
    }
}
