/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_icons
*/

#include "coreflat.h"
#include "my.h"

void draw_icons(cw_graph_t *cw_graph, champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        sfSprite_setPosition(cw_graph->icons[0]->sprite,
        (sfVector2f) {1080, 130 + i * 60});
        sfSprite_setScale(cw_graph->icons[0]->sprite,
        (sfVector2f) {0.6, 0.6});
        sfRenderWindow_drawSprite(cw_graph->window->window,
        cw_graph->icons[0]->sprite, NULL);
        sfText_setString(cw_graph->text.text, champions[i]->header->prog_name);
        sfText_setPosition(cw_graph->text.text, (sfVector2f)
        {1140, 135 + i * 60});
        sfText_setCharacterSize(cw_graph->text.text, 20);
        sfText_setColor(cw_graph->text.text, sfWhite);
        sfRenderWindow_drawText(cw_graph->window->window,
        cw_graph->text.text, NULL);
    }
    sfSprite_setPosition(cw_graph->icons[2]->sprite,
    (sfVector2f) {1083, 420});
    sfSprite_setScale(cw_graph->icons[2]->sprite,
    (sfVector2f) {0.5, 0.5});
    sfRenderWindow_drawSprite(cw_graph->window->window,
    cw_graph->icons[2]->sprite, NULL);

    sfText_setString(cw_graph->text.text, "NB of cycles:");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1140, 425});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);

    sfText_setString(cw_graph->text.text, int_to_str(nbr_cycles));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1340, 425});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);


    sfSprite_setPosition(cw_graph->icons[1]->sprite,
    (sfVector2f) {1080, 480});
    sfSprite_setScale(cw_graph->icons[1]->sprite,
    (sfVector2f) {0.6, 0.6});
    sfRenderWindow_drawSprite(cw_graph->window->window,
    cw_graph->icons[1]->sprite, NULL);

    sfText_setString(cw_graph->text.text, "Cycle to die:");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1140, 485});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);

    sfText_setString(cw_graph->text.text, int_to_str(cycle_to_die));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {1340, 485});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}