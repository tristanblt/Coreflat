/*
** EPITECH PROJECT, 2018
** Task05
** File description:
** Transforms string into number.
*/

int my_get_nbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    if (str[0] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr*10 + str[i] - '0';
        i++;
    }
    if (str[0] == '-')
        nbr *= -1;
    return (nbr);
}
