/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_instruction
*/

#include "asm.h"
#include "my.h"

int get_instruction_id_next(char *start_line)
{
    if (my_strcmp(start_line, "sti"))
        return (IC_sti);
    if (my_strcmp(start_line, "fork"))
        return (IC_fork);
    if (my_strcmp(start_line, "lld"))
        return (IC_lld);
    if (my_strcmp(start_line, "lldi"))
        return (IC_lldi);
    if (my_strcmp(start_line, "lfork"))
        return (IC_lfork);
    if (my_strcmp(start_line, "aff"))
        return (IC_aff);
    return (-1);
}

int get_instruction_id(char *start_line)
{
    if (my_strcmp(start_line, "live"))
        return (IC_live);
    if (my_strcmp(start_line, "ld"))
        return (IC_ld);
    if (my_strcmp(start_line, "st"))
        return (IC_st);
    if (my_strcmp(start_line, "add"))
        return (IC_add);
    if (my_strcmp(start_line, "sub"))
        return (IC_sub);
    if (my_strcmp(start_line, "and"))
        return (IC_and);
    if (my_strcmp(start_line, "or"))
        return (IC_or);
    if (my_strcmp(start_line, "xor"))
        return (IC_xor);
    if (my_strcmp(start_line, "zjmp"))
        return (IC_zjmp);
    if (my_strcmp(start_line, "ldi"))
        return (IC_ldi);
    return (get_instruction_id_next(start_line));
}

int *parse_args(char **line)
{
    int n_args = my_argslen(line) - 1;
    int *args = my_calloc(n_args + 1, sizeof(int));

    if (args == NULL)
        return (NULL);
    args[n_args] = -1;
    for (int i = 0; i < n_args; i++) {
        if (argument_is_register(line[i + 1]))
            args[i] = my_get_nbr(line[i + 1] + 1);
        if (argument_is_direct(line[i + 1]))
            args[i] = my_get_nbr(line[i + 1] + 1);
        if (argument_is_indirect(line[i + 1]))
            args[i] = my_get_nbr(line[i + 1]);
    }
    return (args);
}

char *parse_description(char **line)
{
    int n_args = my_argslen(line) - 1;
    char *description = my_calloc(n_args + 1, sizeof(char));

    if (description == NULL)
        return (NULL);
    description[n_args] = -1;
    for (int i = 0; i < n_args; i++) {
        if (argument_is_register(line[i + 1]))
            description[i] = T_REG;
        if (argument_is_direct(line[i + 1]))
            description[i] = T_DIR;
        if (argument_is_indirect(line[i + 1]))
            description[i] = T_IND;
    }
    return (description);
}