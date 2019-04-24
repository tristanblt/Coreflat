/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_handling_and_parsing
*/

#include "my.h"
#include "asm.h"

instruction_t **error_handling_and_parsing(char *file_path)
{
    instruction_t **instructions = NULL;
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
        return (NULL);
    
    return (instructions);
}