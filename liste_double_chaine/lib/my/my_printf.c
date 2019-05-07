/*
** EPITECH PROJECT, 2018
** my printf
** File description:
** my printf
*/

#include <stdarg.h>
#include "my.h"

int do_flags_4(const char *format, va_list list, int i)
{
    char tmp[3];

    switch (format[i + 1]) {
    case '+':
        tmp[0] = '%';
        tmp[1] = format[i + 2];
        tmp[2] = '\0';
        my_putchar('+');
        do_flags(tmp, list, 0);
        return (i + 3);
    }
    my_putchar(format[i]);
    my_putchar(format[i + 1]);
    return (i + 2);
}

int display_modulo2(char const *format, int i, int cmpt, int opt)
{
    if (opt == 0) {
        while (cmpt > 1){
            my_putchar(format[i]);
            cmpt--;
            i++;
        }
    }
    else {
        while (cmpt > 0){
            my_putchar(format[i]);
            cmpt--;
            i++;
        }
    }
    return (i);
}

int display_modulo(char const *format, int i)
{
    int j = i;
    int cmpt = 0;

    while (format[j] == '%'){
        j++;
        cmpt++;
    }
    if (cmpt % 2 == 0 && format[j] != '%' && format[j] != '\n' && format[j])
        i = display_modulo2(format, i, cmpt, 0);
    else if (cmpt % 2 == 0)
        i = display_modulo2(format, i, cmpt, 1);
    else
        i = display_modulo2(format, i, cmpt, 1);
    return (i);
}

void check_flags(const char *format, va_list list)
{
    int i = 0;

    while (format[i]){
        if (format[i] == '%' && format[i + 1] != '%')
            i = do_flags(format, list, i);
        else if (format[i] == '%' && format[i + 1] == '%') {
            i = display_modulo(format, i + 1);
        }
        else {
            my_putchar(format[i]);
            i++;
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    check_flags(format, list);
    va_end(list);
    return (0);
}
