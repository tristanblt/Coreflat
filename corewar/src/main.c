/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** wow
*/

#include "my.h"
#include "corewar.h"

int main(void)
{
    char *file = NULL;
    int size = 0;

    if ((file = get_cor_file("test", &size)) == NULL)
        return (EXIT_FAIL);
    
    return (0);
}
