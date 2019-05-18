/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_configuration
*/

#include "coreflat.h"

bool fill_editor_with_empty_champion(editor_t *editor)
{
    editor->header = malloc(sizeof(header_t));
    editor->instructions = malloc(sizeof(instruction_t *));
    if (!editor->header || !editor->instructions)
        return (false);
    *editor->header = (header_t){0};
    *editor->instructions = NULL;
    return (true);
}

bool draw_create_champion(cw_graph_t *cw_graph)
{
    sfColor color = cw_graph->interface_gradient;

    if (!cw_graph->edit.header)
        if (!fill_editor_with_empty_champion(&cw_graph->edit))
            return (false);
    draw_background(cw_graph);
    draw_input_bar(cw_graph, (sfVector2f){500, 400},
    cw_graph->edit.header->prog_name);
    if (cw_graph->edit.header->prog_name[0])
        draw_button(cw_graph, (sfVector2f){700, 500}, color, EDIT_CHAMP_TEXT);
    return (true);
}

void draw_configuration(cw_graph_t *cw_graph)
{
    draw_background(cw_graph);
    draw_button(cw_graph, (sfVector2f){500, 400},
                cw_graph->interface_gradient, LOAD_TEXT);
    draw_button(cw_graph, (sfVector2f){900, 400},
                cw_graph->interface_gradient, CREATE_CHAMPION);
    draw_button(cw_graph, (sfVector2f){700, 600},
                cw_graph->interface_gradient, MAIN_MENU_TEXT);
}
