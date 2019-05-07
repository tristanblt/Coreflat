/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

// INCLUDES

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"

// END INCLUDES

#define EXIT_FAIL 84

// DEFINES

// END DEFINES


// TYPEDEFS

typedef struct instruction instruction_t;

//END TYPEDEFS

// ENUMS

enum INSTRUCTION_CODES {
    IC_live = 1,
    IC_ld,
    IC_st,
    IC_add,
    IC_sub,
    IC_and,
    IC_or,
    IC_xor,
    IC_zjmp,
    IC_ldi,
    IC_sti,
    IC_fork,
    IC_lld,
    IC_lldi,
    IC_lfork,
    IC_aff
};

// END ENUMS

// STRUCTS

struct instruction {
    char code;
    char *description;
    int *args;
    char *label;
    char **label_args;
    int size;
    int cumulative_size;
};

//END STRUCTS


//PROTOTYPES

char *get_cor_file(char *path, int *size);

//END PROTOTYPES

#endif /* !ASM_H_ */
