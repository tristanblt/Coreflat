/*
** EPITECH PROJECT, 2018
** flags
** File description:
** flags
*/

#include <stdarg.h>
#include "my.h"

void display_zero(char c)
{
    if (c < 8)
        my_putstr("00");
    if (c >= 8 && c < 32)
        my_putstr("0");
}

void display_non_printable(char *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < 32 || str[i] >= 127){
            my_putchar('\\');
            display_zero(str[i]);
            my_putnbr_base(str[i], "01234567");
        }
        else
            my_putchar(str[i]);
        i++;
    }
}

int do_flags_3(const char *format, va_list list, int i)
{
    int j = 0;

    switch (format[i + 1]) {
    case 'p':
        my_putstr("0x");
        my_putnbr_base_unsigned((unsigned long)(va_arg(list, char *))\
, "0123456789abcdef");
        return (i + 2);
    case 'S':
        display_non_printable(va_arg(list, char *));
        return (i + 2);
    case '0':
        j = cmpt_len(format, i + 1, list);
        if (j == -1)
            break;
        else
            return (j);
    }
    i = do_flags_4(format, list, i);
    return (i);
}

int do_flags_bis(const char *format, va_list list, int i)
{
    switch (format[i + 1]) {
    case 'o':
        my_putnbr_base(va_arg(list, int), "01234567");
        return (i + 2);
    case 'x':
        my_putnbr_base(va_arg(list, int), "0123456789abcdef");
        return (i + 2);
    case 'u':
        my_unsigned_putnbr(va_arg(list, unsigned int));
        return (i + 2);
    case 'b':
        my_putnbr_base(va_arg(list, int), "01");
        return (i + 2);
    }
    i = do_flags_3(format, list, i);
    return (i);
}

int do_flags(const char *format, va_list list, int i)
{
    switch (format[i + 1]) {
    case 'c':
        my_putchar(va_arg(list, int));
        return (i + 2);
    case 's':
        my_putstr(va_arg(list, char *));
        return (i + 2);
    case 'i':
    case 'd':
        my_put_nbr(va_arg(list, int));
        return (i + 2);
    case 'X':
        my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
        return (i + 2);
    }
    i = do_flags_bis(format, list, i);
    return (i);
}