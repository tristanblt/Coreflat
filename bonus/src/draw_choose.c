/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** menu_choose
*/

#include "coreflat.h"

void draw_step_dots(cw_graph_t *cw_graph)
{
    draw_text(cw_graph, "Progress", 15, (sfVector2f) {1330, 30});
    for (int i = 0; i < 5; i++) {
        if (i < cw_graph->g_setts.step + 1)
            sfCircleShape_setFillColor(cw_graph->buttons,
            cw_graph->interface_gradient);
        else
            sfCircleShape_setFillColor(cw_graph->buttons,
            SELECTOR_MIDDLE_COLOR);
        sfCircleShape_setPosition(cw_graph->buttons,
        (sfVector2f) {1430 + i * 30, 30});
        sfCircleShape_setRadius(cw_graph->buttons, 10);
        sfRenderWindow_drawCircleShape(cw_graph->window->window,
        cw_graph->buttons, NULL);
    }
    if (cw_graph->g_setts.step != 3 && cw_graph->g_setts.step != 5)
        draw_button(cw_graph, (sfVector2f) {710, 600},
        cw_graph->interface_gradient, NEXT_TEXT);
    if (cw_graph->g_setts.step < 3)
        draw_button(cw_graph, (sfVector2f) {710, 670},
        cw_graph->interface_gradient, MAIN_MENU_TEXT_B);
}

bool dispacht_steps(cw_graph_t *cw_graph, champion_t **champions, int *n)
{
    switch (cw_graph->g_setts.step) {
    case 0: draw_choose_champion(cw_graph);
        break;
    case 1: draw_choose_cyc_auto(cw_graph);
        break;
    case 2: draw_choose_cyc_per_sec(cw_graph);
        break;
    case 3:
        if (!draw_champions_settings(cw_graph, champions, n))
            return (false);
        break;
    case 4: draw_ready_to_start(cw_graph);
        break;
    }
    draw_step_dots(cw_graph);
    return (true);
}

bool draw_choose(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    static int n = 1;

    draw_background(cw_graph);
    if (cw_graph->g_setts.step == 5) {
        if (!(load_champion_instructions_in_mem(cw_graph->g_setts.champions,
            memory)))
            return (false);
        if (!(cw_graph->g_setts.procs =
            init_processes(cw_graph->g_setts.champions, memory)))
            return (false);
        cw_graph->g_setts.corewar_launched = true;
        cw_graph->current_view = 3;
        n = 1;
        if (!cw_graph->g_setts.automatic_cps)
            return (true);
        if (!(auto_pre_game(cw_graph, memory)))
            return (false);
    }
    if (!dispacht_steps(cw_graph, champions, &n))
        return (false);
    return (true);
}