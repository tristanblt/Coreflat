/*
** EPITECH PROJECT, 2018
** putnbr_base
** File description:
** putnbr_base
*/

#include "my.h"

int my_strlen_bis(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void my_putnbr_base(int nbr, char const *base)
{
    int i = 0;
    int result = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    if (nbr > 0) {
        i = nbr % my_strlen_bis(base);
        result = nbr / my_strlen_bis(base);
        my_putnbr_base(result, base);
        my_putchar(base[i]);
    }
}
