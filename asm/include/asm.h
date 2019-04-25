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
    char code; // the var which stock the enum which correspond to the instruction
    char *description; // the description of arguments
    int *args;
    char *label;
};

//END STRUCTS


//PROTOTYPES

bool encode_instructions_to_file(char *file_name, instruction_t **instructions);
bool arguments_handling(int ac, char **av);
instruction_t **error_handling_and_parsing(char *file_path);
char **get_file(FILE *fd);
void *my_memset(void *alloced, char c, int count);
char *my_strncpy(char *dest, char const *src, int n);
char **multiple_split(char *str, char *split);
int my_arrlen(char **arr);
int my_argslen(char **arr);

void free_double_arr(char **arr);
void free_instructions(instruction_t **arr);

// error handling
bool argument_is_valid(char *argument, char type);
bool char_is_in_string(char c, char *str);
char instruction_get_code(char **line);

// parsing
int get_instruction_id(char *start_line);
int *parse_args(char **line);
char *parse_description(char **line);
bool argument_is_indirect(char *argument);
bool argument_is_register(char *argument);
bool argument_is_direct(char *argument);
void clean_comments(char *line);

//END PROTOTYPES

#endif /* !ASM_H_ */
