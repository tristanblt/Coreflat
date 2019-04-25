/*
** EPITECH PROJECT, 2019
** my strlen
** File description:
** my strlen
*/

#include <stdlib.h>
#include "op.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

int my_arrlen(char **arr)
{
    int i = 0;

    for (i = 0; arr[i]; i++);
    return (i);
}

int my_argslen(char **arr)
{
    int i = 0;

    for (i = 0; arr[i] && arr[i][0] != COMMENT_CHAR; i++);
    return (i);
}