/*
** EPITECH PROJECT, 2019
** test
** File description:
** short file description
*/

#include <criterion/criterion.h>
#include "corewar.h"
#include "my.h"

Test(parse_instruction_from_mem, one_arg_test)
{
    proc_t *proc = malloc(sizeof(proc_t));

    if (!proc)
        return;
    *proc = (proc_t){0};
    if (!(proc->instruction = malloc(sizeof(instruction_t))) ||
        !(proc->pc = create_list()) ||
        !(proc->instruction->args = malloc(sizeof(int) * 4)))
        return;
    proc->pc->val = IC_fork;
    proc->pc->next->val = 1;
    cr_assert(parse_instruction_from_mem(proc));
    cr_assert(proc->instruction->args[0] == 256);
    cr_assert(proc->instruction->code == IC_fork);
    cr_assert(proc->pc->prev->prev->prev->val == IC_fork);
}

Test(parse_instruction_from_mem, multiple_arg_test)
{
    proc_t *proc = malloc(sizeof(proc_t));

    if (!proc)
        return;
    *proc = (proc_t){0};
    if (!(proc->instruction = malloc(sizeof(instruction_t))) ||
        !(proc->pc = create_list()) ||
        !(proc->instruction->args = malloc(sizeof(int) * 4)))
        return;
    proc->pc->val = IC_sti;
    proc->pc->next->val = 0x68;
    proc->pc->next->next->val = 1;
    proc->pc->next->next->next->next->val = 7;
    proc->pc->next->next->next->next->next->next->val = 1;
    cr_assert(parse_instruction_from_mem(proc));
    cr_assert(proc->instruction->args[0] == 1);
    cr_assert(proc->instruction->args[1] == 7);
    cr_assert(proc->instruction->args[2] == 1);
    cr_assert(proc->instruction->code == IC_sti);
    cr_assert(proc->pc->prev->val == 01 && proc);
}
