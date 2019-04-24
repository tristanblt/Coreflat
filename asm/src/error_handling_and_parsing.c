/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_handling_and_parsing
*/

#include "my.h"
#include "asm.h"

bool is_an_instruction(char *line)
{
    if (line[0] == 10)
        return (false);
    if (line[0] == '#')
        return (false);
    return (true);
}

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

instruction_t *check_and_parse_instruction(char **line)
{
    instruction_t *instruction = my_calloc(1, sizeof(instruction_t));

    instruction->code = IC_add;

    // JUST TO PAS SEGFAULT
    instruction->description = my_calloc(1, sizeof(char));
    instruction->description[0] = NULL;
    instruction->args = my_calloc(1, sizeof(int));
    instruction->args[0] = NULL;
    // END JUST TO PAS SEGFAULT
    return (instruction);
}

instruction_t **get_instructions_array(char **file)
{
    instruction_t **instructions = my_calloc(1, sizeof(instruction_t *));
    instruction_t *tmp_instr = NULL;
    char **line = NULL;

    instructions[0] = NULL;
    for (int i = 0; file[i] != NULL; i++) {
        if (!is_an_instruction(file[i]))
            continue;
        if ((line = multiple_split(file[i], " ,")) == NULL)
            return (NULL);
        tmp_instr = check_and_parse_instruction(line);
        free_double_arr(line);
        if (tmp_instr == NULL)
            return (NULL);
        if ((instructions = push_instruction(instructions, tmp_instr)) == NULL)
            return (NULL);
    }
    free_double_arr(file);
    return (instructions);
}

instruction_t **error_handling_and_parsing(char *file_path)
{
    FILE *fd = fopen(file_path, "r");
    char **file = NULL;

    if (fd == NULL)
        return (NULL);
    if ((file = get_file(fd)) == NULL)
        return (NULL);
    fclose(fd);
    return (get_instructions_array(file));
}