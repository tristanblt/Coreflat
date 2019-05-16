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

void draw_ready_to_start(cw_graph_t *cw_graph)
{
    sfText_setString(cw_graph->text.text, "Ready to start ?");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {600, 420});
    sfText_setCharacterSize(cw_graph->text.text, 50);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_champion_line(cw_graph_t *cw_graph, char *name, int i, bool is_select)
{
    if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40}, (sfVector2f) {500, 40}) && sfMouse_isButtonPressed(sfMouseLeft))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_CLICKED);
    else if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40}, (sfVector2f) {500, 40}))
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR);
    else
        sfRectangleShape_setFillColor(cw_graph->interface, SELECTOR_COLOR_HOVER);
    if (is_select)
        sfRectangleShape_setFillColor(cw_graph->interface, cw_graph->interface_gradient);
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {30, 95 + i * 40});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {500, 40});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    sfText_setString(cw_graph->text.text, name);
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {60, 102 + i * 40});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
}

void draw_champion_settings(cw_graph_t *cw_graph, champion_t **champions, int *select)
{
    static int red = 0;
    static int green = 0;
    static int blue = 0;

    sfText_setString(cw_graph->text.text, "Champion settings");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {600, 20});
    sfText_setCharacterSize(cw_graph->text.text, 40);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    for (int i = 0; champions[i] && i < 19; i++) {
        if (is_in_rect(cw_graph, (sfVector2f) {30, 95 + i * 40}, (sfVector2f) {500, 40}) && cw_graph->is_released)
            *select = i;
        draw_champion_line(cw_graph, champions[i]->header->prog_name, i, *select == i ? true : false);
    }
    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {530, 95});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {1070, 805});
    sfRectangleShape_setFillColor(cw_graph->interface, BACKGROUND_COLOR);
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    draw_selector(cw_graph, (sfVector2i) {0, 9}, (sfVector2f) {1270, 150}, &red);
    draw_selector(cw_graph, (sfVector2i) {0, 9}, (sfVector2f) {1270, 350}, &green);
    draw_selector(cw_graph, (sfVector2i) {0, 9}, (sfVector2f) {1270, 550}, &blue);

    sfText_setString(cw_graph->text.text, "Red");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {1270, 100});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);

    sfText_setString(cw_graph->text.text, "Green");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {1270, 300});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);

    sfText_setString(cw_graph->text.text, "Blue");
    sfText_setPosition(cw_graph->text.text, (sfVector2f) {1270, 500});
    sfText_setCharacterSize(cw_graph->text.text, 20);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);

    sfRectangleShape_setPosition(cw_graph->interface, (sfVector2f) {1270, 700});
    sfRectangleShape_setSize(cw_graph->interface, (sfVector2f) {300, 100});
    sfRectangleShape_setFillColor(cw_graph->interface, (sfColor)
    {red * 20, green * 20, blue * 20, 255});
    sfRenderWindow_drawRectangleShape(cw_graph->window->window,
    cw_graph->interface, NULL);
    cw_graph->g_setts.color = (sfColor) {red * 20, green * 20, blue * 20, 255};
}

bool draw_champions_settings(cw_graph_t *cw_graph, champion_t **champions)
{
    static int select = -1;
    static int n_added = 0;

    if (cw_graph->g_setts.nb_champions <= n_added)
        cw_graph->g_setts.step++;
    draw_champion_settings(cw_graph, champions, &select);
    if (is_in_rect(cw_graph, (sfVector2f) {710 - 25, 800},
    (sfVector2f) {200, 50}) && cw_graph->is_released && select != -1) {
        champions[select]->color = (color_t) {cw_graph->g_setts.color.r,
        cw_graph->g_setts.color.g, cw_graph->g_setts.color.b, 255};
        if (!(cw_graph->g_setts.champions =
        push_champion(cw_graph->g_setts.champions, champion_dup(champions[select]))))
            return (false);
        select = -1;
        n_added++;
    }
    draw_button(cw_graph, (sfVector2f) {710, 800}, cw_graph->interface_gradient,
        NEXT_CHAMP_TEXT);
    return (true);
}

bool draw_choose(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    draw_background(cw_graph);
    if (cw_graph->g_setts.step == 5) {
        if (!(load_champion_instructions_in_mem(cw_graph->g_setts.champions, memory)))
            return (false);
        if (!(cw_graph->g_setts.procs = init_processes(cw_graph->g_setts.champions, memory)))
            return (false);
        cw_graph->g_setts.corewar_launched = true;
        cw_graph->current_view = 3;
    }
    switch (cw_graph->g_setts.step)
    {
    case 0: draw_choose_champion(cw_graph);
        break;
    case 1: draw_choose_cyc_auto(cw_graph);
        break;
    case 2: draw_choose_cyc_per_sec(cw_graph);
        break;
    case 3:
        if (!draw_champions_settings(cw_graph, champions))
            return (false);
        break;
    case 4: draw_ready_to_start(cw_graph);
        break;
    }
    if (cw_graph->g_setts.step != 3)
        draw_button(cw_graph, (sfVector2f) {710, 600},
        cw_graph->interface_gradient, NEXT_TEXT);
    return (true);
}