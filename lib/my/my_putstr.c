/*
** EPITECH PROJECT, 2019
** my put str
** File description:
** my put str
*/

#include "my.h"

int my_putstr_arg(int fd, va_list ap)
{
    return (my_putstr(fd, va_arg(ap, char *)));
}

int my_putstr(int fd, char *str)
{
    int printed = 0;

    if (!str)
        return (my_putstr(fd, "(null)"));
    for (int i = 0; str[i]; i++)
        printed += my_putchar(fd, str[i]);
    return (printed);
}
