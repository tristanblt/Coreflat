/*
** EPITECH PROJECT, 2018
** isupper
** File description:
** isupper
*/

#include <unistd.h>

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}
