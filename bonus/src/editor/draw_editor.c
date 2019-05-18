/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_editor
*/

#include "coreflat.h"
#include "../asm/include/asm.h"

void draw_input_dir_ind(cw_graph_t *cw_graph)
{
    sfColor color = SELECTOR_COLOR;
    sfVector2i mouse = sfMouse_getPosition(cw_graph->window->window);
    sfVector2f pos;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
        cw_graph->edit.number_selected = false;
    if (cw_graph->edit.number_selected == false)
        pos = (sfVector2f) {580, 800};
    else
        pos = (sfVector2f) {(int)mouse.x - 20, (int)mouse.y - 20};
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_rect(cw_graph,
    pos, (sfVector2f) {50, 50}) && cw_graph->edit.number_selected == false &&
    cw_graph->edit.register_selected == 0) {
        color = SELECTOR_COLOR_CLICKED;
        cw_graph->edit.number_selected = true;
    }
    else if (is_in_rect(cw_graph, pos, (sfVector2f) {50, 50}))
        color = SELECTOR_COLOR_HOVE;
    else
        color = SELECTOR_COLOR;
    sfCircleShape_setPosition(cw_graph->buttons, pos);
    sfCircleShape_setRadius(cw_graph->buttons, 25);
    sfCircleShape_setFillColor(cw_graph->buttons, color);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    draw_text(cw_graph, "n", 25,
    (sfVector2f) {18 + pos.x, 9 + pos.y});

    draw_text(cw_graph, "Type:", 20, (sfVector2f) {700, 815});
    draw_text(cw_graph, (cw_graph->edit.indirect_type ? "Indirect" : "Direct"), 20, (sfVector2f) {780, 815});
    draw_button(cw_graph, (sfVector2f) {950, 800}, cw_graph->interface_gradient, CHANGE_TYPE_TEXT);
}

bool draw_edition(cw_graph_t *cw_graph)
{
    draw_background(cw_graph);
    draw_rect(cw_graph, (sfVector2f) {30, 160}, (sfVector2f) {500, 710},
    SUBWINDOW_COLOR);
    draw_champ_instructions(cw_graph);
    draw_editor_interface(cw_graph);
    if (!draw_all_instructions(cw_graph))
        return (false);
    draw_registers(cw_graph);
    draw_labels(cw_graph);
    draw_input_dir_ind(cw_graph);
    draw_input_bar_nb(cw_graph, (sfVector2f) {580, 710}, cw_graph->edit.buffer);
    return (true);
}

bool draw_editor(cw_graph_t *cw_graph, champion_t **champions, list_t *memory)
{
    memory = (void *)memory;
    if (cw_graph->edit.step == 0)
        draw_configuration(cw_graph);
    if (cw_graph->edit.step == 1 || cw_graph->edit.step == 4)
        if (!draw_select_champion(cw_graph, champions))
            return (false);
    if (cw_graph->edit.step == 2)
        draw_create_champion(cw_graph);
    if (cw_graph->edit.step == 3)
        if (!draw_edition(cw_graph))
            return (false);
    return (true);
}
