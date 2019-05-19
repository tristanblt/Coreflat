/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** init_game
*/

#include "coreflat.h"

view_t *set_fct(int view, bool (*fct)(cw_graph_t *cw_graph,
champion_t **champions, list_t *memory))
{
    view_t *init = malloc(sizeof(view_t));

    init->view = view;
    init->fct = fct;
    return (init);
}

view_t **views_fcts(void)
{
    view_t **views = malloc((NBR_VIEWS + 1) * sizeof(view_t));

    if (views == NULL)
        return (NULL);
    views[0] = set_fct(0, draw_main_menu);
    views[1] = set_fct(1, draw_help);
    views[2] = set_fct(2, draw_choose);
    views[3] = set_fct(3, draw_corewar);
    views[4] = set_fct(4, draw_winner);
    views[5] = set_fct(5, draw_credits);
    views[6] = set_fct(6, draw_settings);
    views[7] = set_fct(7, draw_editor);
    views[8] = set_fct(8, draw_visualiser);
    views[NBR_VIEWS] = NULL;
    return (views);
}
