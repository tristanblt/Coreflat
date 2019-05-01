/*
** EPITECH PROJECT, 2019
** my strdup
** File description:
** my strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    int length = my_strlen(str);
    char *duplicate;

    if (length <= 0)
        return (NULL);
    if (!(duplicate = malloc(sizeof(char) * (1 + length))))
        return (NULL);
    duplicate[length] = 0;
    for (int i = 0; str[i]; i++)
        duplicate[i] = str[i];
    return (duplicate);
}
