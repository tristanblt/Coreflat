/*
** EPITECH PROJECT, 2019
** load file in mem
** File description:
** loads a file in memory
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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

char **load_file_in_2d_array(char const *filepath)
{
    char *file_content = load_file_in_mem(filepath);
    int lines = 1;
    char **array;

    if (!file_content)
        return (NULL);
    for (int i = 0; file_content[i]; i++)
        if (file_content[i] == '\n' && file_content[i + 1])
            lines++;
    if (!(array = malloc(sizeof(char *) * (1 + lines))))
        return (NULL);
    array[lines] = NULL;
    array[0] = file_content;
    for (int i = 0, j = 1; file_content[i]; i++)
        if (file_content[i] == '\n' && file_content[i + 1])
            array[j++] = &file_content[i + 1];
    for (int i = 0; file_content[i]; i++)
        if (file_content[i] == '\n')
            file_content[i] = 0;
    return (array);
}
