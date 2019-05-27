/*
** EPITECH PROJECT, 2019
** EPITECH 2018
** File description:
** parse_args
*/

#include "corewar.h"

int *fill_arg(char **file, int *size, char *description, int *args)
{
    for (int i = 0; description[i]; i++){
        switch (description[i]) {
        case 1: args[i] = file[0][0];
            *file += 1;
            *size -= 1;
            break;
        case 2: args[i] = reverse_bytes_corewar(*(int *)(*file));
            *file += 4;
            *size -= 4;
            break;
        case 3: args[i] = reverse_bytes_two_corewar(*(short *)(*file));
            *file += 2;
            *size -= 2;
            break;
        }
    }
    return (args);
}

int *parse_args(char **file, int *size, char *description)
{
    int *args = malloc(sizeof(int) * 4);

    if (args == NULL)
        return (NULL);
    for (int i = 0; i < 4; i++)
        args[i] = 0;
    if (description == NULL) {
        args[0] = reverse_bytes_corewar(*(int *)(*file));
        *file += 4;
        *size -= 4;
        return (args);
    }
    args = fill_arg(file, size, description, args);
    return (args);
}