/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef CORE_H_
#define CORE_H_

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

#define USAGE "USAGE\n      ./corewar [-dump nbr_cycle] \
[[-n prog_number] [-a load_address] prog_name] ...\n\n\
DESCRIPTION\n      -dump nbr_cycle dumps the memory after \
the nbr_cycle execution (if the round isn’t\n                      \
already over) with the following \
format: 32 bytes/line in\n                      \
hexadecimal (A0BCDEFE1DD3...)\n      \
-n prog_number  sets the next program’s number.  \
By default, the first free number\n                      \
in the parameter order\n      \
-a load_address sets the next program’s \
loading address.  When no address is\n                      \
specified, optimize the addresses \
so that the processes are as far\n                      \
away from each other as possible. The addresses are MEM_SIZE modulo"

// END DEFINES

// GLOBALS VAR

extern int nbr_lives;
extern int cycle_to_die;

// END GLOBALS VAR

// TYPEDEFS

typedef struct instruction instruction_t;
typedef struct champion champion_t;
typedef struct proc proc_t;
typedef struct list_t list_t;
typedef struct fct fct_t;

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

struct fct {
    bool (*fct)(proc_t ***, int);
    int code;
};

struct instruction {
    char code;
    char *description;
    int *args;
};

struct proc {
    bool is_active;
    int cycles;
    instruction_t *instruction;
    champion_t *champion;
    list_t *pc;
    int carry;
    int *registers;
};

struct champion {
    char *instructions;
    int start_offset;
    header_t *header;
    int last_live;
    bool dead;
    int prog_number;

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
bool parse_instructions(char *file, int size);
header_t *parse_header(char **file, int *size);
int reverse_bytes(unsigned int x);
int reverse_bytes_two(unsigned int x);
bool start_corewar(champion_t **champions, list_t *memory);
champion_t *create_champion(char *path, int n, int a);
champion_t **push_champion(champion_t **arr, champion_t *add);
proc_t **init_processes(champion_t **champions, list_t *memory);
bool load_champion_instructions_in_mem(champion_t **champ, list_t *mem);
bool parse_instruction_from_mem(proc_t *proc);
char *parse_description(char c);
bool has_one_argument(int code);
bool instruction_is_valid(instruction_t *instruction);
bool uses_indexes(int code);
bool is_instruction_code_valid(char code);
void dump_memory(list_t *mem);
int get_nb_from_mem(list_t *mem, int size, int offset);
proc_t **push_proc(proc_t **arr, proc_t *add);
bool argument_error_handling(char **av);
bool end_of_file(char *path, char *end);
bool argument_handling(int ac, char **av, champion_t ***champions);

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

// instructions

bool add(proc_t ***procs, int i);
bool aff(proc_t ***procs, int i);
bool and(proc_t ***procs, int i);
bool fork_vm(proc_t ***procs, int i);
bool ld(proc_t ***procs, int i);
bool ldi(proc_t ***procs, int i);
bool lfork(proc_t ***procs, int i);
bool live(proc_t ***procs, int i);
bool lld(proc_t ***procs, int i);
bool lldi(proc_t ***procs, int i);
bool or(proc_t ***procs, int i);
bool st(proc_t ***procs, int i);
bool sti(proc_t ***procs, int i);
bool sub(proc_t ***procs, int i);
bool xor(proc_t ***procs, int i);
bool zjmp(proc_t ***procs, int i);
int get_value_from_instrution(proc_t *proc, int arg);
proc_t *create_new_proc(proc_t *proc);
void store_at_index_two(list_t *pc, int value, int index);

//END PROTOTYPES

#endif /* !CORE_H_ */
