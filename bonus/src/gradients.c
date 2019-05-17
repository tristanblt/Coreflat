/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** gradients
*/

#include "coreflat.h"

void evolve_gradient(sfColor *gradient)
{
    static bool r_sens = false;
    static bool g_sens = false;
    static bool b_sens = false;

    gradient->a = 255;
    if (gradient->r < 100 || gradient->r > 200)
        r_sens = !r_sens;
    if (gradient->g < 100 || gradient->g > 200)
        g_sens = !g_sens;
    if (gradient->b < 100 || gradient->b > 200)
        b_sens = !b_sens;
    gradient->r+= r_sens ? 1 : -1;
    gradient->g+= g_sens ? -1 : 1;
    gradient->b+= b_sens ? 1 : -1;
}
