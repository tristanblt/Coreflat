/*
** EPITECH PROJECT, 2019
** is num
** File description:
** returns true if str only contains num and false otherwise
*/

#include "my.h"

bool is_num(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}
