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

// GLOBALS VAR

int nbr_lives = 0;
int cycle_to_die = CYCLE_TO_DIE;

// END GLOBALS VAR

// TYPEDEFS

typedef struct instruction instruction_t;
typedef struct champion champion_t;
typedef struct proc proc_t;
typedef struct list_t list_t;

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

struct proc {
    int cycles;
    instruction_t *instruction;
    list_t *pc;
    int carry;
};

struct champion {
    char *instructions;
    int size;
    int start_offset;
    header_t *header;
    proc_t **procs;
    int *registers;
    int last_live;
};

struct list_t
{
    char val;
    struct list_t *prev;
    struct list_t *next;
};

//END STRUCTS


//PROTOTYPES

char *get_cor_file(char *path, int *size);
instruction_t **parse_instructions(char *file, int size);
header_t *parse_header(char **file, int *size);
int reverse_bytes(unsigned int x);
int reverse_bytes_two(unsigned int x);
bool start_corewar(champion_t **champions);
champion_t *create_champion(char *path);

// list_t functions
void add_next(list_t *list, int val);
void add_prev(list_t *list, int val);
void add_n_next(list_t *list, int nb, int val);
void add_n_prev(list_t *list, int nb, int val);
list_t *create_list(void);
void clear_list(list_t *list);
void delete_in_list(list_t *list);
list_t *go_next(list_t *list);
list_t *go_n_next(list_t *list, int nb);
list_t *go_prev(list_t *list);
list_t *go_n_prev(list_t *list, int nb);


//END PROTOTYPES

#endif /* !ASM_H_ */
