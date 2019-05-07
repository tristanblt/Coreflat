/*
** EPITECH PROJECT, 2018
** strlen fonction
** File description:
** strlen
*/

#include "my.h"

int strlen_my_put_nbr_unsigned(unsigned int nb, int i)
{
    if (nb > 9){
        while (nb > 9){
            nb /= 10;
            i++;
        }
    }
    else
        i++;
    return (i);
}

int strlen_my_put_nbr(int nb, int i)
{
    if (nb < 0){
        my_putchar('-');
        i++;
    }
    if (nb > 9){
        while (nb > 9){
            nb /= 10;
            i++;
        }
    }
    else
        i++;
    return (i);
}