/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** return the square
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    int result = 0;

    if (nb < 0)
        return (0);
    while (result < nb){
        result = i * i;
        if (result == nb)
            return (i);
        i++;
    }
    return (0);
}
