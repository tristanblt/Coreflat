/*
** EPITECH PROJECT, 2019
** parse_instruction_from_file.c
** File description:
** parses the instruction form the file
*/

#include "disasm.h"
#include <stdlib.h>
#include "my.h"

bool instruction_is_valid(instruction_t *instruction)
{
    op_t op = {0};
    int expected = 0;
    int args = my_strlen(instruction->description);

    for (int i = 0; op_tab[i].code; i++)
        if (instruction->code == op_tab[i].code)
            op = op_tab[i];
    if (!op.code)
        return (false);
    for (; expected < 4 && op.type[expected]; expected++);
    if (args != expected)
        return (false);
    for (int i = 0; i < args; i++)
        if (!(op.type[i] | instruction->description[i]))
            return (false);
    return (true);
}

char *parse_description(char c, char code)
{
    char *description = malloc((1 + MAX_ARGS_NUMBER) * sizeof(char));

    if (description == NULL)
        return (NULL);
    if (has_one_argument(code)) {
        description[0] = 2;
        description[1] = 0;
        return (description);
    }
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        description[MAX_ARGS_NUMBER - i - 1] = c & 3;
        c >>= 2;
    }
    description[MAX_ARGS_NUMBER] = 0;
    return (description);
}

int get_argument_from_file(char *file, int *i, int fsize, int size)
{
    int argument = 0;

    for (int j = 0; j < size; (*i)++, j++) {
        if ((*i) > fsize)
            return (0);
        argument <<= 8;
        argument |= file[*i];
    }
    return (argument);
}

bool parse_arguments(char *file, int *i, instruction_t *instruction, int fsize)
{
    int size = 0;

    instruction->args = malloc(sizeof(int) * 4);
    if (!instruction->args)
        return (false);
    for (int j = 0; instruction->description[j]; j++) {
        if (instruction->description[j] == 3 ||
            (instruction->description[j] == 2 &&
            uses_indexes(instruction->code)))
            size = IND_SIZE;
        else if (instruction->description[j] == 2)
            size = DIR_SIZE;
        else
            size = 1;
        instruction->args[j] = get_argument_from_file(file, i, fsize, size);
        if (*i > fsize)
            return (true);
    }
    return (true);
}

instruction_t *parse_instruction_from_file(char *file, int *i, int size)
{
    instruction_t *inst = malloc(sizeof(instruction_t));

    if (!inst)
        return (NULL);
    *inst = (instruction_t){0};
    if (!(inst->label_arg = malloc(sizeof(char *) * 4)))
        return (NULL);
    for (int j = 0; j < 4; j++)
        inst->label_arg[j] = NULL;
    inst->code = file[*i];
    if (++(*i) > size)
        return (NULL);
    if (!is_instruction_code_valid(inst->code)) {
        free(inst);
        return (NULL);
    }
    inst->description = parse_description(file[(*i)], inst->code);
    if ((!has_one_argument(inst->code) && ++(*i) > size) ||
        !parse_arguments(file, i, inst, size))
        return (NULL);
    return (inst);
}
