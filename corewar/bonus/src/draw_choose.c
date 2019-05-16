/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** menu_choose
*/

#include "coreflat.h"

bool draw_selector_button(cw_graph_t *cw_graph, sfVector2f pos)
{
    bool ret = false;

    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) && cw_graph->is_released) {
        ret = true;
    }
    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) && sfMouse_isButtonPressed(sfMouseLeft))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_CLICKED);
    else if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_HOVER);
    else
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {pos.x, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {100, 100});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    return (ret);
}

void draw_selector(cw_graph_t *cw_graph, sfVector2i limiter, sfVector2f pos, int *value)
{
    if (draw_selector_button(cw_graph, (sfVector2f){pos.x, pos.y}) && *value > limiter.x)
        (*value)--;
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {pos.x + 100, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {100, 100});
    sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_MIDDLE_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfText_setString(cw_graph->text.text, int_to_str(*value));
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 100 + 35, pos.y + 15});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    if (draw_selector_button(cw_graph, (sfVector2f){pos.x + 200, pos.y}) && *value < limiter.y)
        (*value)++;
    sfText_setString(cw_graph->text.text, "-");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 35, pos.y + 15});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    sfText_setString(cw_graph->text.text, "+");
    sfText_setPosition(cw_graph->text.text, (sfVector2f)
    {pos.x + 200 + 35, pos.y + 15});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_checkbox(cw_graph_t *cw_graph, sfVector2f pos, bool *value)
{
    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) && cw_graph->is_released) {
        *value = !(*value);
        cw_graph->g_setts.pass_step += *value ? 1 : -1;
    }
    if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}) && sfMouse_isButtonPressed(sfMouseLeft))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_CLICKED);
    else if (is_in_rect(cw_graph, pos, (sfVector2f) {100, 100}))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_HOVER);
    else
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {pos.x, pos.y});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {100, 100});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    if (*value) {
        sfText_setString(cw_graph->text.text, "X");
        sfText_setPosition(cw_graph->text.text, (sfVector2f)
        {pos.x + 27, pos.y});
        sfText_setCharacterSize(cw_graph->text.text, 80);
        sfText_setColor(cw_graph->text.text, sfWhite);
        sfRenderWindow_drawText(cw_graph->window->window,
        cw_graph->text.text, NULL);
    }
}

void draw_choose_champion(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "How many champions ?");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {490, 300});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_selector(cw_graph, (sfVector2i) {2, 4}, (sfVector2f) {640, 400}, &cw_graph->g_setts.nb_champions);
}

void draw_choose_cyc_per_sec(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "How many cycles per second ? (1 = 1000 cycles/sec)");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {160, 300});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_selector(cw_graph, (sfVector2i) {1, 9}, (sfVector2f) {640, 400}, &cw_graph->g_setts.cycles_per_second);
}

void draw_choose_cyc_auto(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "Automatic cycle per second ?");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {510, 420});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    draw_checkbox(cw_graph, (sfVector2f) {350, 400}, &cw_graph->g_setts.automatic_cps);
}

bool draw_choose(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    champions = (void *)champions;
    memory = (void *)memory;
    cw_graph = (void *)cw_graph;
    draw_background(cw_graph);
    switch (cw_graph->g_setts.step)
    {
    case 0: draw_choose_champion(cw_graph);
        break;
    case 1: draw_choose_cyc_auto(cw_graph);
        break;
    case 2: draw_choose_cyc_per_sec(cw_graph);
        break;
    }
    draw_button(cw_graph, (sfVector2f) {710, 600}, cw_graph->interface_gradient, NEXT_TEXT);
    return (true);
}