/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** encode_instructions_to_file
*/

#include "my.h"
#include "asm.h"

char *change_s_to_cor(char *file_name)
{
    int i = 0;
    char *new_file_name = my_calloc(my_strlen(file_name) + 3, sizeof(char));

    if (new_file_name == NULL)
        return (NULL);
    for (; i < my_strlen(file_name) - 1; i++)
        new_file_name[i] = file_name[i];
    new_file_name[i] = 'c';
    new_file_name[i+1] = 'o';
    new_file_name[i+2] = 'r';
    free(file_name);
    return (new_file_name);
}

int create_file(char *file_name)
{
    return (open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0664));
}

bool encode_and_write_instructions(int fd, instruction_t **instructions)
{
    my_printf("TEST : \n");
    for (int i = 0; instructions[i]; i++) {
        my_printf("Code : %i, Sumarry : ", instructions[i]->code);
        for (int j = 0; instructions[i]->description[j]; j++) {
            my_printf("%i, ", instructions[i]->description[j]);
        }
        my_printf("Arguments : ");
        for (int j = 0; instructions[i]->args[j]; j++) {
            my_printf("%i, ", instructions[i]->args[j]);
        }
        my_printf("\n");
    }
    return (true);
}

bool encode_instructions_to_file(char *file_name, instruction_t **instructions)
{
    int fd;

    file_name = change_s_to_cor(file_name);
    if (file_name == NULL)
        return (false);
    if ((fd = create_file(file_name)) == -1) {
        free(file_name);
        return (false);
    }
    free(file_name);
    if (encode_and_write_instructions(fd, instructions) == false)
        return (false);
    return (true);
}