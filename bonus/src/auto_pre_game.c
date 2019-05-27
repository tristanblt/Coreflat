/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** auto_pre_game
*/

#include "coreflat.h"

bool reset_game(cw_graph_t *cw_graph, list_t *memory)
{
    cw_graph->g_setts.cycles_per_second = nbr_cycles / 3600;
    if (cw_graph->g_setts.cycles_per_second == 0)
        cw_graph->g_setts.cycles_per_second = 1;
    nbr_cycles = 0;
    nbr_lives = 0;
    for (int i = 0; cw_graph->g_setts.champions[i]; i++) {
        cw_graph->g_setts.champions[i]->dead = false;
        cw_graph->g_setts.champions[i]->last_live = 0;
    }
    if (!(load_champion_instructions_in_mem(cw_graph->g_setts.champions,
        memory)))
        return (false);
    if (!(cw_graph->g_setts.procs =
        init_processes(cw_graph->g_setts.champions, memory)))
        return (false);
    cycle_to_die = CYCLE_TO_DIE;
    return (true);
}

bool auto_pre_game(cw_graph_t *cw_graph, list_t *memory)
{
    fct_t *fcts = init_fcts();

    fcts[0] = (fct_t) {live_flat, IC_live};
    fcts[15] = (fct_t) {aff_flat, IC_aff};
    while (1) {
        if (!check_lives(cw_graph->g_setts.champions, cw_graph->g_setts.procs))
            break;
        if (!do_corewar_cycle(&cw_graph->g_setts.procs, fcts))
            return (false);
        nbr_cycles++;
        set_proc_owner(cw_graph->g_setts.procs);
    }
    if (!reset_game(cw_graph, memory))
        return (false);
    return (true);
}