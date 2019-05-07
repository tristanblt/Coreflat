/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** display string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
