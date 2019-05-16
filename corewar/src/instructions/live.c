/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** live
*/

#include "my.h"
#include "corewar.h"

char *get_champ_name(proc_t **procs, int nb)
{
    for (int i = 0; procs[i]; i++)
        if (procs[i]->champion->prog_number==nb && !procs[i]->champion->dead) {
            procs[i]->champion->last_live = 0;
            return (procs[i]->champion->header->prog_name);
        }
    return (NULL);
}

bool live(proc_t ***procs, int i)
{
    int nb = procs[0][i]->instruction->args[0];
    char *name = get_champ_name(*procs, nb);

    if (!name)
        return (true);
    my_printf("The player %i(%s) is alive.\n", nb, name);
    nbr_lives++;
    if (nbr_lives > NBR_LIVE) {
        cycle_to_die -= CYCLE_DELTA;
        nbr_lives = 0;
    }
    return (true);
}
