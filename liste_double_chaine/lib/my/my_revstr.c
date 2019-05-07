/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** rev a sting
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}
