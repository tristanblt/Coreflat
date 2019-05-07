/*
** EPITECH PROJECT, 2018
** strupcase
** File description:
** a to A
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}
