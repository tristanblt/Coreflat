/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_choose_next_2
*/

#include "coreflat.h"

void draw_champion_select(cw_graph_t *cw_graph, char *name, int i,
bool is_select)
{
    if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40},
        (sfVector2f) {500, 40}) && sfMouse_isButtonPressed(sfMouseLeft))
        sfRectangleShape_setFillColor(cw_graph->interface,
        SELECTOR_COLOR_CLICKED);
    else if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40},
        (sfVector2f) {500, 40}))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR);
    else
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_HOVE);
    if (is_select)
        sfRectangleShape_setFillColor(cw_graph->interface,
        cw_graph->interface_gradient);
    sfRectangleShape_setPosition(cw_graph->interface,
    (sfVector2f) {30, 95+i*40});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {500, 40});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    draw_text(cw_graph, name, 20, (sfVector2f) {60, 102 + i * 40});
}

void draw_champion_settings_next(cw_graph_t *cw_graph, color_t *color_select)
{
    draw_selector(cw_graph, (sfVector2i) {0, 9}, (sfVector2f) {1270, 150},
    &color_select->r);
    draw_selector(cw_graph, (sfVector2i) {0, 9}, (sfVector2f) {1270, 350},
    &color_select->g);
    draw_selector(cw_graph, (sfVector2i) {0, 9}, (sfVector2f) {1270, 550},
    &color_select->b);
    draw_text(cw_graph, "Red", 20, (sfVector2f) {1270, 100});
    draw_text(cw_graph, "Green", 20, (sfVector2f) {1270, 300});
    draw_text(cw_graph, "Blue", 20, (sfVector2f) {1270, 500});
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {1270, 700});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {300, 100});
    sfRectangleShape_setFillColor(cw_graph->interface, (sfColor)
    {color_select->r * 20 + 55, color_select->g * 20 + 55,
        color_select->b * 20 + 55, 255});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    cw_graph->g_setts.color = (sfColor) {color_select->r * 20 + 55,
        color_select->g * 20 + 55, color_select->b * 20 + 55, 255};

}

void draw_champion_settings(cw_graph_t *cw_graph, champion_t **champions,
int *select, color_t *color_select)
{
    draw_text(cw_graph, "Champion settings", 40, (sfVector2f) {600, 20});
    for (int i = 0; champions[i] && i < 19; i++) {
        if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40},
            (sfVector2f) {500, 40}) && cw_graph->is_released)
            *select = i;
        draw_champion_select(cw_graph, champions[i]->header->prog_name, i,
        *select == i ? true : false);
    }
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {530, 95});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1070, 805});
    sfRectangleShape_setFillColor(cw_graph->interface, BACKGROUND_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    draw_champion_settings_next(cw_graph, color_select);
}

void display_champion_dots(cw_graph_t *cw_graph)
{
    draw_button(cw_graph, (sfVector2f) {710, 800},
    cw_graph->interface_gradient, NEXT_CHAMP_TEXT);
    draw_text(cw_graph, "Champion", 15, (sfVector2f) {1330, 850});
    for (int i = 0; i < cw_graph->g_setts.nb_champions; i++) {
        if (i < cw_graph->g_setts.champ_added + 1)
            sfCircleShape_setFillColor(cw_graph->buttons,
            cw_graph->interface_gradient);
        else
            sfCircleShape_setFillColor(cw_graph->buttons,
            SELECTOR_MIDDLE_COLOR);
        sfCircleShape_setPosition(cw_graph->buttons,
        (sfVector2f) {1430 + i * 30, 850});
        sfCircleShape_setRadius(cw_graph->buttons, 10);
        sfRenderWindow_drawCircleShape(cw_graph->window->window,
        cw_graph->buttons, NULL);
    }
}

bool draw_champions_settings(cw_graph_t *cw_graph, champion_t **champions,
int *n)
{
    static int select = -1;
    static color_t color_select = (color_t) {7, 2, 4, 0};

    if (cw_graph->g_setts.nb_champions <= cw_graph->g_setts.champ_added)
        cw_graph->g_setts.step++;
    draw_champion_settings(cw_graph, champions, &select, &color_select);
    if (is_in_rect(cw_graph, (sfVector2f) {710 - 25, 800},
    (sfVector2f) {200, 50}) && cw_graph->is_released && select != -1) {
        champions[select]->color = (color_t) {cw_graph->g_setts.color.r,
            cw_graph->g_setts.color.g, cw_graph->g_setts.color.b, 255};
        champions[select]->prog_number = *n;
        (*n)++;
        if (!(cw_graph->g_setts.champions = push_champion(cw_graph->g_setts.
            champions, champion_dup(champions[select]))))
            return (false);
        select = -1;
        color_select = (color_t) {rand() % 10, rand() % 10, rand() % 10, 255};
        cw_graph->g_setts.champ_added++;
    }
    display_champion_dots(cw_graph);
    return (true);
}