/*
** EPITECH PROJECT, 2019
** my printf
** File description:
** my printf
*/

#include <unistd.h>
#include "my.h"

t_flags flags[] = {
    {'i', my_put_nbr_arg},
    {'d', my_put_nbr_arg},
    {'s', my_putstr_arg},
    {'c', my_putchar_arg},
    {'f', my_put_double_arg},
    {0}
};

int print_flag(int fd, va_list ap, char *str, int *i)
{
    int printed = 0;

    (*i)++;
    for (int j = 0; flags[j].flag; j++)
        if (flags[j].flag == str[*i])
            return (flags[j].print(fd, ap));
    printed += my_putchar(fd, '%');
    printed += my_putchar(fd, str[*i]);
    return (printed);
}

int my_printf(char *str, ...)
{
    va_list ap;
    int printed = 0;

    va_start(ap, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%' && str[i + 1] == '%') {
            printed += my_putchar(1, '%');
            i++;
            continue;
        } else if (str[i] == '%')
            printed += print_flag(1, ap, str, &i);
        else
            printed += my_putchar(1, str[i]);
    }
    va_end(ap);
    return (printed);
}

int my_dprintf(int fd, char *str, ...)
{
    va_list ap;
    int printed = 0;

    va_start(ap, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%' && str[i + 1] == '%') {
            printed += my_putchar(fd, '%');
            continue;
        } else if (str[i] == '%')
            printed += print_flag(fd, ap, str, &i);
        else
            printed += my_putchar(fd, str[i]);
    }
    va_end(ap);
    return (printed);
}
