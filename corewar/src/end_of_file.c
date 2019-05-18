/*
** EPITECH PROJECT, 2019
** end of file
** File description:
** checks if the file extension is the right one
*/

#include "my.h"

bool end_of_file_corewar(char *path, char *end)
{
    int n = my_strlen(path) - 1;
    int i = 0;

    if (n <= my_strlen(end) - 1)
        return (false);
    for (i = n; path[i] && path[i] != '.'; i--);
    path += i;
    if (!my_strcmp(path, end))
        return (false);
    return (true);
}
