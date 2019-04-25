/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_calloc
*/

#include "my.h"

void *my_memset(void *alloced, char c, int count)
{
    char *start;

	if (alloced == NULL)
		return (NULL);
	start = alloced;
	for (; count; count--) {
		*start = c;
		start++;
	}
	return (alloced);
}

void *my_calloc(int count, int size)
{
    void *alloced = malloc(count * size);

    my_memset(alloced, 0, count);
    return(alloced);
}