/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** champion_manager
*/

#include "my.h"
#include "corewar.h"

champion_t *champion_dup(champion_t *dup)
{
    champion_t *new = malloc(sizeof(champion_t));

    if (new == NULL)
        return (NULL);
    new->color = dup->color;
    new->dead = dup->dead;
    new->header = dup->header;
    new->instructions = dup->instructions;
    new->last_live = dup->last_live;
    new->prog_number = dup->prog_number;
    new->start_offset = dup->start_offset;
    return (new);
}

champion_t **push_champion(champion_t **arr, champion_t *add)
{
    champion_t **new_arr = NULL;
    int nb_elem_arr;
    int copy_elems;

    if (add == NULL)
        return (NULL);
    for (nb_elem_arr = 0; arr[nb_elem_arr] != NULL; nb_elem_arr++);
    new_arr = malloc(sizeof(champion_t *) * (nb_elem_arr + 2));
    if (new_arr == NULL)
        return (NULL);
    for (copy_elems = 0; copy_elems < nb_elem_arr; copy_elems++)
        new_arr[copy_elems] = arr[copy_elems];
    new_arr[copy_elems] = add;
    new_arr[copy_elems + 1] = NULL;
    free(arr);
    return (new_arr);
}

header_t *get_champion_info(char *file_path, char **file_content)
{
    int fd = open(file_path, O_RDONLY);
    header_t *header = malloc(sizeof(header_t));

    if (fd == -1 || !header)
        return (NULL);
    *header = (header_t){0};
    if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
        return (NULL);
    header->magic = reverse_bytes_corewar(header->magic);
    header->prog_size = reverse_bytes_corewar(header->prog_size);
    if (header->magic != COREWAR_EXEC_MAGIC || header->prog_size < 0 ||
    !(*file_content = malloc(sizeof(char) * (header->prog_size + 1)))) {
        (free(header), close(fd));
        return (NULL);
    }
    (*file_content)[header->prog_size] = 0;
    if (read(fd, *file_content, header->prog_size) != header->prog_size) {
        (free(header), close(fd), free(*file_content));
        return (NULL);
    } close(fd);
    return (header);
}

champion_t *create_champion(char *path, int n, int a)
{
    char *file = NULL;
    int size = 0;
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return (NULL);
    *champion = (champion_t){0};
    if (!(champion->header = get_champion_info(path, &file)))
        return (NULL);
    champion->instructions = file;
    if (parse_instructions(file, size) == false)
        return (NULL);
    champion->start_offset = a;
    champion->prog_number = n;
    return (champion);
}
