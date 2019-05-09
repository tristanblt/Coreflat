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

bool champion_cycle(champion_t *champion, int i)
{
    static int instruction[4] = {-1};

    if (champion->buffer_cycle == 0) {
        instruction[i]++;
        if (champion->instructions[instruction[i]] == NULL) {
            instruction[i] = 0;
            //return (false); // changer de cellule (fin de cycle des instructions)
        }
        champion->buffer_cycle = find_cycle_n(champion->instructions[instruction[i]]->code);
        if (champion->instructions[instruction[i]]->code == IC_live) {
            champion->alive = champion->cycle_to_die;
            champion->nbr_live++;
        }
    }
    else {
        champion->buffer_cycle--;
        champion->alive--;
    }
    if (champion->alive == 0)
        return (false);
    if (champion->nbr_live > NBR_LIVE) {
        printf("%i\n", champion->cycle_to_die);
        champion->cycle_to_die -= CYCLE_DELTA;
    }
    if (champion->cycle_to_die <= 0)
        return (false);
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