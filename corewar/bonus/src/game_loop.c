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
        switch (display_view(cw_graph, champions, memory, views[i]))
        {
        case 0: return (false);
            break;
        case 2: return (true);
            break;
        }
    return (true);
}

void set_truc_machin(proc_t **procs)
{
    for (int i = 0; procs[i]; i++) {
        procs[i]->pc->owner = procs[i]->champion->prog_number;
    }
}

bool launch_corewar(champion_t **champions, proc_t **procs, fct_t *fcts,
int cycle_per_tour)
{
    for (int i = 0; i < cycle_per_tour; i++)
        if (check_lives(champions, procs)) {
            if (!do_corewar_cycle(&procs, fcts))
                return (false);
            nbr_cycles++;
            set_truc_machin(procs);
        }
    return (true);
}

bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    proc_t **procs = init_processes(champions, memory);
    fct_t *fcts = init_fcts();
    view_t **views = views_fcts();

    if (procs == NULL)
        return (false);
    while (sfRenderWindow_isOpen(cw_graph->window->window)) {
        manage_events(cw_graph);
        evolve_gradient(&cw_graph->interface_gradient);
        if (cw_graph->g_setts.corewar_launched) {
            if (!launch_corewar(champions, procs, fcts, 100))
                return (false);
            if (!check_lives(champions, procs))
                cw_graph->current_view = 4;
        }
        if (!display_views(cw_graph, champions, memory, views))
            return (false);
        sfRenderWindow_display(cw_graph->window->window);
    }
    return (true);
}
