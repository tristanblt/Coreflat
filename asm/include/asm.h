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

bool encode_instructions_to_file(char *file_name, instruction_t **instructions,
header_t *header);
bool arguments_handling(int ac, char **av);
instruction_t **error_handling_and_parsing(char *file_path, header_t **header);
char **get_file(FILE *fd);
void *my_memset(void *alloced, char c, int count);
char *my_strncpy(char *dest, char const *src, int n);
char **multiple_split(char *str, char *split);
int my_arrlen(char **arr);
int my_argslen(char **arr);
bool has_one_argument(int code);

void free_double_arr(char **arr);
void free_instructions(instruction_t **arr);
void free_header(header_t *header);

// error handling
bool argument_is_valid(char *argument, char type);
bool char_is_in_string(char c, char *str);
char instruction_get_code(char **line, char **label_name, char **labels);

// parsing
int get_instruction_id(char *start_line);
int *parse_args(char **line);
char *parse_description(char **line);
bool argument_is_indirect(char *argument);
bool argument_is_register(char *argument);
bool argument_is_direct(char *argument);
bool argument_is_label(char *argument);
void clean_comments(char *line);
header_t *get_header(char **file);
int get_instruction_size(instruction_t *instruction);

// writing
void write_n_zeros(int n, int fd);
void write_header(header_t *header, int fd);
void write_description(char *description, int fd);
void write_reverse_bytes(int arg, char size, int fd);
void write_with_good_size(char c, int arg, int fd, int code);

// utils
bool line_is_empty(char *line);
bool is_a_label(char *str);
int get_arg_number(int code);
bool uses_indexes(int code);

// labels
int compute_instruction_size(instruction_t **instructions);
int labels_get_values(instruction_t **instructions);
bool check_multiple_label_definitions(instruction_t **instructions);

//END PROTOTYPES

#endif /* !ASM_H_ */
