/*
** EPITECH PROJECT, 2021
** Corwar
** File description:
** Header op
*/

#ifndef OP_H
#define OP_H

#define MEM_SIZE (6*1024)
#define IDX_MOD 512
#define MAX_ARGS_NUMBER 4

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

#define REG_NUMBER 16

typedef char args_type_t;

#define T_REG 1
#define T_DIR2 2
#define T_DIR4 4
#define T_IND 2
#define T_LAB 8

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;


#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

#define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#endif