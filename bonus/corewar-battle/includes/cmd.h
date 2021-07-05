/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** Header cmd
*/

#ifndef CMD_H
#define CMD_H

#include "corewar.h"

#define NO 0
#define REG 1
#define DIR2 2
#define DIR4 4
#define IND 3

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
    void (*exec_function)(global_t*, prog_t*);
} cmd_t;

void execute_and(global_t *global, prog_t *prog);
void execute_live(global_t *global, prog_t *prog);
void execute_sti(global_t *global, prog_t *prog);
void execute_zjmp(global_t *global, prog_t *prog);
void execute_xor(global_t *global, prog_t *prog);
void execute_or(global_t *global, prog_t *prog);
void execute_aff(global_t *global, prog_t *prog);
void execute_fork(global_t *global, prog_t *prog);
void execute_lfork(global_t *global, prog_t *prog);
void execute_ld(global_t *global, prog_t *prog);
void execute_st(global_t *global, prog_t *prog);
void execute_ldi(global_t *global, prog_t *prog);
void execute_lldi(global_t *global, prog_t *prog);
void execute_add(global_t *global, prog_t *prog);
void execute_sub(global_t *global, prog_t *prog);
void execute_lld(global_t *global, prog_t *prog);

static const cmd_t COMMANDS[] = {
    {1, 10, 0, 1, {{DIR4, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &execute_live},
    {2, 5, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}}, &execute_ld},
    {3, 5, 1, 2, {{REG, NO, NO}, {IND, REG, NO}, {NO, NO, NO}}, &execute_st},
    {4, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, &execute_add},
    {5, 10, 1, 3, {{REG, NO, NO}, {REG, NO, NO}, {REG, NO, NO}}, &execute_sub},
    {6, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
    &execute_and},
    {7, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
    &execute_or},
    {8, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG, NO, NO}},
    &execute_xor},
    {9, 20, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &execute_zjmp},
    {10, 25, 1, 3, {{REG, DIR2, IND}, {DIR2, REG, NO}, {REG, NO, NO}},
    &execute_ldi},
    {11, 25, 1, 3, {{REG, NO, NO}, {REG, DIR2, IND}, {DIR2, REG, NO}},
    &execute_sti},
    {12, 800, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}},
    &execute_fork},
    {13, 10, 1, 2, {{DIR4, IND, NO}, {REG, NO, NO}, {NO, NO, NO}},
    &execute_lld},
    {14, 50, 1, 3, {{REG, DIR2, IND}, {REG, DIR2, NO}, {REG, NO, NO}},
    &execute_lldi},
    {15, 1000, 0, 1, {{DIR2, NO, NO}, {NO, NO, NO}, {NO, NO, NO}},
    &execute_lfork},
    {16, 2, 1, 1, {{REG, NO, NO}, {NO, NO, NO}, {NO, NO, NO}}, &execute_aff}
};

prog_t *create_prog_copy(prog_t *prog, global_t *global);

#endif /* !CMD_H */