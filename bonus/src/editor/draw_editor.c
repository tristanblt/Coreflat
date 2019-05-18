/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_editor
*/

#include "coreflat.h"
#include "../asm/include/asm.h"

void draw_input_dir_ind(cw_graph_t *cw_graph)
{
    draw_text(cw_graph, "Type:", 20, (sfVector2f) {600, 815});
    draw_text(cw_graph, (cw_graph->edit.indirect_type ? "Indirect" : "Direct"), 20, (sfVector2f) {680, 815});
    draw_button(cw_graph, (sfVector2f) {910, 800}, cw_graph->interface_gradient, CHANGE_TYPE_TEXT);
}

void draw_edition(cw_graph_t *cw_graph)
{
    draw_background(cw_graph);
    draw_rect(cw_graph, (sfVector2f) {30, 160}, (sfVector2f) {500, 710},
    SUBWINDOW_COLOR);
    draw_champ_instructions(cw_graph);
    draw_editor_interface(cw_graph);
    draw_all_instructions(cw_graph);
    draw_registers(cw_graph);
    draw_labels(cw_graph);
    draw_input_dir_ind(cw_graph);
}

bool draw_editor(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    memory = (void *)memory;
    if (cw_graph->edit.step == 0)
        draw_configuration(cw_graph);
    if (cw_graph->edit.step == 1 || cw_graph->edit.step == 4)
        if (!draw_select_champion(cw_graph, champions))
            return (false);
    if (cw_graph->edit.step == 2)
        draw_create_champion(cw_graph);
    if (cw_graph->edit.step == 3)
        draw_edition(cw_graph);
    return (true);
}
