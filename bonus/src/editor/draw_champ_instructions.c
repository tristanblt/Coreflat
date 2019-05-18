/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_champ_instructions
*/

#include "coreflat.h"

void draw_args_instr(cw_graph_t *cw_graph, int i,
instruction_t *instruction)
{
    int dec = 0;

    for (int j = 0; j < op_tab[i].nbr_args; j++) {
        if (op_tab[instruction->code - 1].type[j] & T_REG) {
            draw_text(cw_graph, "Reg", 16,
            (sfVector2f) {180 + dec * 40 + j * 100, 170 + i * 39.3 + cw_graph->edit.cursor});
            dec++;
        }
        if (op_tab[instruction->code - 1].type[j] & T_DIR) {
            draw_text(cw_graph, "Dir", 16,
            (sfVector2f) {180 + dec * 40 + j * 100, 170 + i * 39.3 + cw_graph->edit.cursor});
            dec++;
        }
        if (op_tab[instruction->code - 1].type[j] & T_IND) {
            draw_text(cw_graph, "Ind", 16,
            (sfVector2f) {180 + dec * 35 + j * 100, 170 + i * 39.3 + cw_graph->edit.cursor});
            dec++;
        }
        dec = 0;
    }
}

void draw_one_instruction_champ(cw_graph_t *cw_graph, int i,
instruction_t *instruction)
{
    sfColor color = SUBWINDOW_COLOR;

    /*if (is_in_rect(cw_graph, (sfVector2f){1140, 30 + i * 39.3},
    (sfVector2f) {430, 39.3}) && cw_graph->is_released)
        printf("TOUCH INSTRUCTION \"%s\"\n", op_tab[i].mnemonique);*/
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
}

void draw_champ_instructions(cw_graph_t *cw_graph)
{
    for (int i = 0; cw_graph->edit.instructions[i]; i++)
        draw_one_instruction_champ(cw_graph, i, cw_graph->edit.instructions[i]);
}