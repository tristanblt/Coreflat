/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_strncpy
*/

#include "my.h"
#include "asm.h"

char *my_strcpy_asm(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}