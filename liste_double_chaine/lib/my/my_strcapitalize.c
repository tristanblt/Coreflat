/*
** EPITECH PROJECT, 2018
** strcapitalize
** File description:
** strcapitalize
*/

char *my_strlowcase_bis(char *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase_bis(str);
    while (str[i]){
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            str[i + 1] -= 32;
        if ((str[i] == '-' || str[i] == '+') \
            && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            str[i + 1] -= 32;
        i++;
    }
    return (str);
}
