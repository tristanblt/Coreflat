/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "my.h"
#include "asm.h"

int main(int ac, char **av)
{
    instruction_t **instructions = NULL;

    if (!arguments_handling(ac, av))
        return (EXIT_FAIL);
    if ((instructions = error_handling_and_parsing(av[1])) == NULL)
        return (EXIT_FAIL);
    if (!encode_instructions_to_file(my_strdup(av[1]), instructions)) {
        free_instructions(instructions);
        return (EXIT_FAIL);
    }
    free_instructions(instructions);
    return (EXIT_SUCCESS);
}
