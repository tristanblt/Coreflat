/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** draw_champ_instructions
*/

#include "coreflat.h"
#include "my.h"

void swap_instructions(instruction_t **inst_1, instruction_t **inst_2)
{
    instruction_t *tmp = *inst_1;

    *inst_1 = *inst_2;
    *inst_2 = tmp;
}

void draw_no_instr_label(cw_graph_t *cw_graph, int i,
instruction_t *instruction, int *index)
{
    sfCircleShape_setFillColor(cw_graph->buttons,
    (sfColor){200, 150, 50, 255});
    sfCircleShape_setPosition(cw_graph->buttons,
    (sfVector2f){40, 165 + i * 39.3 + cw_graph->edit.cursor});
    sfCircleShape_setRadius(cw_graph->buttons, 13);
    sfRenderWindow_drawCircleShape(cw_graph->window->window,
    cw_graph->buttons, NULL);
    sfText_setColor(cw_graph->text.text, sfWhite);
    sfText_setString(cw_graph->text.text, "+");
    sfText_setPosition(cw_graph->text.text,
    (sfVector2f){48, 165 + i * 39.3 + cw_graph->edit.cursor});
    sfRenderWindow_drawText(cw_graph->window->window,
    cw_graph->text.text, NULL);
    if (is_in_rect(cw_graph, (sfVector2f){40, 165 + i * 39.3 +
        cw_graph->edit.cursor}, (sfVector2f){26, 26}) &&
    cw_graph->is_released){
        instruction->label = strcat(my_strdup("flat_"), int_to_str(index));
        (*index)++;
    }
}

void draw_label_instr(cw_graph_t *cw_graph, int i, instruction_t *instruction)
{
    static int index = 0;

    if (!instruction->label)
        draw_no_instr_label(cw_graph, i, instruction, &index);
    else
        draw_text(cw_graph, instruction->label, 15, (sfVector2f)
        {44, 170 + i * 39.3 + cw_graph->edit.cursor});
}

void remove_instruction(cw_graph_t *cw_graph, int *i, bool *removed)
{
    free(cw_graph->edit.instructions[*i]->description);
    free(cw_graph->edit.instructions[*i]->args);
    free(cw_graph->edit.instructions[*i]->label_args);
    free(cw_graph->edit.instructions[*i]);
    for (int j = *i; cw_graph->edit.instructions[j]; j++)
        cw_graph->edit.instructions[j] = cw_graph->edit.instructions[j + 1];
    (*i)--;
    (*removed) = true;
}

void draw_champ_instructions(cw_graph_t *cw_graph)
{
    bool removed = false;
    bool moved = false;
    int ret = 0;

    for (int i = 0; cw_graph->edit.instructions[i]; i++) {
        ret = draw_one_instruction_champ(cw_graph, i,
        cw_graph->edit.instructions[i]);
        if (ret == 1 && !removed)
            remove_instruction(cw_graph, &i, &removed);
        if (ret == 2 && !moved && i) {
            swap_instructions(&cw_graph->edit.instructions[i],
            &cw_graph->edit.instructions[i - 1]);
            moved = true;
        } else if (ret == 3 && !moved && cw_graph->edit.instructions[i + 1]) {
            swap_instructions(&cw_graph->edit.instructions[i],
            &cw_graph->edit.instructions[i + 1]);
            moved = true;
        }
    }
}
