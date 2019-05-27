/*
** EPITECH PROJECT, 2019
** parse instruction and header
** File description:
** parsing
*/

#include "disasm.h"
#include <stdlib.h>

instruction_t **push_instruction_asm(instruction_t **arr, instruction_t *add)
{
    instruction_t **new_arr = NULL;
    int nb_elem_arr;
    int copy_elems;

    for (nb_elem_arr = 0; arr[nb_elem_arr] != NULL; nb_elem_arr++);
    new_arr = malloc(sizeof(instruction_t *) * (nb_elem_arr + 2));
    if (new_arr == NULL)
        return (NULL);
    for (copy_elems = 0; copy_elems < nb_elem_arr; copy_elems++)
        new_arr[copy_elems] = arr[copy_elems];
    new_arr[copy_elems] = add;
    new_arr[copy_elems + 1] = NULL;
    free(arr);
    return (new_arr);
}

bool parse_header_and_instruction(header_t **header,
instruction_t ***insts, char *filepath)
{
    instruction_t *to_add = NULL;
    char *file_content = NULL;

    if (!(*header = parse_header_disasm(filepath, &file_content)))
        return (NULL);
    for (int i = 0; i < (*header)->prog_size;) {
        if (!(to_add = parse_instruction_from_file(file_content, &i,
            (*header)->prog_size)))
            return (NULL);
        if (!(*insts = push_instruction_asm(*insts, to_add)))
            return (NULL);
    }
    free(file_content);
    return (true);
}
