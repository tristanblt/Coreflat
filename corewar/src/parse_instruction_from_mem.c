/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_instruction_from_mem
*/

#include "my.h"
#include "corewar.h"

bool uses_indexes(int code)
{
    if (code == IC_ldi || code == IC_lldi || code == IC_fork ||
        code == IC_lfork || code == IC_zjmp || code == IC_sti)
        return (true);
    return (false);
}

bool is_instruction_code_valid(char code)
{
    for (int i = 0; op_tab[i].code; i++)
        if (op_tab[i].code == code)
            return (true);
    return (false);
}

int get_argument(proc_t *proc, int size)
{
    int argument = 0;

    for (int i = 0; i < size; i++) {
        argument <<= 8;
        argument += proc->pc->val;
        proc->pc = proc->pc->next;
    }
    return (argument);
}

bool get_description(proc_t *proc)
{
    proc->pc = proc->pc->next;
    if (has_one_argument(proc->instruction->code)) {
        if (!proc->instruction->description)
            proc->instruction->description = malloc(sizeof(char) * 2);
        if (!proc->instruction->description)
            return (false);
        proc->instruction->description[1] = 0;
        proc->instruction->description[0] = T_DIR;
        if (has_one_argument(proc->instruction->code) ||
            uses_indexes(proc->instruction->code))
            proc->instruction->description[0] = T_IND;
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

bool parse_instruction_from_mem(proc_t *proc)
{
    int size = 0;

    proc->instruction->code = proc->pc->val;
    if (!is_instruction_code_valid(proc->instruction->code)) {
        proc->instruction->code = 0;
        return (true);
    }
    if (!get_description(proc))
        return (false);
    for (int i = 0; proc->instruction->description[i]; i++) {
        if (proc->instruction->description[i] == T_IND ||
            (proc->instruction->description[i] == T_DIR &&
            uses_indexes(proc->instruction->code)))
            size = IND_SIZE;
        else if (proc->instruction->description[i] == T_DIR)
            size = DIR_SIZE;
        else
            size = 1;
        proc->instruction->args[i] = get_argument(proc, size);
    }
    return (true);
}
