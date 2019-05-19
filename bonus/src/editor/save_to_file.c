/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** save_to_file
*/

#include "coreflat.h"
#include "asm.h"

void adapt_instructions_to_asm(instruction_t **instructions)
{
    int i = 0;

    for (int j = 0; instructions[j]; j++) {
        for (i = 0; instructions[j]->description[i]; i++);
        instructions[j]->description[i] = -1;
    }
}

void adapt_instructions_to_coreflat(instruction_t **instructions)
{
    int i = 0;

    for (int j = 0; instructions[j]; j++) {
        for (i = 0; instructions[j]->description[i] != -1; i++);
        instructions[j]->description[i] = 0;
    }
}

void save_to_file(cw_graph_t *cw_graph)
{
    char *s_file = my_strcat(cw_graph->edit.header->prog_name, ".s");
    char *file_name = NULL;
    char *comment = AUTO_COMMENT;

    if (!s_file)
        return;
    file_name = my_strcat(strdup("champions/"), s_file);
    if (!file_name)
        return;
    for (int i = 0; comment[i]; i++)
        cw_graph->edit.header->comment[i] = comment[i];
    cw_graph->edit.header->magic = reverse_bytes_corewar(COREWAR_EXEC_MAGIC);
    adapt_instructions_to_asm(cw_graph->edit.instructions);
    cw_graph->edit.header->prog_size =
    compute_instruction_size(cw_graph->edit.instructions);
    if (labels_get_values(cw_graph->edit.instructions))
        return;
    if (!encode_instructions_to_file(file_name,
        cw_graph->edit.instructions, cw_graph->edit.header))
        return;
    adapt_instructions_to_coreflat(cw_graph->edit.instructions);
}
