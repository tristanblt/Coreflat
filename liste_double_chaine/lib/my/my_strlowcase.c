/*
** EPITECH PROJECT, 2018
** strlowcase
** File description:
** A to a
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}
