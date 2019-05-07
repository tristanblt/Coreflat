/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** strstr
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (to_find[i]){
        if ((to_find[i] != str[i]) && str[i] != '\0')
            return (my_strstr(str + 1, to_find));
        i++;
    }
    return (str);
}
