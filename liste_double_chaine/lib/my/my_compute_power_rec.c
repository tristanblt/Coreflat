/*
** EPITECH PROJECT, 2018
** my_compute_rec
** File description:
** rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (nb > 2147483647)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}
