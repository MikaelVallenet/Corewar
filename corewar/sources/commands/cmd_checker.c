/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cmd_checker
*/

#include <stdio.h>
#include "cmd.h"

static int verify_args(int cmd, int arg1, int arg2, int arg3)
{
    if (COMMANDS[cmd].args_types[0].arg1 != arg1 && COMMANDS[cmd].args_types
    [0].arg2 != arg1 && COMMANDS[cmd].args_types[0].arg3 != arg1)
        return (0);
    if (COMMANDS[cmd].args_nbr > 1 && COMMANDS[cmd].args_types[1].arg1 != arg2
    && COMMANDS[cmd].args_types[1].arg2 != arg2 && COMMANDS[cmd].args_types
    [1].arg3 != arg2)
        return (0);
    if (COMMANDS[cmd].args_nbr > 2 && COMMANDS[cmd].args_types[2].arg1 != arg3
    && COMMANDS[cmd].args_types[2].arg2 != arg3 && COMMANDS[cmd].args_types
    [2].arg3 != arg3)
        return (0);
    return (1);
}

static int check_ocp(global_t *global, int address)
{
    int cmd = global->memory[select_address(address)] - 1;
    int arg1;
    int arg2;
    int arg3;

    if (!COMMANDS[cmd].has_op_code)
        return (1);
    arg1 = get_argument_type(global, address, 1);
    arg2 = get_argument_type(global, address, 2);
    arg3 = get_argument_type(global, address, 3);
    if (!verify_args(cmd, arg1, arg2, arg3))
        return (0);
    return (1);
}

static int get_parcour_value(global_t *global, int address, int cmd, int arg)
{
    if (!COMMANDS[cmd].has_op_code ||
    get_argument_type(global, address, arg) == NO) {
        return (get_type_size(COMMANDS[cmd].args_types[arg - 1].arg1));
    }
    return (get_type_size(get_argument_type(global, address, arg)));
}

static int check_registers(global_t *global, int address)
{
    int cmd = global->memory[select_address(address)] - 1;
    int parcour = address + 2;

    if (!COMMANDS[cmd].has_op_code)
        parcour -= 1;
    for (int i = 0; i < COMMANDS[cmd].args_nbr; i++) {
        if (get_parcour_value(global, address, cmd, i + 1) == T_REG &&
        (global->memory[select_address(parcour)] > 16 ||
        global->memory[select_address(parcour)] < 1))
                return (0);
        parcour += get_parcour_value(global, address, cmd, i + 1);
    }
    return (1);
}

/**
** Check the command
** @param int Command address
** @return int 1 if correct, 0 if incorrect
*/
int check_cmd(global_t *global, int address)
{
    int cmd = global->memory[select_address(address)];

    if (cmd < 1 || cmd > 16)
        return (0);
    if (!check_ocp(global, address))
        return (0);
    if (!check_registers(global, address))
        return (0);
    return (1);
}
