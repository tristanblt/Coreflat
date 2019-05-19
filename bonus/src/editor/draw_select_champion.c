/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_select_champion
*/

#include "coreflat.h"
#include "disasm.h"

bool disasm_champion(cw_graph_t *cw_graph, champion_t **champions)
{
    instruction_t *to_add = NULL;

    cw_graph->edit.header = champions[cw_graph->edit.selected]->header;
    if (my_strlen(cw_graph->edit.header->prog_name) > 25)
        cw_graph->edit.header->prog_name[25] = 0;
    cw_graph->edit.instructions = malloc(sizeof(instruction_t *));
    if (!cw_graph->edit.instructions)
        return (NULL);
    cw_graph->edit.instructions[0] = NULL;
    for (int i = 0; i < cw_graph->edit.header->prog_size;) {
        if (!(to_add =
            parse_instruction_from_file(champions[cw_graph->edit.selected]->
            instructions, &i, cw_graph->edit.header->prog_size)))
            return (false);
        if (!(cw_graph->edit.instructions =
            push_instruction(cw_graph->edit.instructions, to_add)))
            return (false);
    }
    compute_instructions_sizes(cw_graph->edit.instructions);
    fill_label_args(cw_graph->edit.instructions);
    return ((cw_graph->edit.step = 3) % 1 + true);
}

bool draw_select_champion(cw_graph_t *cw_graph, champion_t **champions)
{
    if (cw_graph->edit.step == 4) {
        if (!disasm_champion(cw_graph, champions))
            return (false);
        return (true);
    }
    draw_background(cw_graph);
    for (int i = 0; champions[i] && i < 19; i++) {
        if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40},
            (sfVector2f) {500, 40}) && cw_graph->is_released)
            cw_graph->edit.selected = i;
        draw_champion_select(cw_graph, champions[i]->header->prog_name, i,
        cw_graph->edit.selected == i ? true : false);
    }
    draw_rect(cw_graph, (sfVector2f){530, 0}, (sfVector2f){1070, 900},
    BACKGROUND_COLOR);
    draw_button(cw_graph, (sfVector2f) {800, 780}, cw_graph->interface_gradient,
    VALIDATE_CHAMPION);
    return (true);
}
