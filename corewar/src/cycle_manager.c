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

bool do_a_cycle(proc_t ***procs, int i)
{

    return (true);
}

bool do_corewar_cycle(proc_t ***procs)
{
    for (int i = 0; procs[0][i]; i++)
        if (!do_a_cycle(procs, i))
            return (false);
    return (true);
}

bool check_lives()
{
    return (true);
}

bool start_corewar(champion_t **champions, list_t *memory)
{
    proc_t **procs = init_processes(champions);

    if (procs == NULL)
        return (false);
    while (true) {
        if (!check_lives())
            break;
        if (!do_corewar_cycle(&procs))
            return (false);
    }
    // display winner
    return (true);
}