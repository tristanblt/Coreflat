/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instruction_utils
*/

#include "corewar.h"
#include "my.h"

bool registers_are_valid(instruction_t *instruction)
{
    for (int i = 0; instruction->description[i]; i++)
        if (instruction->description[i] == 1 &&
            (instruction->args[i] < 1 || instruction->args[i] > REG_NUMBER))
            return (false);
    return (true);
}

int get_value_from_instrution(proc_t *proc, int arg)
{
    if (proc->instruction->description[arg] == 1)
        return (proc->registers[proc->instruction->args[arg] - 1]);
    return (proc->instruction->args[arg]);
}

void store_at_index_two(list_t *pc, int value, int index, int prog_nb)
{
    list_t *mem = NULL;
    int curr_byte = 0x00FF;
    int to_write = 0;

    if (index > 0)
        mem = go_n_next(pc, index);
    else
        mem = go_n_prev(pc, -index);
    for (int i = 0; i < 2; i++) {
        to_write = value & (~curr_byte);
        to_write >>= (6 - 2 * i) * 4;
        to_write &= 255;
        curr_byte >>= 8;
        curr_byte |= 0xFF00;
        mem->val = to_write;
        mem->owner = prog_nb;
        mem = mem->next;
    }
}

void store_at_index_int(list_t *pc, int value, int index, int prog_nb)
{
    list_t *mem = NULL;
    int curr_byte = 0x00FFFFFF;
    int to_write = 0;

    if (index > 0)
        mem = go_n_next(pc, index);
    else
        mem = go_n_prev(pc, -index);
    for (int i = 0; i < 4; i++) {
        to_write = value & (~curr_byte);
        to_write >>= (6 - 2 * i) * 4;
        to_write &= 255;
        curr_byte >>= 8;
        curr_byte |= 0xFF000000;
        mem->val = to_write;
        mem->owner = prog_nb;
        mem = mem->next;
    }
}
