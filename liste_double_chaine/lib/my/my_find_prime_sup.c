/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** find prime sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1)
        nb++;
    return (nb);
}
