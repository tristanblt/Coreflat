/*
** EPITECH PROJECT, 2018
** isnum
** File description:
** return 0 or 1
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i]){
        if (str[i] <= '9' && str[i] >= '0')
            i++;
        else
            return (0);
    }
    return (1);
}
