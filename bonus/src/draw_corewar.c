/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_corewar
*/
#include "coreflat.h"

void draw_block(cw_graph_t *cw_graph, int col, int line, sfColor color)
{
    sfRectangleShape_setPosition(cw_graph->interface,
    (sfVector2f) {col * 11 + 60, line * 11 + 140});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {6, 6});
    sfRectangleShape_setFillColor(cw_graph->interface, color);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

sfColor find_color(champion_t **champions, list_t *memory)
{
    sfColor color;
    int opacity = memory->val == 0 ? 160 : 255;
    champion_t *c = NULL;

    if (memory->owner == 0)
        return ((sfColor){50, 50, 50, 255});
    for (int i = 0; champions[i]; i++) {
        c = champions[i];
        if (c->prog_number == memory->owner)
            color = (sfColor) {c->color.r, c->color.g, c->color.b, opacity};
    }
    return (color);
}

int count_process(proc_t **procs, int n)
{
    int count = 0;

    for (int i = 0; procs[i]; i++) {
        if (n == -1) {
            count++;
            continue;
        }
        if (procs[i]->champion->prog_number == n)
            count++;
    }
    return (count);
}

bool draw_corewar(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    int line = 0;
    int col = 0;
    sfColor color;

    champions = (void *)champions;
    draw_interface(cw_graph, cw_graph->g_setts.champions);
    draw_selector(cw_graph, (sfVector2i) {1, 9}, (sfVector2f) {1220, 720},
    &cw_graph->g_setts.acceleration);
    for (int i = 0; i < MEM_SIZE; i++) {
        color = find_color(cw_graph->g_setts.champions, memory);
        draw_block(cw_graph, col, line, color);
        memory = memory->next;
        col++;
        if (col == 96) {
            line++;
            col = 0;
        }
    }
    if (!cw_graph->g_setts.corewar_launched)
        draw_pause(cw_graph);
    return (true);
}