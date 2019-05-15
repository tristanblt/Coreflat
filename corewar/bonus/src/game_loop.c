/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** game_loop
*/

#include "coreflat.h"

bool display_views(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    switch (cw_graph->current_view)
    {
    case 0:
        if (!draw_corewar(cw_graph, champions, memory))
            return (false);
        break;
    case 1: draw_credits(cw_graph);
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

bool game_loop(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    proc_t **procs = init_processes(champions, memory);
    fct_t *fcts = init_fcts();
    int cycles = 0;

    if (procs == NULL)
        return (false);
    while (sfRenderWindow_isOpen(cw_graph->window->window)) {
        for (int i = 0; i < 25; i++) {
            if (check_lives(champions, procs)) {
                if (!do_corewar_cycle(&procs, fcts))
                    return (false);
                cycles++;
                nbr_cycles++;
                set_truc_machin(procs);
            }
        }
        manage_events(cw_graph);
        draw_interface(cw_graph, champions);
        if (!display_views(cw_graph, champions, memory))
            return (false);
        if (!check_lives(champions, procs))
            draw_winner(cw_graph, champions);
        sfRenderWindow_display(cw_graph->window->window);
    }
    return (true);
}