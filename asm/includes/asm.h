/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** Header
*/

#ifndef ASM
#define ASM

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../lib/includes/my.h"
#include "op.h"

typedef struct dict_label_s dict_label_t;

typedef struct head_s {
    char *buffer;
    char *buffer_start;
    FILE *fd;
    char *file_content;
    int buff_len;
    int len_commands;
    int error;
    dict_label_t *labels;
} head_t;

typedef struct dict_label_s {
    char *name;
    int *appariton;
    int *cmd_appariton;
    int *len_appariton;
    int appariton_len;
    int address;
    struct dict_label_s *next;
    struct dict_label_s *prev;
} dict_label_t;

#define NO 0
#define REG 1
#define DIR2 2
#define DIR4 4
#define IND 3

typedef char arg_type_t;

typedef struct valid_args_s {
    arg_type_t arg1;
    arg_type_t arg2;
    arg_type_t arg3;
} valid_args_t;

typedef struct cmd_s {
    int id;
    int duration;
    int has_op_code;
    int args_nbr;
    valid_args_t args_types[3];
    char *name;
} cmd_t;

static const cmd_t COMMANDS[] = {
    {1, 10, 0, 1, {{DIR4, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "live"},
    {2, 5, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, "ld"},
    {3, 5, 1, 2, {{REG, NO, NO}, {IND, REG, NO}, {NO, NO, NO}}, "st"},
    {4, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, "add"},
    {5, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, "sub"},
    {6, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}}, "and"},
    {7, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}}, "or"},
    {8, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}}, "xor"},
    {9, 20, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "zjmp"},
    {10, 25, 1, 3, {{REG, DIR2, IND}, {DIR2, REG, NO}, {REG, NO, NO}}, "ldi"},
    {11, 25, 1, 3, {{REG, NO, NO}, {REG, DIR2, IND}, {DIR2, REG, NO}}, "sti"},
    {12, 800, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "fork"},
    {13, 10, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, "lld"},
    {14, 50, 1, 3, {{REG, DIR2, IND}, {REG, DIR2, NO}, {REG, NO, NO}}, "lldi"},
    {15, 1000, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "lfork"},
    {16, 2, 1, 1, {{REG, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, "aff"}
};

static const char MAGIC_HEADER[4] = {0, 234, 131, 243};

/* GLOBAL */

void handle_error(int argc, char **argv);
void init_head(head_t *head, char **av);
void destroy_head(head_t *head);
void file_writer(head_t *head, char *filepath);

/* TOOLS */

int read_file(char *file_path, char **buffer);
int get_file_size(char *file_path);
void add_buff_char(head_t *head, char c);
void add_42bytes_value(head_t *head, int value, int bytes);
int fread_file(FILE *fd, char **buffer);
int get_file_fsize(FILE *file);
int verify_char_lab(char a, char b);
void print_one_args_aux(head_t *head, char c, char *str, long nb);

/* PARSING COMMANDS */

void finds_commands_error(head_t *head, char **args);
void print_one_args(head_t *head, char c, char *str);
int check_lab(char *str);
int check_one_arg(int t, char *arg);
int check_reg(char *str);
int check_ind(char *str);
int check_dir(char *str, int type);
int finds_opc_value(char c, int one, int two);
int print_label_minus(head_t *head, char c, char *str);
int print_label_ind(head_t *head, char c, char *str);

/* PARSER */
int parse_file(head_t *head);

/* LABEL */
void get_all_label(dict_label_t **list, char *str);
void label_add_adresse(dict_label_t *list, char *name, int address);
void label_add_pos(dict_label_t *list, char *name, int data[3]);
void label_place_label(head_t *header, dict_label_t *list);
void label_list_pop_list(dict_label_t **list);

#include "error.h"

#endif /* !ASM */