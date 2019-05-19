/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** utils
*/

#include "coreflat.h"
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_revstr(char *str)
{
    int i = 0;
    char str2[my_strlen(str)];

    my_strcpy(str2, str);
    while (str[i] != '\0') {
        str[i] = str2[my_strlen(str) - 1 - i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (11));

    if (str == NULL)
        return (NULL);
    memset(str, 0, 11);
    if (nb == 0)
        str[0] = '0';
    for (int i = 0; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    my_revstr(str);
    return (str);
}

char *int_to_str_reg(int nb)
{
    char *str = malloc(sizeof(char) * (12));

    if (str == NULL)
        return (NULL);
    memset(str, 0, 12);
    if (nb == 0)
        str[0] = '0';
    for (int i = 0; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    my_revstr(str);
    return (str);
}
