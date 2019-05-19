/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** save_to_file
*/

#include "coreflat.h"

void save_to_file(cw_graph_t *cw_graph)
{
    char *s_file = strcat(strdup(cw_graph->edit.header->prog_name), ".s");
    char *file_name = NULL;
    char *comment = strdup(AUTO_COMMENT);

    if (!s_file || !comment)
        return;
    file_name  = strcat(strdup("champions/"), s_file);
    if (!file_name)
        return;
    for (int i = 0; comment[i]; i++)
        cw_graph->edit.header->comment[i] = comment[i];
    cw_graph->edit.header->prog_size = compute_instruction_size(cw_graph->edit.instructions);
    if (!encode_instructions_to_file(file_name,
    cw_graph->edit.instructions, cw_graph->edit.header)) {
        return;
    }
}