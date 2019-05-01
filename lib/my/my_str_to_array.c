/*
** EPITECH PROJECT, 2019
** my str to array
** File description:
** takes str, returns array
*/

#include <stdlib.h>
#include "my.h"

int find_next_word(char *str, int i)
{
    while (str[i] != ' ' && str[i] != '\t' && str[i])
        i++;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return (i);
}

int find_word_length(char *str)
{
    int i = 0;

    while (str[i] != ' ' && str[i] != '\t' && str[i])
        i++;
    return (i);
}

char *dup_word(char *str)
{
    int length = find_word_length(str);
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

char **my_str_to_array(char *str)
{
    char **array;
    int words;

    !find_word_length(str) ? (words = 0) : (words = 1);
    for (int i = 0; str[i]; i = find_next_word(str, i))
        words++;
    words == 0 ? (words++) : 0;
    array = malloc(sizeof(char *) * (words));
    if (!array)
        return (NULL);
    array[words - 1] = NULL;
    for (int i = 0, j = 0; str[i]; i = find_next_word(str, i), j++) {
        if (str[i] == ' ' || str[i] == '\t') {
            j = -1;
            continue;
        }
        array[j] = dup_word(&str[i]);
        if (!array[j])
            return (NULL);
    }
    return (array);
}
