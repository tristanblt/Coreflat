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
    if (!encode_instructions_to_file())
        return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}
