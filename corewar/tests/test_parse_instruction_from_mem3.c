/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_parse_instruction_from_mem3
*/

#include <criterion/criterion.h>
#include "corewar.h"
#include "my.h"

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
