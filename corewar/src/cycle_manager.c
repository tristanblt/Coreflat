/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cycle_manager
*/

#include "my.h"
#include "corewar.h"

int cycle_to_die = /* CYCLE_TO_DIE */1000;
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
//    my_printf("%d\n", (*procs)[i]->instruction->code);
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

bool do_corewar_cycle(proc_t ***procs, fct_t *fcts)
{
    for (int i = 0; procs[0][i]; i++)
        if (!do_a_cycle(procs, i, fcts))
            return (false);
    return (true);
}

bool check_lives(champion_t **champions, proc_t **procs)
{
    bool over = true;

    for (int i = 0; champions[i]; i++) {
        champions[i]->last_live++;
        if (champions[i]->last_live > cycle_to_die)
            champions[i]->dead = true;
        else
            over = false;
    }
    for (int i = 0; procs[i]; i++)
        if (procs[i]->champion->dead)
            procs[i]->is_active = false;
    return (!over);
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

bool start_corewar(champion_t **champions, list_t *memory)
{
    proc_t **procs = init_processes(champions, memory);
    fct_t *fcts = init_fcts();

    if (procs == NULL)
        return (false);
    while (true) {
        /* dump_memory(memory); */
        if (!check_lives(champions, procs))
            break;
        if (!do_corewar_cycle(&procs, fcts))
            return (false);
    }
    /* dump_memory(memory); */
    // display winner
    return (true);
}
