/*
** EPITECH PROJECT, 2019
** draw visualisor
** File description:
** draw visualisor lets you see how your program works step by step
*/

#include "coreflat.h"
#include "corewar.h"

void draw_select_champion_visualiser(cw_graph_t *cw_graph, champion_t **champs)
{
    bool selected = false;

    for (int i = 0; champs[i] && i < 19; i++) {
        if (is_in_rect(cw_graph, (sfVector2f){30, 95 + i * 40},
            (sfVector2f){500, 40}) && cw_graph->is_released)
            cw_graph->visualiser.selected = i;
        if (cw_graph->visualiser.selected == i)
            selected = true;
        else
            selected = false;
        draw_champion_select(cw_graph, champs[i]->header->prog_name, i,
        selected);
    }
    draw_rect(cw_graph, (sfVector2f){530, 0}, (sfVector2f){1070, 900},
    BACKGROUND_COLOR);
    if (cw_graph->visualiser.selected != -1)
        draw_button(cw_graph, (sfVector2f){750, 800},
        cw_graph->interface_gradient, VISUALISE_TEXT);
    draw_button(cw_graph, (sfVector2f){1350, 800},
    cw_graph->interface_gradient, MAIN_MENU_TEXT);
}

void draw_visualiser_interface(cw_graph_t *cw_graph, champion_t **champs)
{
    draw_header(cw_graph);
    draw_subwindows(cw_graph);
    draw_icons(cw_graph, champs);
}

bool visualise_champion(cw_graph_t *cw_graph, list_t *memory)
{
    sfColor color = sfWhite;
    int col = 0;
    int line = 0;

    draw_visualiser_interface(cw_graph, cw_graph->g_setts.champions);
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
    for (int i = 0; i < 1; i++)
        if (!do_corewar_cycle(&cw_graph->g_setts.procs, cw_graph->visualiser.fct))
            return (false);
    nbr_cycles++;
    set_proc_owner(cw_graph->g_setts.procs);
    draw_button(cw_graph, (sfVector2f){1300, 800}, cw_graph->interface_gradient,
    EXIT_TEXT);
    return (true);
}

bool start_visualiser(cw_graph_t *cw_graph, champion_t **champs, bool *load,
list_t *memory)
{
    if (!(cw_graph->g_setts.champions = malloc(sizeof(champion_t *) * 2)) ||
        (!(cw_graph->g_setts.champions[0] =
        champion_dup(champs[cw_graph->visualiser.selected]))))
        return (false);
    cw_graph->g_setts.champions[1] = NULL;
    cw_graph->g_setts.champions[0]->color = (color_t){200, 200, 200, 255};
    if (!(cw_graph->g_setts.procs =
        init_processes(cw_graph->g_setts.champions, memory)))
        return (false);
    for (int i = 0; i < MEM_SIZE / 2; i++)
        cw_graph->g_setts.procs[0]->pc =
        cw_graph->g_setts.procs[0]->pc->next;
    cw_graph->g_setts.champions[0]->start_offset = MEM_SIZE / 2;
    load_champion_instructions_in_mem(cw_graph->g_setts.champions, memory);
    *load = false;
    return (true);
}

bool draw_visualiser(cw_graph_t *cw_graph, champion_t **champs, list_t *memory)
{
    fct_t *fcts = init_fcts();
    static bool load = true;

    if (!fcts)
        return (false);
    fcts[0] = (fct_t){live_flat, IC_live};
    fcts[15] = (fct_t){aff_flat, IC_aff};
    draw_background(cw_graph);
    if (cw_graph->visualiser.step && load)
        if (!start_visualiser(cw_graph, champs, &load, memory))
            return (false);
    if (!cw_graph->visualiser.step)
        draw_select_champion_visualiser(cw_graph, champs);
    else
        visualise_champion(cw_graph, memory);
    return (true);
}
