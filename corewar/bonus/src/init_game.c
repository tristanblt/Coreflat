/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_game
*/

#include "coreflat.h"

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    if (window == NULL)
        return (NULL);
    window->mode = (sfVideoMode) {1600, 900, 32};
    window->window = sfRenderWindow_create(window->mode, WINDOW_NAME,
    sfClose, NULL);
    if (window->window == NULL)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window->window, FRAMERATE_LIMIT);
    return (window);
}

icon_t *init_icon(char *path)
{
    icon_t *icon = malloc(sizeof(icon_t));

    if (icon == NULL)
        return (NULL);
    icon->texture = sfTexture_createFromFile(path, NULL);
    icon->sprite = sfSprite_create();
    if (icon->sprite == NULL || icon->texture == NULL)
        return (NULL);
    sfSprite_setTexture(icon->sprite, icon->texture, sfTrue);
    return (icon);
}

icon_t **init_icons(void)
{
    icon_t **icons = malloc(sizeof(icon_t *) * NBR_ICONS);

    if (icons == NULL)
        return (NULL);
    icons[0] = init_icon("bonus/assets/icons/trophy.png");
    icons[1] = init_icon("bonus/assets/icons/cemetery.png");
    icons[2] = init_icon("bonus/assets/icons/round-right-arrow.png");
    icons[NBR_ICONS] = NULL;
    for (int i = 0; icons[i]; i++)
        if (icons[i] == NULL)
            return (NULL);
    return (icons);
}

cw_graph_t *init_cw_graph(void)
{
    cw_graph_t *cw_graph = malloc(sizeof(cw_graph_t));

    if (cw_graph == NULL)
        return (false);
    if ((cw_graph->window = init_window()) == NULL)
        return (false);
    if ((cw_graph->interface = sfRectangleShape_create()) == NULL)
        return (false);
    if ((cw_graph->buttons = sfCircleShape_create()) == NULL)
        return (false);
    cw_graph->interface_gradient = (sfColor) {125, 150, 175, 255};
    cw_graph->text.font =
    sfFont_createFromFile("bonus/assets/fonts/montserrat.otf");
    cw_graph->text.text = sfText_create();
    if (cw_graph->text.font == NULL || cw_graph->text.text == NULL)
        return (NULL);
    sfText_setFont(cw_graph->text.text, cw_graph->text.font);
    if ((cw_graph->icons = init_icons()) == NULL)
        return (NULL);
    cw_graph->current_view = 0;
    return (cw_graph);
}