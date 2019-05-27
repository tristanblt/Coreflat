/*
** EPITECH PROJECT, 2019
** EPITECH 2018
** File description:
** start_corewar
*/

#include "corewar.h"
#include "my.h"
#include "time.h"

int nbr_cycles = 0;

fct_t *init_second_fcts(fct_t *fcts)
{
    fcts[9] = (fct_t) {ldi, IC_ldi};
    fcts[10] = (fct_t) {sti, IC_sti};
    fcts[11] = (fct_t) {fork_vm, IC_fork};
    fcts[12] = (fct_t) {lld, IC_lld};
    fcts[13] = (fct_t) {lldi, IC_lldi};
    fcts[14] = (fct_t) {lfork, IC_lfork};
    fcts[15] = (fct_t) {aff, IC_aff};
    fcts[16] = (fct_t) {0};
    return (fcts);
}

fct_t *init_fcts(void)
{
    fct_t *fcts = malloc(sizeof(fct_t) * 17);

    if (fcts == NULL)
        return (NULL);
    fcts[0] = (fct_t) {live, IC_live};
    fcts[1] = (fct_t) {ld, IC_ld};
    fcts[2] = (fct_t) {st, IC_st};
    fcts[3] = (fct_t) {add, IC_add};
    fcts[4] = (fct_t) {sub, IC_sub};
    fcts[5] = (fct_t) {and, IC_and};
    fcts[6] = (fct_t) {or, IC_or};
    fcts[7] = (fct_t) {xor, IC_xor};
    fcts[8] = (fct_t) {zjmp, IC_zjmp};
    fcts = init_second_fcts(fcts);
    return (fcts);
}

bool do_corewar_cycle(proc_t ***procs, fct_t *fcts)
{
    for (int i = 0; procs[0][i]; i++)
        if (!do_a_cycle(procs, i, fcts))
            return (false);
    return (true);
}

void display_winner(champion_t **champions)
{
    bool biggest = true;

    for (int i = 0; champions[i]; i++) {
        biggest = true;
        for (int j = 0; champions[j]; j++)
            champions[i]->last_live > champions[j]->last_live ?\
biggest = false : 0;
        if (biggest) {
            my_printf("The player %d(%s) has won.\n", \
champions[i]->prog_number, champions[i]->header->prog_name);
            return;
        }
    }
}

bool start_corewar(champion_t **champions, list_t *memory, int dump)
{
    proc_t **procs = init_processes(champions, memory);
    fct_t *fcts = init_fcts();
    int cycles = 0;

    if (procs == NULL || !fcts)
        return (false);
    while (true) {
        if (!check_lives(champions, procs))
            break;
        if (!do_corewar_cycle(&procs, fcts))
            return (false);
        if (cycles == dump) {
            dump_memory(memory);
            break;
        }
        cycles++;
    }
    display_winner(champions);
    destroy_processes(procs);
    free(fcts);
    return (true);
}
