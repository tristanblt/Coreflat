/*
** EPITECH PROJECT, 2019
** my put char
** File description:
** my put char
*/

#include <unistd.h>
#include "my.h"

int my_putchar_arg(int fd, va_list ap)
{
    return (my_putchar(fd, va_arg(ap, int)));
}

int my_putchar(int fd, char c)
{
    return (write(fd, &c, 1));
}
