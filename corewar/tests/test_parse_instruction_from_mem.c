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

Test(parse_instruction_from_mem, multiple_arg_negative_numbers_test)
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
    proc->pc->next->next->next->val = 0xff;
    proc->pc->next->next->next->next->val = 0xfb;
    proc->pc->next->next->next->next->next->next->val = 1;
    cr_assert(parse_instruction_from_mem(proc));
    cr_assert(proc->instruction->args[0] == 1);
    cr_assert(proc->instruction->args[1] == -5);
    cr_assert(proc->instruction->args[2] == 1);
    cr_assert(proc->instruction->code == IC_sti);
    cr_assert(proc->pc->prev->val == 01 && proc);
}

Test(argument_handling, basic_test)
{
    champion_t **champs = malloc(sizeof(champion_t *) * 1);
    int dump = -1;
    int ac = 3;
    char *av[] = {"./corewar", "tests/files/test.cor",
        "tests/files/test.cor", NULL};

    champs[0] = 0;
    cr_assert(argument_handling(ac, av, &champs, &dump));
}

Test(argument_handling, more_arguments)
{
    champion_t **champs = malloc(sizeof(champion_t *) * 1);
    int dump = -1;
    int ac = 13;
    char *av[] = {"./corewar", "-n", "10", "-a", "101", "tests/files/test.cor",
        "-a", "6000", "-n", "100", "tests/files/test.cor", "-dump", "12", NULL};

    champs[0] = 0;
    cr_assert(argument_handling(ac, av, &champs, &dump));
    cr_assert(dump == 12);
}

Test(champion_parse, champion)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    int dump = -1;
    int ac = 3;
    char *av[] = {"./corewar", "tests/files/test.cor",
        "tests/files/test.cor", NULL};

    champions[0] = NULL;
    argument_handling(ac, av, &champions, &dump);
    cr_assert(load_champion_instructions_in_mem(champions, memory));
}

Test(champion_parse, champion_error)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    int dump = -1;
    int ac = 13;
    char *av[] = {"./corewar", "-n", "10", "-a", "101", "tests/files/test.cor",
        "-a", "6000", "-n", "100", "tests/files/test.cor", "-dump", "12", NULL};

    champions[0] = NULL;
    argument_handling(ac, av, &champions, &dump);
    cr_assert(!load_champion_instructions_in_mem(champions, memory));
}

Test(corewar, simple_test)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    int dump = -1;
    int ac = 3;
    char *av[] = {"./corewar", "tests/files/test.cor",
        "tests/files/test.cor", NULL};

    champions[0] = NULL;
    argument_handling(ac, av, &champions, &dump);
    load_champion_instructions_in_mem(champions, memory);
    cr_assert(start_corewar(champions, memory, dump));
}

Test(corewar, test_with_error)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    int dump = -1;
    int ac = 13;
    char *av[] = {"./corewar", "-n", "10", "-a", "101", "tests/files/test.cor",
        "-a", "6000", "-n", "100", "tests/files/test.cor", "-dump", "12", NULL};

    champions[0] = NULL;
    argument_handling(ac, av, &champions, &dump);
    load_champion_instructions_in_mem(champions, memory);
    cr_assert(start_corewar(champions, memory, dump));
}

Test(check_lives, simple_test)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    proc_t **procs = NULL;
    int dump = -1;
    int ac = 3;
    char *av[] = {"./corewar", "tests/files/test.cor",
        "tests/files/test.cor", NULL};

    champions[0] = NULL;
    argument_handling(ac, av, &champions, &dump);
    load_champion_instructions_in_mem(champions, memory);
    procs = init_processes(champions, memory);
    for (int i = 0; champions[i]; i++)
        champions[i]->dead = true;
    cr_assert(!check_lives(champions, procs));
}
