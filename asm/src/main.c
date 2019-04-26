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
    header_t *header = NULL;

    if (!arguments_handling(ac, av))
        return (EXIT_FAIL);
    if ((instructions = error_handling_and_parsing(av[1], &header)) == NULL)
        return (EXIT_FAIL);
    // calc prog_size
    // labels management
    if (!encode_instructions_to_file(my_strdup(av[1]), instructions, header)) {
        free_instructions(instructions);
        return (EXIT_FAIL);
    }
    free_instructions(instructions);
    free_header(header);
    return (EXIT_SUCCESS);
}
