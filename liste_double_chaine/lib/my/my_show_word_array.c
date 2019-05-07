/*
** EPITECH PROJECT, 2018
** show word array
** File description:
** show word array
*/

#include <unistd.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    if (tab == NULL)
        return (0);
    while (tab[i]){
        my_putstr(tab[i]);
        my_putstr("\n");
        i++;
    }
    return (0);
}
