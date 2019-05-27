/*
** EPITECH PROJECT, 2019
** my str to array opt
** File description:
** my str to array opt
*/

#include "my.h"
#include <stdlib.h>

static int find_next_word_opt(char *str, int i, char c)
{
    while (str[i] != c && str[i])
        i++;
    while (str[i] == c)
        i++;
    return (i);
}

static int find_world_length_opt(char *str, char c)
{
    int i = 0;

    while (str[i] != c && str[i])
        i++;
    return (i);
}

static char *dup_word_opt(char *str, char c)
{
    int length = find_world_length_opt(str, c);
    char *duplicate;

    if (length <= 0)
        return (NULL);
    duplicate = malloc(sizeof(char) * (1 + length));
    if (!duplicate)
        return (NULL);
    duplicate[length] = 0;
    for (int i = 0; i < length; i++)
        duplicate[i] = str[i];
    return (duplicate);
}

char **my_str_to_array_opt(char *str, char c)
{
    char **array;
    int words;

    !find_world_length_opt(str, c) ? (words = 0) : (words = 1);
    for (int i = 0; str[i]; i = find_next_word_opt(str, i, c))
        words++;
    words == 0 ? (words++) : 0;
    array = malloc(sizeof(char *) * (words));
    if (!array)
        return (NULL);
    array[words - 1] = NULL;
    for (int i = 0, j = 0; str[i]; i = find_next_word_opt(str, i, c), j++) {
        if (str[i] == c) {
            j = -1;
            continue;
        }
        array[j] = dup_word_opt(&str[i], c);
        if (!array[j])
            return (NULL);
    }
    return (array);
}
