/*
** EPITECH PROJECT, 2019
** EPITECH 2018
** File description:
** arguments_handling
*/

#include "corewar.h"

bool putstr_bool(char *str)
{
    write (1, str, my_strlen(str));
    return (true);
}

bool end_of_file(char *path, char *end)
{
    int n = my_strlen(path) - 1;
    int i = 0;

    if (n <= my_strlen(end) - 1)
        return (false);
    for (i = n; path[i] != '.'; i--);
    path += i;
    if (!my_strcmp(path, end))
        return (false);
    return (true);
}

bool flag_n_error(char *str)
{
    printf("error = %s", str);
    if (!is_num(str)){
        puts("test");
        return (false);
    }
    if (my_get_nbr(str) < 0 || my_get_nbr(str) >= 4){
        puts("test");
        return (false);
    }
    return (true);
}

info_t *get_info_champ(char **av, int i)
{
    info_t *info = malloc(sizeof(info_t));

    if (info == NULL)
        return (NULL);
    while (end_of_file(av[i], ".cor") == false && i != 0)
        i--;
    while (end_of_file(av[i + 1], ".cor") == false){
        if (my_strcmp(av[i + 1], "-n") == true){
            if (!flag_n_error(av[i + 2]))
                return (false);
            else
                info->prog_number = my_get_nbr(av[i + 2]);
        }
        printf("prog_number = %d\n", info->prog_number);
        i += 2;
    }
    return (info);
}

//if ((champion[cmp]->info = get_info_champ(av, i - 1)) == NULL)
//                return (false);

bool argument_handling(int ac, char **av)
{
    info_t *info = malloc(sizeof(info_t));

    if (ac == 2 && (my_strcmp(av[1], "-h") == true)){
        putstr_bool(USAGE);
        return (true);
    }
    for (int i = 0; av[i]; i++)
        if (!count_champ(av[i], info))
            return (false);
    return (false);
}

bool count_champ(char *str, info_t *info)
{
    int champ = 0;
    int fd = 0;

    if (end_of_file(str, ".cor")){
        if (fd = open(str, O_RDONLY) == -1)
            return (false);
        info->nb_champ++;
        close(fd);
    }
    printf("%d\n", info->nb_champ);
    return (true);
}