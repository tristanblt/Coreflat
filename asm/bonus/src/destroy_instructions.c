/*
** EPITECH PROJECT, 2019
** destroy_instructions
** File description:
** frees the instructions
*/

#include "disasm.h"
#include <stdlib.h>

void destroy_instructions(instruction_t **insts)
{
    for (int i = 0; insts[i]; i++) {
        free(insts[i]->args);
        free(insts[i]->description);
        free(insts[i]->label);
        free(insts[i]->label_args);
        free(insts[i]);
    }
    free(insts);
}
