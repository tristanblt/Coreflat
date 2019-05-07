/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** swap the content of two integers
*/

void my_swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
