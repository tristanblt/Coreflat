/*
** EPITECH PROJECT, 2019
** write file
** File description:
** writes the header and the instructions
*/

#include "disasm.h"
#include "my.h"

void write_instruction_args(instruction_t *inst, int fd)
{
    for (int i = 0; inst->description[i]; i++) {
        if (inst->description[i] == 1)
            my_dprintf(fd, "r");
        if (inst->description[i] == 2)
            my_putchar(fd, '%');
        if (inst->label_arg[i])
            my_dprintf(fd, ":%s%c", inst->label_arg[i],
            inst->description[i + 1] ? ' ' : '\n');
        else
            my_dprintf(fd, "%d%c", inst->args[i],
            inst->description[i + 1] ? ' ' : '\n');
    }
}

void write_instructions(instruction_t **instructions, int fd)
{
    int len = 0;

    for (int i = 0; instructions[i]; i++) {
        len = 0;
        if (instructions[i]->label) {
            my_dprintf(fd, "\n%s:", instructions[i]->label);
            len = my_strlen(instructions[i]->label);
        }
        for (; len < 15; len += 8)
            my_dprintf(fd, "\t");
        my_dprintf(fd, "%s ", get_inst_name(instructions[i]->code));
        write_instruction_args(instructions[i], fd);
    }
}

void write_header(header_t *header, int fd)
{
    my_dprintf(fd, "%s \"%s\"\n", NAME_CMD_STRING, header->prog_name);
    my_dprintf(fd, "%s \"%s\"\n\n", COMMENT_CMD_STRING, header->comment);
}
