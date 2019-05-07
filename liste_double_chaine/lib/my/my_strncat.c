/*
** EPITECH PROJECT, 2018
** strncat
** File description:
** strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int j = 0;

    while (j < nb && src[j] != '\0'){
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
