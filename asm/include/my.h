/*
** EPITECH PROJECT, 2019
** my h
** File description:
** my h
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (100)
#endif

#define REALLOC (my_realloc((*to_fill), my_strlen\
((*to_fill))+my_strlen(buffer)+1))

typedef struct flag
{
    char flag;
    int (*print)();
} t_flags;

int my_put_double_arg(int fd, va_list ap);
int my_put_double(int fd, double nb);
int my_printf(char *, ...);
int my_dprintf(int, char *, ...);
int my_putchar(int, char);
int my_putchar_arg(int, va_list);
int my_putstr(int, char *);
int my_putstr_arg(int, va_list);
int my_put_nbr_arg(int, va_list ap);
int my_put_nbr(int, int);
char **my_str_to_array(char *);
int my_strlen(char const *);
char *my_strdup(char const *);
bool my_strcmp(char const *str, char const *str2);
bool my_strncmp(char const *str, char const *str2, int n);
int my_get_nbr(char const *str);
bool is_num(char const *str);
char *get_next_line(int fd);
char **my_str_to_array_opt(char *str, char c);
void * __cdecl my_calloc(int count, int size);

#endif
