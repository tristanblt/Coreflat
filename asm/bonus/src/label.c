/*
** EPITECH PROJECT, 2019
** label
** File description:
** label related functions
*/

#include "disasm.h"
#include <stdlib.h>

int get_ten_pow(int nb)
{
    int pow = 1;

    while (pow * 10 <= nb)
        pow *= 10;
    return (pow);
}

void copy_label_name(int code, char *label)
{
    char *live = "live_";
    char *chossu = "chossu_";
    static int last_chossu = 0;
    static int last_live = 0;
    char *str = chossu;
    int last_nb = last_chossu;
    int j = 0;

    if (code == 1) {
        str = live;
        last_nb = last_live;
    }
    for (; str[j]; j++)
        label[j] = str[j];
    for (int p = get_ten_pow(last_nb); p > 0; p /= 10, j++)
        label[j] = (last_nb / p) % 10 + '0';
    label[j] = 0;
    if (code != 1)
        last_chossu++;
    else
        last_live++;
}

char *get_label(int nb, int cumul_size, instruction_t **insts)
{
    int size = nb + cumul_size;
    int i = 0;

    if (!nb)
        return (NULL);
    for (; insts[i]; i++)
        if (size == insts[i]->cumulative_size)
            break;
    if (!insts[i])
        return (NULL);
    if (insts[i]->label)
        return (insts[i]->label);
    insts[i]->label = malloc(sizeof(char) * 15);
    copy_label_name(insts[i]->code, insts[i]->label);
    return (insts[i]->label);
}

void fill_label_args(instruction_t **insts)
{
    for (int i = 0; insts[i]; i++)
        for (int j = 0; insts[i]->description[j]; j++) {
            insts[i]->description[j] != 1 ?
            insts[i]->label_args[j] = get_label(insts[i]->args[j],
        insts[i]->cumulative_size, insts) : 0;
        }
}
