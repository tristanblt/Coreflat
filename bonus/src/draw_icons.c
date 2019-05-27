/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_icons
*/

#include "coreflat.h"
#include "my.h"

void draw_nb_cycle(cw_graph_t *cw_graph)
{
    sfSprite_setPosition(cw_graph->icons[2]->sprite,
    (sfVector2f) {1193, 420});
    sfSprite_setScale(cw_graph->icons[2]->sprite,
    (sfVector2f) {0.5, 0.5});
    sfRenderWindow_drawSprite(cw_graph->window->window,
    cw_graph->icons[2]->sprite, NULL);
    sfText_setString(cw_graph->text.text, "NB of cycles:");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1250, 425});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, int_to_str(nbr_cycles));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1450, 425});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_cycle_to_die(cw_graph_t *cw_graph)
{
    sfSprite_setPosition(cw_graph->icons[1]->sprite,
    (sfVector2f) {1190, 480});
    sfSprite_setScale(cw_graph->icons[1]->sprite,
    (sfVector2f) {0.6, 0.6});
    sfRenderWindow_drawSprite(cw_graph->window->window,
    cw_graph->icons[1]->sprite, NULL);
    sfText_setString(cw_graph->text.text, "Cycle to die:");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1250, 485});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, int_to_str(cycle_to_die));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1450, 485});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_all_processes(cw_graph_t *cw_graph)
{
    sfSprite_setPosition(cw_graph->icons[3]->sprite,
    (sfVector2f) {1190, 540});
    sfSprite_setScale(cw_graph->icons[3]->sprite,
    (sfVector2f) {0.6, 0.6});
    sfRenderWindow_drawSprite(cw_graph->window->window,
    cw_graph->icons[3]->sprite, NULL);
    sfText_setString(cw_graph->text.text, "All processes:");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {1250, 545});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text,
    int_to_str(count_process(cw_graph->g_setts.procs, -1)));
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {1450, 545});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_champion_line(cw_graph_t *cw_graph, champion_t **champions,
int i, bool dead)
{
    sfText_setColor(cw_graph->text.text, dead ? sfRed : sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, "Processes:");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1260, 160 + i * 60});
    sfText_setCharacterSize(cw_graph->text.text, 13);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text,
    int_to_str(count_process(cw_graph->g_setts.procs,
    champions[i]->prog_number)));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1340, 160 + i * 60});
    sfText_setCharacterSize(cw_graph->text.text, 14);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_icons(cw_graph_t *cw_graph, champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        sfSprite_setColor(cw_graph->icons[0]->sprite, (sfColor)
        {champions[i]->color.r, champions[i]->color.g,
            champions[i]->color.b, 255});
        sfSprite_setPosition(cw_graph->icons[0]->sprite,
        (sfVector2f) {1190, 130 + i * 60});
        sfSprite_setScale(cw_graph->icons[0]->sprite,
        (sfVector2f) {0.6, 0.6});
        sfRenderWindow_drawSprite(cw_graph->window->window,
        cw_graph->icons[0]->sprite, NULL);
        sfText_setString(cw_graph->text.text, champions[i]->header->prog_name);
        sfText_setPosition(cw_graph->text.text, (sfVector2f)
        {1250, 135 + i * 60});
        sfText_setCharacterSize(cw_graph->text.text, 20);
        draw_champion_line(cw_graph, champions, i, champions[i]->dead);
    }
    draw_nb_cycle(cw_graph);
    draw_cycle_to_die(cw_graph);
    draw_all_processes(cw_graph);
}