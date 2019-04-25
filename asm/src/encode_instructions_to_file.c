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

void write_description(char *description, int fd)
{
    char c = 0;
    int i = 0;

    for (i = 0; description[i] != -1; i++) {
        if (description[i] == T_REG)
            c += 1;
        if (description[i] == T_DIR)
            c += 2;
        if (description[i] == T_IND)
            c += 3;
        c <<= 2;
    }
    for (; i < 3; i++)
        c <<= 2;
    write(fd, &c, 1);
}

bool encode_and_write_instructions(int fd, instruction_t **instructions)
{
    for (int i = 0; instructions[i]; i++) {
        write(fd, &instructions[i]->code, 1);
        write_description(instructions[i]->description, fd);
        for (int j = 0; instructions[i]->args[j] != -1; j++) {
            write(fd, &instructions[i]->args[j], 1);
        }
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
    if (encode_and_write_instructions(fd, instructions) == false) {
        close(fd);
        return (false);
    }
    close(fd);
    return (true);
}