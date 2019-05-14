/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cycle_manager
*/

#include "my.h"
#include "corewar.h"

int cycle_to_die = CYCLE_TO_DIE;
int nbr_lives = 0;

int find_cycle_n(int code)
{
    for (int i = 0; op_tab[i].code; i++)
        if (code == op_tab[i].code)
            return (op_tab[i].nbr_cycles);
    return (0);
}

bool exec_cycle(proc_t ***procs, int i, fct_t *fcts)
{
    bool ret = true;

    if (!procs[0][i]->instruction->code)
        return (true);
    for (int j = 0; fcts[j].code; j++) {
        if (fcts[j].code == procs[0][i]->instruction->code) {
            ret = fcts[j].fct(procs, i);
            break;
        }
    }
    if (ret == false)
        return (false);
    return (true);
}

void new_cycle(proc_t *proc)
{
    parse_instruction_from_mem(proc);
    proc->cycles = find_cycle_n(proc->instruction->code);
}

bool do_a_cycle(proc_t ***procs, int i, fct_t *fcts)
{
    if (!procs[0][i]->is_active)
        return (true);
    if (procs[0][i]->cycles <= 0) {
        if (!exec_cycle(procs, i, fcts))
            return (false);
        new_cycle(procs[0][i]);
    }
    procs[0][i]->cycles--;
    return (true);
}

bool check_lives(champion_t **champions, proc_t **procs)
{
    static bool is_first_instruction = true;
    int alives = 0;

    for (int i = 0; champions[i]; i++) {
        if (!is_first_instruction)
            champions[i]->last_live++;
        else
            is_first_instruction = false;
        if (champions[i]->last_live > cycle_to_die) {
            champions[i]->dead = true;
        }
    }
    for (int i = 0; procs[i]; i++)
        if (procs[i]->champion->dead)
            procs[i]->is_active = false;
    for (int i = 0; champions[i]; i++)
        if (!champions[i]->dead)
            alives++;
    if (alives <= 1)
        return (false);
    return (true);
}
