/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** commands
*/

#include "asm.h"
#include "parser.h"

static void write_args_buffer(head_t *head, char **args, int i, char argv[])
{
    int opc = 0;

    if (COMMANDS[i].has_op_code) {
        opc += finds_opc_value(argv[0], 128, 64);
        opc += finds_opc_value(argv[1], 32, 16);
        opc += finds_opc_value(argv[2], 8, 4);
        add_buff_char(head, opc);
    }
    print_one_args(head, argv[0], args[1]);
    print_one_args(head, argv[1], args[2]);
    print_one_args(head, argv[2], args[3]);
}

static void check_args_command(head_t *head, char **args, int i)
{
    int nb = COMMANDS[i].args_nbr;
    int j = 0;
    char argv[] = {0, 0, 0};

    for (j = 1; args[j] != NULL; j += 1);
    if (j - 1 != nb)
        exit_error("Invalid number of args : ./get_commands l:112");
    for (int x = 0; x < nb; x += 1) {
        argv[x] += check_one_arg(COMMANDS[i].args_types[x].arg1, args[x + 1]);
        argv[x] += check_one_arg(COMMANDS[i].args_types[x].arg2, args[x + 1]);
        argv[x] += check_one_arg(COMMANDS[i].args_types[x].arg3, args[x + 1]);
    }
    for (int z = 0; z < nb; z += 1) {
        if (argv[z] == 0)
            exit_error("invalid chars arguments : ./get_commands l:120");
    }
    write_args_buffer(head, args, i , argv);
}

void finds_commands_error(head_t *head, char **args)
{
    int i;

    if (!args[0])
        exit_error("invalid line");
    head->len_commands = head->buff_len;
    for (i = 0; i < 16; i += 1) {
        if (my_strcmp(args[0], COMMANDS[i].name) == 0) {
            add_buff_char(head, COMMANDS[i].id);
            check_args_command(head, args, i);
            i = -1;
            break;
        }
    }
    if (i != -1)
        exit_error("invalid command name : ./get_command l:140");
}

void print_one_args(head_t *head, char c, char *str)
{
    long nb;

    if (c == 0)
        return;
    if (c == REG)
        add_buff_char(head, my_getlongnbr(str + 1));
    if (c == DIR4 && print_label_minus(head, c, str) == 0) {
        if (my_getlongnbr(str + 1) < 0) {
            nb = 4294967296 + my_getlongnbr(str + 1);
            add_buff_char(head, nb / 16777216);
            add_buff_char(head, nb / 65536);
            add_buff_char(head, nb / 256);
            add_buff_char(head, nb % 256);
        } else {
            add_buff_char(head, my_getlongnbr(str + 1) / 16777216);
            add_buff_char(head, my_getlongnbr(str + 1) / 65536);
            add_buff_char(head, my_getlongnbr(str + 1) / 256);
            add_buff_char(head, my_getlongnbr(str + 1) % 256);
        }
    }
    print_one_args_aux(head, c, str, nb);
}

int finds_opc_value(char c, int one, int two)
{
    if (c == REG)
        return (two);
    if (c == DIR4 || c == DIR2)
        return (one);
    if (c == IND)
        return (one + two);
    return (0);
}