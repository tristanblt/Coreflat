/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** free_utils
*/

#include <stdlib.h>
#include "asm.h"

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
        free(arr[i]->args);
        free(arr[i]->description);
        free(arr[i]);
    }
    free(arr);
}