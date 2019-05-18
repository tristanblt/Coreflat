/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** redirections
*/

#include "coreflat.h"
#include "my.h"

void reset_g_setts(cw_graph_t *cw_graph)
{
    cycle_to_die = CYCLE_TO_DIE;
    nbr_cycles = 0;
    nbr_lives = 0;
    cw_graph->g_setts.step = 0;
    cw_graph->g_setts.champ_step = 0;
    cw_graph->g_setts.corewar_launched = false;
    cw_graph->g_setts.nb_champions = 2;
    cw_graph->g_setts.cycles_per_second = 1;
    cw_graph->g_setts.acceleration = 1;
    cw_graph->g_setts.champ_added = 0;
    cw_graph->g_setts.pass_step = 1;
    cw_graph->g_setts.automatic_cps = false;
    cw_graph->g_setts.color = (sfColor) {0};
    cw_graph->g_setts.champions = malloc(sizeof(champion_t *));
    cw_graph->g_setts.champions[0] = NULL;
}

void redirection_next(cw_graph_t *cw_graph, char *to)
{
    if (my_strcmp(to, PAUSE_TEXT))
        cw_graph->g_setts.corewar_launched = false;
    if (my_strcmp(to, PLAY_TEXT))
        cw_graph->g_setts.corewar_launched = true;
    if (my_strcmp(to, SETTINGS_TEXT))
        cw_graph->current_view = 6;
    if (my_strcmp(to, EDITOR_TEXT))
        cw_graph->current_view = 7;
    if (my_strcmp(to, CHANGE_TYPE_TEXT))
        cw_graph->edit.indirect_type = !cw_graph->edit.indirect_type;
    if (my_strcmp(to, LOAD_TEXT))
        cw_graph->edit.step = 1;
    if (my_strcmp(to, CREATE_CHAMPION))
        cw_graph->edit.step = 2;
    if (my_strcmp(to, EDIT_CHAMP_TEXT))
        cw_graph->edit.step = 3;
    if (my_strcmp(to, VALIDATE_CHAMPION) && cw_graph->edit.selected != -1)
        cw_graph->edit.step = 4;
}

void redirection(cw_graph_t *cw_graph, char *to)
{
    if (my_strcmp(to, BEGIN_TEXT))
        cw_graph->current_view = 2;
    if (my_strcmp(to, HELP_TEXT))
        cw_graph->current_view = 1;
    if (my_strcmp(to, CREDITS_TEXT))
        cw_graph->current_view = 5;
    if (my_strcmp(to, EXIT_TEXT))
        sfRenderWindow_close(cw_graph->window->window);
    if (my_strcmp(to, MAIN_MENU_TEXT))
        cw_graph->current_view = 0;
    if (my_strcmp(to, MAIN_MENU_RES_TEXT)) {
        reset_g_setts(cw_graph);
        cw_graph->current_view = 0;
    }
    if (my_strcmp(to, NEXT_TEXT)) {
        cw_graph->g_setts.step += cw_graph->g_setts.pass_step;
        cw_graph->g_setts.pass_step = 1;
    }
    redirection_next(cw_graph, to);
}
