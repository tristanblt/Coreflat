/*
** EPITECH PROJECT, 2019
** write
** File description:
** in list
*/

#include "corewar.h"

void load_in_mem(list_t *mem, char *to_write, int size, int offset)
{
    for (int i = 0; i < offset; i++)
        mem = mem->next;
    for (int i = 0; i < size; i++) {
        mem->val = to_write[i];
        mem = mem->next;
    }
}

bool check_overlap(list_t *mem, int offset, int size)
{
    for (int i = 0; i < offset; i++)
        mem = mem->next;
    for (int i = 0; i < size; i++) {
        if (mem->val)
            return (true);
        mem = mem->next;
    }
    return (false);
}

bool load_champion_instructions_in_mem(champion_t **champ, list_t *mem)
{
    int champ_count = 0;
    int offset = 0;

    for (; champ[champ_count]; champ_count++);
    offset = MEM_SIZE / champ_count;
    for (int i = 0; champ[i]; i++)
        if (champ[i]->start_offset == -1)
            champ[i]->start_offset = i * offset;
    for (int i = 0; champ[i]; i++) {
        if (check_overlap(mem, champ[i]->start_offset, champ[i]->header->prog_size))
            return (false);
        load_in_mem(mem, champ[i]->instructions,
champ[i]->header->prog_size, champ[i]->start_offset);
    }
    return (true);
}
