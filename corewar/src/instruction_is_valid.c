/*
** EPITECH PROJECT, 2019
** instruction_is_valid
** File description:
** checks if the instruction is valid
*/

#include "my.h"
#include "corewar.h"

bool instruction_is_valid_corewar(instruction_t *instruction)
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
