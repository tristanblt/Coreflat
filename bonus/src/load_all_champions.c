/*
** EPITECH PROJECT, 2019
** load
** File description:
** all champions
*/

#include "coreflat.h"
#include "corewar.h"
#include <sys/dir.h>
#include "my.h"

char *my_strcat(char *first, char *second)
{
    int len = my_strlen(first) + my_strlen(second) + 1;
    char *cat = malloc(sizeof(char) * len);
    int i = 0;

    if (!cat)
        return (NULL);
    for (; first[i]; i++)
        cat[i] = first[i];
    for (int j = 0; second[j]; i++, j++)
        cat[i] = second[j];
    cat[i] = 0;
    return (cat);
}

bool add_champion_all(char *name, champion_t ***champions, char *f_path)
{
    static int nb = 1;
    champion_t *to_add = NULL;
    char *path = NULL;

    if (!end_of_file_corewar(name, ".cor"))
        return (true);
    path = my_strcat(f_path, name);
    if (!path)
        return (false);
    to_add = create_champion(path, nb++, -1);
    if (!to_add)
        return (true);
    *champions = push_champion(*champions, to_add);
    if (*champions == NULL)
        return (false);
    free(path);
    return (true);
}

bool load_all_champions(char *path, champion_t ***champions)
{
    DIR *dir = opendir(path);
    struct dirent *content = NULL;

    if (!dir)
        return (false);
    while ((content = readdir(dir)))
        if (!add_champion_all(content->d_name, champions, path))
            return (false);
    content = readdir(dir);
    closedir(dir);
    return (true);
}
