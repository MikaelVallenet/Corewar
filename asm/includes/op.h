/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** header op.h
*/

#ifndef OP_H
#define OP_H

#define MEM_SIZE (6*1024)
#define IDX_MOD 512 // modulo of the index <
#define MAX_ARGS_NUMBER 4 // this may not be changed 2^*IND_SIZE

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

/* regs */

#define REG_NUMBER 16 // r1 <--> rx

/* ** */

typedef char args_type_t;

#define T_REG 1 // register
#define T_DIR2 2 // direct  (ld  #1,r1  put 1 into r1)
#define T_DIR4 4
#define T_IND 4 // indirect always relative
#define T_LAB 8 // LABEL

/* header */
#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

#endif