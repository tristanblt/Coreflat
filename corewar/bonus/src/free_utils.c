/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** free_utils
*/

#include "coreflat.h"

void free_end(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    clear_list(memory);
    sfMusic_destroy(cw_graph->music);
    sfText_destroy(cw_graph->text.text);
    sfFont_destroy(cw_graph->text.font);
    sfRenderWindow_destroy(cw_graph->window->window);
    free(cw_graph->window);
    sfRectangleShape_destroy(cw_graph->interface);
    sfCircleShape_destroy(cw_graph->buttons);
    destroy_champions(cw_graph->g_setts.champions);
    destroy_champions(champions);
    for (int i = 0; cw_graph->icons[i]; i++) {
        sfSprite_destroy(cw_graph->icons[i]->sprite);
        sfTexture_destroy(cw_graph->icons[i]->texture);
        free(cw_graph->icons[i]);
    }
    free(cw_graph->icons);
    free(cw_graph);
}