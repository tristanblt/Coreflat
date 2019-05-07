/*
** EPITECH PROJECT, 2018
** islower
** File description:
** islower
*/

#include <unistd.h>

int my_str_islower(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
