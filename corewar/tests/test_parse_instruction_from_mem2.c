/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_parse_instruction_from_mem2
*/

#include <criterion/criterion.h>
#include "corewar.h"
#include "my.h"

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
    char *av[] = {"./corewar", "tests/files/Gagnant.cor",
        "tests/files/mortel.cor", NULL};

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

Test(corewar, simple_test_error)
{
    champion_t **champions = malloc(sizeof(champion_t *));
    list_t *memory = create_list();
    int dump = -1;
    int ac = 3;
    char *av[] = {"./corewar", "tests/files/ebola.cor",
        "tests/files/maxidef.cor", NULL};

    champions[0] = NULL;
    argument_handling(ac, av, &champions, &dump);
    load_champion_instructions_in_mem(champions, memory);
    cr_assert(start_corewar(champions, memory, dump));
}