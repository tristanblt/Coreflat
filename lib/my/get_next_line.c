/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** gets next line
*/

#include <stdlib.h>
#include "my.h"
#include <unistd.h>

char *my_realloc(char *str, size_t size)
{
    char *reallocd = malloc(size);
    int i = 0;

    if (!reallocd)
        return (NULL);
    for (; str[i]; i++)
        reallocd[i] = str[i];
    reallocd[i] = 0;
    free(str);
    return (reallocd);
}

int fill_str(char *buffer, char **to_fill)
{
    int i = 0;

    if (!(*to_fill)) {
        (*to_fill) = malloc(my_strlen(buffer) + 1);
        (*to_fill) ? (*to_fill)[0] = 0: 0;
    } else
        (*to_fill) = REALLOC;
    if (!(*to_fill))
        return (1);
    for (; (*to_fill)[i]; i++);
    for (int j = 0; buffer[j]; j++, i++)
        if (buffer[j] == '\n') {
            (*to_fill)[i] = 0;
            return (1);
        } else
            (*to_fill)[i] = buffer[j];
    (*to_fill)[i] = 0;
    return (0);
}

char *prepare_buffer(char *buffer, char *to_return, int state)
{
    int i;
    int j;

    if (state == 0) {
        free(to_return);
        return (NULL);
    }
    for (i = 0; buffer[i] != '\n' && buffer[i]; i++);
    if (!buffer[i])
        return (to_return);
    i++;
    for (j = 0; buffer[i]; j++, i++)
        buffer[j] = buffer[i];
    buffer[j] = 0;
    return (to_return);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE + 1] = {0};
    char *to_return = NULL;
    int size = 0;

    if (fd < 0)
        return (NULL);
    if (fill_str(buffer, &to_return))
        return (prepare_buffer(buffer, to_return, 1));
    size = read(fd, buffer, READ_SIZE);
    if (size <= 0)
        return (prepare_buffer(buffer, to_return, 0));
    buffer[size] = 0;
    for (; !fill_str(buffer, &to_return) && size; buffer[size] = 0)
        size = read(fd, buffer, READ_SIZE);
    return (prepare_buffer(buffer, to_return, 1));
}
