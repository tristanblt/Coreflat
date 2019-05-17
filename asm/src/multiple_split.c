/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** multiple_split
*/

#include "my.h"
#include "asm.h"

int is_split(char c, char *split)
{
    if (c == '\0' || c == '\n' || c == '\t')
        return (0);
    for (int i = 0; split[i]; i++) {
        if (split[i] == c)
            return (0);
    }
    return (1);
}

int count_words(char const *str, char *split)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_split(str[i], split) == 1 && is_split(str[i+1], split) == 0)
            count++;
    }
    return (count);
}

char **multiple_split(char *str, char *split)
{
    char **res = malloc((count_words(str, split) + 1) * sizeof(char *));
    int length = 0;
    int j = 0;

    if (res == NULL)
        return (NULL);
    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (is_split(str[i], split))
            length++;
        if (is_split(str[i], split) && is_split(str[i+1], split) == 0) {
            res[j] = malloc(length + 1);
            res[j] ? my_memset(res[j], '\0', length + 1) : 0;
            res[j] ? my_strncpy(res[j], &str[i - length + 1], length) : 0;
            length = 0;
            j++;
        }
        if (j && !res[j - 1])
            return (NULL);
    }
    res[j] = NULL;
    return (res);
}
