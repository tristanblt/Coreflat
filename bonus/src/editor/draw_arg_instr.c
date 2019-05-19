/*
** EPITECH PROJECT, 2019
** draw arg instr
** File description:
** draw arg instr
*/

#include "coreflat.h"

bool can_drop(cw_graph_t *cw_graph, int i, instruction_t *instruction, int j)
{
    (void)i;
    if (cw_graph->edit.number_selected && cw_graph->edit.indirect_type)
        if (op_tab[instruction->code - 1].type[j] & T_IND)
            return (true);
    if (cw_graph->edit.number_selected && !cw_graph->edit.indirect_type)
        if (op_tab[instruction->code - 1].type[j] & T_DIR)
            return (true);
    if (cw_graph->edit.register_selected != 0)
        if (op_tab[instruction->code - 1].type[j] & T_REG)
            return (true);
    return (false);
}

void draw_arg_instr_3(cw_graph_t *cw_graph, int i,
instruction_t *instruction, sfVector2i new)
{
    if (instruction->description[new.x] == T_IND)
        draw_text(cw_graph, int_to_str(instruction->args[new.x]), 16,
        (sfVector2f) {220 + new.y * 20 + new.x * 80, 170 + i * 39.3 +
            cw_graph->edit.cursor});
    if (instruction->description[new.x] == T_DIR) {
        draw_text(cw_graph, "%", 16,
        (sfVector2f) {220 + new.y * 20 + new.x * 80, 170 + i * 39.3 +
            cw_graph->edit.cursor});
        draw_text(cw_graph, int_to_str(instruction->args[new.x]), 16,
        (sfVector2f) {240 + new.y * 20 + new.x * 80, 170 + i * 39.3 +
            cw_graph->edit.cursor});
    }
    if (instruction->description[new.x] == T_REG) {
        draw_text(cw_graph, "r", 16,
        (sfVector2f) {220 + new.y * 20 + new.x * 80, 170 + i * 39.3 +
            cw_graph->edit.cursor});
        draw_text(cw_graph, int_to_str(instruction->args[new.x]), 16,
        (sfVector2f) {230 + new.y * 20 + new.x * 80, 170 + i * 39.3 +
            cw_graph->edit.cursor});
    }
}

void draw_arg_instr_1(cw_graph_t *cw_graph,
instruction_t *instr, sfIntRect n, sfColor color)
{
    if (is_in_rect(cw_graph, (sfVector2f){220+n.width*20+n.top*80, 170+n.left*
            39.3 + cw_graph->edit.cursor}, (sfVector2f) {70, 20}) &&
        !can_drop(cw_graph, n.left, instr, n.top))
        color = (sfColor) {200, 20, 10, 255};
    else if (is_in_rect(cw_graph, (sfVector2f){220+n.width*20+n.top*80,
            170+n.left*39.3 + cw_graph->edit.cursor}, (sfVector2f) {70, 20}) &&
        can_drop(cw_graph, n.left, instr, n.top))
        color = (sfColor) {20, 200, 10, 255};
    draw_rect(cw_graph, (sfVector2f){220+n.width*20+n.top*80, 170+n.left*39.3+
        cw_graph->edit.cursor}, (sfVector2f) {70, 20}, color);
    sfText_setColor(cw_graph->text.text, color);
    if (instr->label_args[n.top]) {
        if (instr->description[n.top] == T_DIR)
            draw_text(cw_graph, "%", 13, (sfVector2f)
            {220+n.width*20+n.top*80, 170+n.left*39.3+cw_graph->edit.cursor});
        draw_text(cw_graph, instr->label_args[n.top], 13,
        (sfVector2f) {(instr->description[n.top] == T_DIR ? 235 : 220) +
            n.width * 20 + n.top * 80, 170+n.left*39.3+cw_graph->edit.cursor});
        return;
    } draw_arg_instr_3(cw_graph, n.left, instr, (sfVector2i){n.top, n.width});
}

void draw_arg_instr(cw_graph_t *cw_graph, int i,
instruction_t *instruction, int j)
{
    int dec = 0;
    sfColor color = SELECTOR_COLOR_CLICKED;

    if (is_in_rect(cw_graph, (sfVector2f) {220 + dec * 20 + j * 80, 170 + i *
        39.3 + cw_graph->edit.cursor}, (sfVector2f) {70, 20}) &&
    can_drop(cw_graph, i, instruction, j) && cw_graph->is_released &&
    cw_graph->edit.number_selected) {
        if (cw_graph->edit.number_selected == 1)
            instruction->args[j] = atoi(cw_graph->edit.buffer);
        else if (cw_graph->edit.number_selected == 2)
            instruction->label_args[j]=strdup(cw_graph->edit.buffer);
        instruction->description[j]=cw_graph->edit.indirect_type?T_IND:T_DIR;
    }
    else if (is_in_rect(cw_graph, (sfVector2f) {220 + dec * 20 + j * 80, 170+i*
        39.3 + cw_graph->edit.cursor}, (sfVector2f) {70, 20}) &&
    can_drop(cw_graph, i, instruction, j) && cw_graph->is_released &&
    cw_graph->edit.register_selected) {
        instruction->args[j] = cw_graph->edit.register_selected;
        instruction->description[j] = T_REG;
    } draw_arg_instr_1(cw_graph, instruction, (sfIntRect){i, j, dec, 0}, color);
}
