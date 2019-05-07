/*
** EPITECH PROJECT, 2018
** flags modifiers
** File description:
** flags
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void do_0_d(va_list list, char *tmp)
{
    int nb = my_getnbr(tmp);
    int nbr = va_arg(list, int);

    nb -= strlen_my_put_nbr(nbr, 1);
    while (nb > 0){
        my_putchar('0');
        nb--;
    }
    my_put_nbr(nbr);
}

void do_0_u(va_list list, char *tmp)
{
    int nb = my_getnbr(tmp);
    unsigned int nbr = va_arg(list, unsigned int);

    nb -= strlen_my_put_nbr_unsigned(nbr, 1);
    while (nb > 0){
        my_putchar('0');
        nb--;
    }
    my_unsigned_putnbr(nbr);
}

void do_0_base(va_list list, char *tmp, char *base)
{
    int nb = my_getnbr(tmp);
    int nbr = va_arg(list, int);

    nb -= strlen_my_put_nbr(nbr, 1);
    while (nb > 0){
        my_putchar('0');
        nb--;
    }
    my_putnbr_base(nbr, base);
}

void do_0(char const*format, int i, va_list list, char *tmp)
{
    switch (format[i]) {
    case 'i':
    case 'd':
        do_0_d(list, tmp);
        break;
    case 'o':
        do_0_base(list, tmp, "01234567");
        break;
    case 'u':
        do_0_u(list, tmp);
        break;
    case 'x':
        do_0_base(list, tmp, "0123456789abcdef");
        break;
    case 'X':
        do_0_base(list, tmp, "0123456789ABCDEF");
        break;
    }
}

int cmpt_len(char const *format, int i, va_list list)
{
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(format) + 1));

    while (format[i] != 'd' && format[i] != 'i'\
    && format[i] != 'o' && format[i] != 'u'\
    && format[i] != 'x' && format[i] != 'X' && format[i]){
        tmp[j] = format[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    if (format[i] == 'd' || format[i] == 'i' ||\
    format[i] == 'o' || format[i] == 'u' ||\
    format[i] == 'x' || format[i] == 'X'){
        do_0(format, i, list, tmp);
        return (i + 1);
    }
    else
        return (-1);
}
