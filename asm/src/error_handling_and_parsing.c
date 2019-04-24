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
    FILE *fd = fopen(file_path, "r");
    char **file = NULL;

    if (fd == NULL)
        return (NULL);
    if ((file = get_file(fd)) == NULL)
        return (NULL);
    for (int i = 0; file[i] != NULL; i++) {
        puts(file[i]);
    }
    return (instructions);
}