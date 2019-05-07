/*
** EPITECH PROJECT, 2018
** unsigend putnbr
** File description:
** unsigned
*/

#include "my.h"

int unsigned_verif(unsigned int nb)
{
    if (nb == 4294967295){
        my_put_nbr(429496729);
        my_putchar('5');
        return (0);
    }
    return (1);
}

int my_unsigned_putnbr(unsigned int nb)
{
    int save = 0;

    if (unsigned_verif(nb) == 0)
        return (0);
    if (nb > 9){
        save = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(save + '0');
    }
    else
        my_putchar(nb + '0');
    return (0);
}