/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** Header
*/

#ifndef COREWAR
#define COREWAR

#include <stddef.h>
#include "op.h"

typedef int arg_type_t;

typedef struct prog_s {
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int pc;
    int carry;
    long id;
    int live_call_cyle;
    int address;
    long size;
    char *content;
    int *registers;
    int last_execute;
} prog_t;

typedef struct global_s {
    long nbr_cycle_dump;
    long cycle;
    int cycles_to_die;
    int *memory;
    char *last_alive;
    int last_live_id;
    int live_calls;
    prog_t **progs;
} global_t;

/* GENERAL */

void show_help(int argc, char **argv);
void show_error(char *msg);
void manage_args(int argc, char **argv, global_t *global);
void parse_cor_file(char *file, char *prog_nbr,
char *load_address, global_t *global);
void verify_file(char *path, char **buffer);
void use_cycle_loop(global_t *global);
void show_winner(global_t *global);
void execute_commands(global_t *global);
void verify_total_size(global_t *global);

/* PROGS TOOLS */

int get_progs_size(global_t *global);
void add_prog(global_t *global, prog_t *prog);
void remove_prog(global_t *global, prog_t *prog);
int get_first_valid_id(global_t *global);
int is_prog_id_valid(global_t *global, long id);
int is_prog_address_valid(global_t *global, int address);
void remove_dead_progs(global_t *global);
void remove_all_progs(global_t *global);
void sort_progs(global_t *global);
void place_progs(global_t *global);
int can_place_prog(global_t *global, prog_t *prog, int address);
void place_prog_at(global_t *global, prog_t *prog, int address);

/* CMDS TOOLS */

int get_execute_address(prog_t *prog);
int get_command_duration(int id);
void add_pc(int *pc, int nb);
int check_cmd(global_t *global, int address);
int select_address(int address);
arg_type_t get_argument_type(global_t *global, int cmd_address, int arg);
long get_4bytes_arg(global_t *global, int address);
int get_2bytes_arg(global_t *global, int address);
int get_type_size(arg_type_t type);
void write_4bytes(global_t *global, int address, int value);
void write_new_pc(prog_t *prog, arg_type_t args[3], int has_ocp);
long get_arg_value(global_t *global, arg_type_t type,
int address, prog_t *prog);
long get_arg_value_mod(global_t *global, arg_type_t type,
int address, prog_t *prog);

#endif /* !COREWAR */