/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display the number given as a parameter
*/

#include <unistd.h>
#include "my.h"

int verif(int nb)
{
    if (nb == -2147483648){
        my_put_nbr(-214748364);
        my_putchar('8');
        return (0);
    }
    if (nb == 2147483647){
        my_put_nbr(214748364);
        my_putchar('7');
        return (0);
    }
    return (1);
}

int my_put_nbr(int nb)
{
    int save = 0;

    if (verif(nb) == 0)
        return (0);
    if (nb < 0){
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb > 9){
        save = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(save + '0');
    }
    else
        my_putchar(nb + '0');
    return (0);
}
