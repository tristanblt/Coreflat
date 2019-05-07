/*
** EPITECH PROJECT, 2018
** isprintable
** File description:
** print or not ?
*/

#include <unistd.h>

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    while (str[i]){
        if (str[i] <= 126 && str[i] >= 36)
            i++;
        else
            return (0);
    }
    return (1);
}
