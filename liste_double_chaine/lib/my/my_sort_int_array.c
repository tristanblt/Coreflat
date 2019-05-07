/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** sort a array of int
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size - 1){
        if (array[i] > array[i + 1]){
            my_swap(&array[i], &array[i + 1]);
            i = 0;
        }
        else
            i++;
    }
}
