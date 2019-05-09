/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_instructions
*/

#include "my.h"
#include "corewar.h"

instruction_t **push_instruction(instruction_t **arr, instruction_t *add)
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
    char *description = malloc(4 * sizeof(char));
    char offset = 0;
    unsigned char temp;

    if (description == NULL)
        return (NULL);
    for (int i = 0; i < 4; i++)
        description[i] = 0;
    for (int i = 0; i < 4; i++) {
        temp = c;
        temp <<= offset;
        temp >>= 6;
        offset += 2;
        description[i] = temp;
    }
    return (description);
}

bool has_one_argument(int code)
{
    if (code == IC_live || code == IC_zjmp || code == IC_fork ||
        code == IC_lfork)
        return (true);
    return (false);
}

int *parse_args(char **file, int *size, char *description)
{
    int *args = malloc(sizeof(int) * 4);

    if (args == NULL)
        return (NULL);
    for (int i = 0; i < 4; i++)
        args[i] = 0;
    if (description == NULL) {
        args[0] = reverse_bytes(*(int *)(*file));
        *file += 4;
        *size -= 4;
        return (args);
    }
    for (int i = 0; description[i]; i++)
        switch (description[i])
        {
        case 1: args[i] = file[0][0];
            *file += 1;
            *size -= 1;
            break;
        case 2: args[i] = reverse_bytes(*(int *)(*file));
            *file += 4;
            *size -= 4;
            break;
        case 3: args[i] = reverse_bytes_two(*(short *)(*file));
            *file += 2;
            *size -= 2;
            break;
        }
    return (args);
}

instruction_t *parse_instruction(char **file, int *size)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));

    if (instruction == NULL)
        return (NULL);
    instruction->code = file[0][0];
    *file += 1;
    *size -= 1;
    if (!has_one_argument(instruction->code)) {
        instruction->description = parse_description(file[0][0]);
        if (instruction->description == NULL)
            return (NULL);
        *file += 1;
        *size -= 1;
    }
    else
        instruction->description = NULL;
    instruction->args = parse_args(file, size, instruction->description);
    if (instruction->args == NULL)
        return (NULL);
    return (instruction);
}

instruction_t **parse_instructions(char *file, int size)
{
    instruction_t **instructions = malloc(sizeof(instruction_t));
    instruction_t *temp = NULL;

    while (size > 0) {
        temp = parse_instruction(&file, &size);
        if (temp == NULL)
            return (NULL);
        instructions = push_instruction(instructions, temp);
    }
    return (instructions);
}