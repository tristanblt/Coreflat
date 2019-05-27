/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** update_input
*/

#include "coreflat.h"

void update_input(cw_graph_t *cw_graph, char *str, int size)
{
    int len = my_strlen(str);
    sfKeyCode code = cw_graph->window->event.key.code;
    char alpha_offset = 'a';

    (code == sfKeyBack && len) ? str[len - 1] = 0 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        alpha_offset = 'A';
    if (len > size)
        return;
    if ((code >= sfKeyA && code <= sfKeyZ) ||
        (code >= sfKeyNum0 && code <= sfKeyNum9) ||
        code == sfKeySpace || code == 56)
        str[len + 1] = 0;
    if (code >= sfKeyA && code <= sfKeyZ)
        str[len] = alpha_offset + code;
    if (code >= sfKeyNum0 && code <= sfKeyNum9)
        str[len] = 22 + code;
    if (code == sfKeySpace)
        str[len] = ' ';
    if (code == 56)
        str[len] = '_';
}

void update_input_nb(cw_graph_t *cw_graph, char *str, int size)
{
    int len = my_strlen(str);
    sfKeyCode code = cw_graph->window->event.key.code;

    (code == sfKeyBack && len) ? str[len - 1] = 0 : 0;
    if (len > size)
        return;
    if (code >= sfKeyNum0 && code <= sfKeyNum9) {
        str[len] = 22 + code;
        str[len + 1] = 0;
    }
}