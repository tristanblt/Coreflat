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
    for (int j = 0; j < args; j++) {
        if (instruction->description[j] == 1 && !(op.type[j] & T_REG))
            return (false);
        if (instruction->description[j] == 2 && !(op.type[j] & T_DIR))
            return (false);
        if (instruction->description[j] == 3 && !(op.type[j] & T_IND))
            return (false);
    }
    return (true);
}
