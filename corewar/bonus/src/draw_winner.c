/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_winner
*/

#include "coreflat.h"

bool draw_winner(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    char *name = NULL;
    bool biggest = true;

    memory = (void *)memory;
    for (int i = 0; cw_graph->g_setts.champions[i]; i++) {
        biggest = true;
        for (int j = 0; cw_graph->g_setts.champions[j]; j++)
            cw_graph->g_setts.champions[i]->last_live > cw_graph->g_setts.champions[j]->last_live ?
            biggest = false : 0;
        if (biggest) {
            name = cw_graph->g_setts.champions[i]->header->prog_name;
            break;
        }
    }
    /* sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {0, 0}); */
    /* sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1600, 900}); */
    /* sfRectangleShape_setFillColor(cw_graph->interface, BACKGROUND_COLOR); */
    /* sfRenderWindow_drawRectangleShape(cw_graph->window->window, */
    /* cw_graph->interface, NULL); */
    sfText_setString(cw_graph->text.text, name);
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {770, 410});
    sfText_setCharacterSize(cw_graph->text.text, 60);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, "The winner is: ");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {300, 410});
    sfText_setCharacterSize(cw_graph->text.text, 60);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    return (true);
}
