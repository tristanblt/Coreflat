/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_corewar
*/
#include "coreflat.h"

void draw_block(cw_graph_t *cw_graph, int col, int line, sfVector2i duo)
{
    sfColor color = (sfColor) {duo.y * 60, 150, 150, 255};

    if (duo.x == 0)
        color = (sfColor) {duo.y * 60, 150, 150, 160};
    if (duo.y == 0)
        color = (sfColor) {50, 50, 50, 255};
    sfRectangleShape_setPosition(cw_graph->interface,
    (sfVector2f) {col * 11 + 60, line * 11 + 140});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {6, 6});
    sfRectangleShape_setFillColor(cw_graph->interface, color);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

bool draw_corewar(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    int line = 0;
    int col = 0;

    draw_interface(cw_graph, cw_graph->g_setts.champions);
    for (int i = 0; i < MEM_SIZE; i++) {
        draw_block(cw_graph, col, line, (sfVector2i) {memory->val, memory->owner});
        memory = memory->next;
        col++;
        if (col == 96) {
            line++;
            col = 0;
        }
    }
    return (true);
}