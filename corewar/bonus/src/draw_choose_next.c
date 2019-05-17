/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_choose_next
*/

#include "coreflat.h"

void draw_choose_champion(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "How many champions ?");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {490, 300});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_selector(cw_graph, (sfVector2i) {2, 4}, (sfVector2f) {640, 400},
    &cw_graph->g_setts.nb_champions);
}

void draw_choose_cyc_per_sec(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text,
    "How many cycles per second ?\n     (x = (x * x) * 120 cycles/sec)");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {410, 230});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_selector(cw_graph, (sfVector2i) {1, 9}, (sfVector2f) {640, 400},
    &cw_graph->g_setts.acceleration);
}

void draw_choose_cyc_auto(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "Automatic cycle per second ?");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {510, 420});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_checkbox(cw_graph, (sfVector2f) {350, 400},
    &cw_graph->g_setts.automatic_cps);
}

void draw_ready_to_start(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "Ready to start ?");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {600, 420});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}
