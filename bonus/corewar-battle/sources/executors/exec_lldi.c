/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_lldi
*/

#include "cmd.h"

void execute_lldi(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1),
    get_argument_type(global, address, 2), REG};
    int arg1 = get_arg_value(global, args[0], address + 2, prog);
    int a1_size = get_type_size(args[0]);
    int arg2 = get_arg_value(global, args[1], address + 2 + a1_size, prog);
    int a2_size = get_type_size(args[1]);
    int value = get_4bytes_arg(global, address + arg1 + arg2);
    int reg = global->memory[select_address(address + 2 + a1_size + a2_size)];

    prog->registers[reg - 1] = value;
    prog->carry = (value == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}