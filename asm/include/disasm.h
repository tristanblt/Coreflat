/*
** EPITECH PROJECT, 2019
** disasm
** File description:
** header file for disasm
*/

#ifndef DISASM
#define DISASM

#include "op.h"
#include <stdbool.h>

typedef struct instruction instruction_t;

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

struct instruction
{
    int cumulative_size;
    int size;
    int code;
    char *description;
    int *args;
    char **label_arg;
    char *label;
};

int reverse_bytes(unsigned int x);
int reverse_bytes_two(unsigned int x);
header_t *parse_header(char *file_path, char **file_content);
instruction_t *parse_instruction_from_file(char *file, int *i, int size);
bool has_one_argument(int code);
bool uses_indexes(int code);
void destroy_instructions(instruction_t **insts);
void fill_label_args(instruction_t **insts);
void write_header(header_t *header, int fd);
void write_instructions(instruction_t **instructions, int fd);
char *get_inst_name(int code);
int get_arg_size(char arg, int code);
bool parse_header_and_instruction(header_t **, instruction_t ***, char *);
void compute_instructions_sizes(instruction_t **insts);
bool is_instruction_code_valid(char code);

#endif
