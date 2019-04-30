/*
** EPITECH PROJECT, 2019
** get
** File description:
** header
*/

#include "op.h"
#include "asm.h"
#include "my.h"

header_t *init_header(void)
{
    header_t *header = malloc(sizeof(header_t));
    int magic = COREWAR_EXEC_MAGIC;

    if (!header)
        return (NULL);
    *header = (header_t){0};
    for (int i = 0; i < 4; i++) {
        header->magic <<= 8;
        header->magic |= magic & 255;
        magic >>= 8;
    }
    return (header);
}

bool line_is_empty(char *line)
{
    if (!line)
        return (true);
    for (int i = 0; line[i]; i++)
        if (line[i] != ' '&&line[i] != '\r'&&line[i] != '\n'&&line[i] != '\t')
            return (false);
    return (true);
}

void clean_name_and_comment(char *str)
{
    int i = my_strlen(str) - 1;

    while (str[i] != '"' && i)
        i--;
    if (!i)
        return;
    str[i + 1] = 0;
}

bool fill_name(char *line, header_t *header)
{
    if (!my_strncmp(NAME_CMD_STRING, line, my_strlen(NAME_CMD_STRING)))
        return (false);
    line = line + my_strlen(NAME_CMD_STRING);
    while (*line == ' ')
        line++;
    clean_name_and_comment(line);
    if (my_strlen(line) == 1 || line[0] != '"' || line[my_strlen(line) - 1] != '"')
        return (false);
    for (int i = 0, count = 0; line[i]; i++) {
        if (line[i] == '"')
            count++;
        if (count > 2)
            return (false);
    }
    (line++, line[my_strlen(line) - 1] = 0);
    if (my_strlen(line) > PROG_NAME_LENGTH)
        return (my_dprintf(2,"Error: Name too long\n")%1);
    my_strncpy(header->prog_name, line, my_strlen(line));
    return (true);
}

bool fill_comment(char *line, header_t *header)
{
    if (!my_strncmp(COMMENT_CMD_STRING, line, my_strlen(COMMENT_CMD_STRING)))
        return (false);
    line = line + my_strlen(COMMENT_CMD_STRING);
    while (*line == ' ')
        line++;
    clean_name_and_comment(line);
    if (my_strlen(line) == 1 || line[0] != '"' || line[my_strlen(line) - 1] != '"')
        return (false);
    for (int i = 0, count = 0; line[i]; i++) {
        if (line[i] == '"')
            count++;
        if (count > 2)
            return (false);
    }
    (line++, line[my_strlen(line) - 1] = 0);
    if (my_strlen(line) > COMMENT_LENGTH)
        return (my_dprintf(2,"Error: Comment too long\n")%1);
    my_strncpy(header->comment, line, my_strlen(line));
    return (true);
}

header_t *get_header(char **file)
{
    header_t *header = init_header();
    int i = 0;
    int j = 0;

    if (!header)
        return (NULL);
    while (line_is_empty(file[i]) && file[i])
        i++;
    for (j = 0; file[i] && (file[i][j] == ' ' || file[i][j] =='\t'); j++);
    if (!file[i] || fill_name(&file[i][j], header) == false)
        return (NULL);
    file[i][0] = 0;
    while (line_is_empty(file[i]) && file[i])
        i++;
    for (j = 0; file[i] && (file[i][j] == ' ' || file[i][j] =='\t'); j++);
    if (!file[i] || !fill_comment(&file[i][j], header))
        return (NULL);
    file[i][0] = 0;
    return (header);
}
