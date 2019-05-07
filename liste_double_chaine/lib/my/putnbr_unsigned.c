/*
** EPITECH PROJECT, 2018
** unsigned putnbr
** File description:
** unsigned putnbr
*/

#include "my.h"

void my_putnbr_base_unsigned(unsigned long nbr, char const *base)
{
    int i = 0;
    int result = 0;

    if (nbr > 0) {
        i = nbr % my_strlen(base);
        result = nbr / my_strlen(base);
        my_putnbr_base_unsigned(result, base);
        my_putchar(base[i]);
    }
}
