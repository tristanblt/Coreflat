/*
** EPITECH PROJECT, 2019
** my strlen
** File description:
** my strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}
