/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** free_utils
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

void free_double_arr(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}

void free_instructions(instruction_t **arr)
{
    for (int i = 0; arr[i]; i++) {
        if (arr[i]->label)
            free(arr[i]->label);
        free(arr[i]->args);
        free(arr[i]->description);
        for (int j = 0; j < MAX_ARGS_NUMBER; j++)
            arr[i]->label_args[j] ? free(arr[i]->label_args[j]) : 0;
        free(arr[i]->label_args);
        free(arr[i]);
    }
    free(arr);
}

void free_header(header_t *header)
{
    free(header);
}
