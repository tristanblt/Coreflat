/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_configuration
*/

#include "coreflat.h"

champion_t *create_empty_champion(void)
{
}

bool draw_create_champion(cw_graph_t *cw_graph)
{
    header_t *header = malloc(sizeof(header_t));
    instruction_t **insts = malloc(sizeof(instruction_t *));

    if (!header || !insts)
        return (false);
    *header = (header_t){0};
    insts[0] = NULL;
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
