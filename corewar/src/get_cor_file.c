/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_cor_file
*/

#include "my.h"
#include "corewar.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int is = my_strlen(dest);
    int total = my_strlen(src) + my_strlen(dest);
    char *to_ret = malloc(sizeof(char) * (total + 1));

    if (to_ret == NULL)
        return (NULL);
    for (int j = 0; j < i; j++)
        to_ret[j] = dest[j];
    for (; i < total; i++)
        to_ret[i] = src[i - is];
    to_ret[i] = 0;
    return (to_ret);
}

int get_file_size(char const *filepath)
{
    char buff[4096];
    int fd = open(filepath, O_RDONLY);
    int read_size = 0;
    int file_size = 0;

    if (fd == -1)
        return (-1);
    while ((read_size = read(fd, buff, 4096)) > 0)
        file_size += read_size;
    close(fd);
    if (read_size == -1)
        return (-1);
    return (file_size);
}

char *load_file_in_mem(char const *filepath)
{
    char buff[4096];
    char *file;
    int fsize = get_file_size(filepath);
    int size;
    int j;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || fsize <= 0 || !(file = malloc(sizeof(char) * (fsize + 1))))
        return (NULL);
    size = read(fd, buff, 4096);
    for (j = 0; size > 0; size = read(fd, buff, 4096))
        for (int i = 0; i < size; i++, j++)
            file[j] = buff[i];
    if (j != fsize)
        return (NULL);
    file[j] = 0;
    close(fd);
    return (file);
}

char *get_cor_file(char *path, int *size)
{
    *size = get_file_size(path);
    return (load_file_in_mem(path));
}
