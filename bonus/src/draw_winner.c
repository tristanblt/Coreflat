/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_winner
*/

#include "coreflat.h"

void draw_winner_background(cw_graph_t *cw_graph)
{
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1600, 80});
    sfRectangleShape_setFillColor(cw_graph->interface, SUBWINDOW_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {1170, 80});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {430, 820});
    sfRectangleShape_setFillColor(cw_graph->interface, SUBWINDOW_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
}

void draw_winner_text(cw_graph_t *cw_graph, char *name, sfColor color)
{
    sfText_setString(cw_graph->text.text, name);
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {500, 0});
    sfText_setCharacterSize(cw_graph->text.text, 60);
    sfText_setColor(cw_graph->text.text, color);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, "The winner is: ");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {50, 0});
    sfText_setCharacterSize(cw_graph->text.text, 60);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_winner_all(cw_graph_t *cw_graph, char *name, sfColor color)
{
    draw_winner_background(cw_graph);
    draw_winner_text(cw_graph, name, color);
    draw_button(cw_graph, (sfVector2f){1310, 400},
    cw_graph->interface_gradient, MAIN_MENU_RES_TEXT);
    draw_button(cw_graph, (sfVector2f){1310, 520},
    cw_graph->interface_gradient, EXIT_TEXT);
}

void find_winner(cw_graph_t *cw_graph, bool *biggest, int i)
{
    *biggest = true;
    for (int j = 0; cw_graph->g_setts.champions[j]; j++)
        cw_graph->g_setts.champions[i]->last_live >
        cw_graph->g_setts.champions[j]->last_live ?
    *biggest = false : 0;
}

bool draw_winner(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    char *name = NULL;
    bool biggest = true;
    sfColor color;
    champion_t *c;

    memory = (void *)memory;
    champions = (void *)champions;
    for (int i = 0; cw_graph->g_setts.champions[i]; i++) {
        c = cw_graph->g_setts.champions[i];
        find_winner(cw_graph, &biggest, i);
        if (biggest) {
            name = c->header->prog_name;
            color = (sfColor) {c->color.r, c->color.g, c->color.b, 255};
            break;
        }
    }
    draw_winner_all(cw_graph, name, color);
    return (true);
}
