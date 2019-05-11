/*
** EPITECH PROJECT, 2019
** char is in string
** File description:
** checks if the char is in the string
*/

#include <stdbool.h>

bool char_is_in_string(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (true);
    return (false);
}
