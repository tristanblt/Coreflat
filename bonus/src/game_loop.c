/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** game_loop
*/

#include "coreflat.h"

int display_view(cw_graph_t *cw_graph, champion_t **champions, list_t *memory,
view_t *view)
{
    if (view->view == cw_graph->current_view) {
        if (!view->fct(cw_graph, champions, memory))
            return (false);
        return (2);
    }
    return (true);
}

bool display_views(cw_graph_t *cw_graph, champion_t **champions, list_t *memory,
view_t **views)
{
    for (int i = 0; views[i]; i++)
        switch (display_view(cw_graph, champions, memory, views[i])) {
        case 0: return (false);
            break;
        case 2: return (true);
            break;
        }
    return (true);
}

void set_proc_owner(proc_t **procs)
{
    for (int i = 0; procs[i]; i++) {
        procs[i]->pc->owner = procs[i]->champion->prog_number;
    }
}

bool launch_corewar(champion_t **champions, cw_graph_t *cw_graph, fct_t *fcts)
{
    champions = (void *)champions;
    if (!cw_graph->g_setts.corewar_launched)
        return (true);
    for (int i = 0; i < (cw_graph->g_setts.cycles_per_second *
    (cw_graph->g_setts.acceleration*cw_graph->g_setts.acceleration)); i++) {
        if (!check_lives(cw_graph->g_setts.champions,
        cw_graph->g_setts.procs)) {
            cw_graph->current_view = 4;
            cw_graph->g_setts.corewar_launched = false;
            break;
        }
        if (!do_corewar_cycle(&cw_graph->g_setts.procs, fcts))
            return (false);
        nbr_cycles++;
        set_proc_owner(cw_graph->g_setts.procs);
    }
    return (true);
}

bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    fct_t *fcts = init_fcts();
    view_t **views = views_fcts();

    fcts[0] = (fct_t) {live_flat, IC_live};
    fcts[15] = (fct_t) {aff_flat, IC_aff};
    cw_graph->visualiser.fct = fcts;
    while (sfRenderWindow_isOpen(cw_graph->window->window)) {
        manage_events(cw_graph);
        evolve_gradient(&cw_graph->interface_gradient);
        if (!launch_corewar(cw_graph->g_setts.champions, cw_graph, fcts))
            return (false);
        if (!display_views(cw_graph, champions, memory, views))
            return (false);
        sfRenderWindow_display(cw_graph->window->window);
    }
    return (true);
}
