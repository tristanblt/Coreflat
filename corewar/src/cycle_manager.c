/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cycle_manager
*/

#include "my.h"
#include "corewar.h"

int find_cycle_n(int code)
{
    for (int i = 0; op_tab[i].code; i++)
        if (code == op_tab[i].code)
            return (op_tab[i].nbr_cycles);
    return (0);
}

bool do_a_cycle(champion_t *champion, int i)
{
    return (true);
}

bool champion_cycle(champion_t *champion, int i)
{
    for (int i = 0; champion->pcs[i].memory; i++) {
        if (!do_a_cycle(champion, i))
            return (false)
    }
    return (true);
}

bool champions_cycle(champion_t **champions)
{
    for (int i = 0; i < 1; i++)
        if (!champion_cycle(champions[i], i))
            return (false);
    return (true);
}

bool start_cycle(champion_t **champions)
{
    while (1)
        if (!champions_cycle(champions))
            break;
    return (true);
}