/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_instruction_from_mem
*/

#include "my.h"
#include "corewar.h"

int get_argument_from_mem(proc_t *proc, int size)
{
    int argument = 0;

    for (int i = 0; i < size; i++) {
        argument <<= 8;
        argument |= (proc->pc->val);
        proc->pc = proc->pc->next;
    }
    proc->instruction->size += size;
    return (argument);
}

bool get_description_from_mem(proc_t *proc)
{
    if (has_one_argument_corewar(proc->instruction->code)) {
        if (!proc->instruction->description)
            proc->instruction->description = malloc(sizeof(char) * 2);
        if (!proc->instruction->description)
            return (false);
        proc->instruction->description[1] = 0;
        proc->instruction->description[0] = 2;
        return (true);
    }
    if (proc->instruction->description)
        free(proc->instruction->description);
    proc->instruction->description = parse_description(proc->pc->val);
    if (!proc->instruction->description)
        return (false);
    proc->pc = proc->pc->next;
    return (true);
}

void parse_arguments_from_mem(proc_t *proc)
{
    int size;

    for (int i = 0; proc->instruction->description[i]; i++) {
        if (proc->instruction->description[i] == 3 ||
            (proc->instruction->description[i] == 2 &&
            uses_indexes_corewar(proc->instruction->code)))
            size = IND_SIZE;
        else if (proc->instruction->description[i] == 2)
            size = DIR_SIZE;
        else
            size = 1;
        proc->instruction->args[i] = get_argument_from_mem(proc, size);
    }
}

bool parse_instruction_from_mem(proc_t *proc)
{
    proc->instruction->size = 2;
    proc->instruction->code = proc->pc->val;
    proc->pc = proc->pc->next;
    if (!is_instruction_code_valid_corewar(proc->instruction->code)) {
        proc->instruction->code = 0;
        return (true);
    }
    if (!get_description_from_mem(proc))
        return (false);
    if (!instruction_is_valid_corewar(proc->instruction)) {
        proc->pc = proc->pc->prev;
        proc->instruction->code = 0;
        return (true);
    }
    parse_arguments_from_mem(proc);
    if (!registers_are_valid(proc->instruction)) {
        proc->pc = go_n_prev(proc->pc, proc->instruction->size - 1);
        proc->instruction->code = 0;
    }
    return (true);
}
