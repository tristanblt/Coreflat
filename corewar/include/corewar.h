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
typedef struct champion champion_t;
typedef struct op op_t;

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
};

struct pc {
    int cycles;
    list_t *memory;
    instruction_t *instruction;
};

struct champion {
    instruction_t **instructions;
    header_t *header;
    pc_t *pcs;
    char **registers;
};

//END STRUCTS


//PROTOTYPES

char *get_cor_file(char *path, int *size);
instruction_t **parse_instructions(char *file, int size);
header_t *parse_header(char **file, int *size);
int reverse_bytes(unsigned int x);
int reverse_bytes_two(unsigned int x);
bool start_cycle(champion_t **champions);
champion_t *create_champion(char *path);

//END PROTOTYPES

#endif /* !ASM_H_ */
