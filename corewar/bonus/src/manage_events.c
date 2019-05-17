/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** manage_events
*/

#include "coreflat.h"

void is_released(cw_graph_t *cw_graph)
{
    static bool is_pressed = false;

    if (cw_graph->is_released)
        cw_graph->is_released = false;
    if (is_pressed == true && !sfMouse_isButtonPressed(sfMouseLeft))
        cw_graph->is_released = true;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        is_pressed = true;
    else
        is_pressed = false;
}

void manage_events(cw_graph_t *cw_graph)
{
    while (sfRenderWindow_pollEvent(cw_graph->window->window,
        &cw_graph->window->event))
        if (cw_graph->window->event.type == sfEvtClosed)
            sfRenderWindow_close(cw_graph->window->window);
    sfMusic_setVolume(cw_graph->music, cw_graph->g_setts.volume * 10);
    is_released(cw_graph);
}