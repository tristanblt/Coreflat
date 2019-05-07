/*
** EPITECH PROJECT, 2018
** str to word array
** File description:
** str to word array
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int my_isalpha_char(char c)
{
    if (((c >= '!') && (c <= '9')) || ((c >= ';') && (c <= '~')))
        return (1);
    else
        return (0);
}

int my_strlen_char(char const *str, int index)
{
    int result = 0;

    while (my_isalpha_char(str[index]) == 1){
        result++;
        index++;
    }
    return (result);
}

int my_strlen_words(char const *str)
{
    int i = 0;
    int words = 0;

    while (str[i]){
        if (my_isalpha_char(str[i]) == 1)
            words++;
        i++;
    }
    return (words);
}

char *my_strcpy_bis(char *dest, char const *src, int i)
{
    int j = 0;

    while (my_isalpha_char(src[i]) == 1){
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char **my_str_to_word_array(char const *str)
{
    char **array = NULL;
    int i = 0;
    int j = 0;

    if (str == NULL)
        return (NULL);
    array = malloc(sizeof(char *) * (my_strlen_words(str) + 1));
    while (str[i]){
        if (my_isalpha_char(str[i]) == 1){
            array[j] = malloc(sizeof(char *) * my_strlen_char(str, i) + 1);
            my_strcpy_bis(array[j], str, i);
            i += my_strlen_char(str, i);
            j++;
        }
        else
            i++;
    }
    array[j] = '\0';
    return (array);
}
