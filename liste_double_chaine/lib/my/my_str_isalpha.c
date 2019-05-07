/*
** EPITECH PROJECT, 2018
** strisalpha
** File description:
** return 1 or 0
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i]){
        if ((str[i] <= 'z' && str[i] >= 'a') ||\
            (str[i] <= 'Z' && str[i] >= 'A'))
            i++;
        else
            return (0);
    }
    return (1);
}
