/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** string into int
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long nb = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0'){
        if (nb > 214748364 || (nb == 214748364 && \
            (str[i] == '9'|| (str[i] == '8' && neg == 1))))
            return (0);
        nb = nb * 10;
        nb += str[i] - 48;
        i++;
    }
    return (nb * neg);
}
