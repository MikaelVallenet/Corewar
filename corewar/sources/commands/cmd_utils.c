/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cmd_utils
*/

#include "cmd.h"

/**
** Get argument type
** /!\ The command need to have an OCP code
** @param global_t* Global
** @param int Address of the command
** @param int Argument number
*/
arg_type_t get_argument_type(global_t *global, int cmd_address, int arg)
{
    int cmd = global->memory[select_address(cmd_address)] - 1;
    int ocp = global->memory[select_address(cmd_address + 1)];
    int result = (ocp >> 6) & 3;
    int arg2 = (ocp >> 4) & 3;
    int arg3 = (ocp >> 2) & 3;

    if (arg == 2)
        result = arg2;
    if (arg == 3)
        result = arg3;
    for (int i = 0; i < 3; i++) {
        if (COMMANDS[cmd].args_types[i].arg1 == DIR4 ||
        COMMANDS[cmd].args_types[i].arg2 == DIR4 ||
        COMMANDS[cmd].args_types[i].arg3 == DIR4)
            result = (result == DIR2) ? DIR4 : result;
    }
    if (!COMMANDS[cmd].has_op_code || result == NO)
        return (COMMANDS[cmd].args_types[arg - 1].arg1);
    return (result);
}

/**
** Get a 4 bytes arguments value
** @param global_t* Global var
** @param int MSB Adress of argument
** @return long Argument value
*/
long get_4bytes_arg(global_t *global, int address)
{
    int value = global->memory[select_address(address)];

    for (int i = 1; i < 4; i++)
        value = (value << 8) + global->memory[select_address(address + i)];
    return (value);
}

/**
** Get a 2 bytes arguments value
** @param global_t* Global var
** @param int MSB Adress of argument
** @return int Argument value
*/
int get_2bytes_arg(global_t *global, int address)
{
    int value = global->memory[select_address(address)] & 255;

    value = ((value << 8) & 65280) +
    (global->memory[select_address(address + 1)] & 255);
    return (value);
}

long get_arg_value(global_t *global, arg_type_t type,
int address, prog_t *prog)
{
    if (type == REG)
        return (prog->registers[global->memory[select_address(address)] - 1]);
    if (type == IND)
        return (get_4bytes_arg(global, select_address(
        get_2bytes_arg(global, address) + prog->address + prog->pc)));
    if (type == DIR2)
        return (get_2bytes_arg(global, address));
    return (get_4bytes_arg(global, address));
}

long get_arg_value_mod(global_t *global, arg_type_t type,
int address, prog_t *prog)
{
    if (type == REG)
        return (prog->registers[global->memory[select_address(address)] - 1]);
    if (type == IND)
        return (get_4bytes_arg(global, select_address(
        get_2bytes_arg(global, address) % IDX_MOD +
        prog->address + prog->pc)));
    if (type == DIR2)
        return (get_2bytes_arg(global, address));
    return (get_4bytes_arg(global, address));
}
