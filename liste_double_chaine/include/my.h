/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all proto
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
int verif(int nb);
int my_showstr(char const *str);
char *my_strlowcase_bis(char *str);
int my_isalpha_char(char c);
int my_strlen_char(char const *str, int index);
int my_strlen_words(char const *str);
char *my_strcpy_bis(char *dest, char const *src, int i);
int my_printf(const char *format, ...);
void my_putnbr_base(int nbr, char const *base);
int do_flags(const char *format, va_list list, int i);
int my_unsigned_putnbr(unsigned int nb);
void my_putnbr_base_unsigned(unsigned long nbr, char const *base);
int cmpt_len(char const *format, int i, va_list list);
int strlen_my_put_nbr_unsigned(unsigned int nb, int i);
int strlen_my_put_nbr(int nb, int i);
int do_flags_4(const char *format, va_list list, int i);

#endif /* !MY_H_ */
