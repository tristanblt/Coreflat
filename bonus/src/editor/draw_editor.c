/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_editor
*/

#include "coreflat.h"

void draw_input_dir_ind(cw_graph_t *cw_graph)
{
    draw_text(cw_graph, "Type:", 20, (sfVector2f) {600, 815});
    draw_text(cw_graph, (cw_graph->edit.indirect_type ? "Indirect" : "Direct"), 20, (sfVector2f) {680, 815});
    draw_button(cw_graph, (sfVector2f) {910, 800}, cw_graph->interface_gradient, CHANGE_TYPE_TEXT);
}

void draw_edition(cw_graph_t *cw_graph)
{
    draw_editor_interface(cw_graph);
    draw_all_instructions(cw_graph);
    draw_registers(cw_graph);
    draw_input_dir_ind(cw_graph);
}

bool draw_editor(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    cw_graph->edit.step = 5;
    if (cw_graph->edit.step < 5)
        draw_configuration(cw_graph);
    else
        draw_edition(cw_graph);
    return (true);
}