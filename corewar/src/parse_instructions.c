/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_instructions
*/

#include "my.h"
#include "corewar.h"

instruction_t **push_instruction_corewar(instruction_t **arr,
instruction_t *add)
{
    instruction_t **new_arr = NULL;
    int nb_elem_arr;
    int copy_elems;

    for (nb_elem_arr = 0; arr[nb_elem_arr] != NULL; nb_elem_arr++);
    new_arr = malloc(sizeof(instruction_t *) * (nb_elem_arr + 2));
    if (new_arr == NULL)
        return (NULL);
    for (copy_elems = 0; copy_elems < nb_elem_arr; copy_elems++)
        new_arr[copy_elems] = arr[copy_elems];
    new_arr[copy_elems] = add;
    new_arr[copy_elems + 1] = NULL;
    free(arr);
    return (new_arr);
}

char *parse_description(char c)
{
    char *description = malloc((1 + MAX_ARGS_NUMBER) * sizeof(char));

    if (description == NULL)
        return (NULL);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        description[MAX_ARGS_NUMBER - i - 1] = c & 3;
        c >>= 2;
    }
    description[MAX_ARGS_NUMBER] = 0;
    return (description);
}

bool has_one_argument_corewar(int code)
{
    if (code == IC_live || code == IC_zjmp || code == IC_fork ||
        code == IC_lfork)
        return (true);
    return (false);
}

bool parse_instruction(char **file, int *size)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));

    if (instruction == NULL)
        return (false);
    instruction->code = file[0][0];
    *file += 1;
    *size -= 1;
    if (!has_one_argument_corewar(instruction->code)) {
        instruction->description = parse_description(file[0][0]);
        if (instruction->description == NULL)
            return (false);
        *file += 1;
        *size -= 1;
    }
    else
        instruction->description = NULL;
    instruction->args = parse_args(file, size, instruction->description);
    if (instruction->args == NULL)
        return (false);
    free(instruction);
    return (true);
}

bool parse_instructions(char *file, int size)
{
    while (size > 0)
        if (!parse_instruction(&file, &size))
            return (false);
    return (true);
}
