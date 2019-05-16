/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** redirections
*/

#include "coreflat.h"
#include "my.h"

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
    if (my_strcmp(to, NEXT_TEXT))
        cw_graph->g_setts.step++;
}