/*
** EPITECH PROJECT, 2019
** my put nbr
** File description:
** my put nbr
*/

#include "my.h"

int my_put_nbr_arg(int fd, va_list ap)
{
    return (my_put_nbr(fd, va_arg(ap, int)));
}

int my_put_nbr(int fd, int nbr)
{
    int printed = 0;

    if (nbr < 0) {
        printed += my_putchar(fd, '-');
        return (printed + my_put_nbr(fd, -nbr));
    }
    if (nbr/10 >= 1)
        printed += my_put_nbr(fd, nbr/10);
    return (printed + my_putchar(fd, '0' + nbr % 10));
}

int my_put_double(int fd, double nb)
{
    int printed = my_put_nbr(fd, (int)nb);

    if (nb < 0)
        nb = -nb;
    printed += my_putchar(fd, '.');
    nb -= (int)nb;
    nb *= 1000000;
    for (int p = 100000; p > 0; p /= 10)
        printed += my_putchar(fd, ((int)nb)/p%10 + '0');
    return (printed);
}

int my_put_double_arg(int fd, va_list ap)
{
    return (my_put_double(fd, va_arg(ap, double)));
}
