/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_lld
*/

#include "cmd.h"

void execute_lld(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1), REG,
    NO};
    int arg1 = get_arg_value(global, args[0], address + 2, prog);
    int a1_size = get_type_size(args[0]);
    int reg = global->memory[select_address(address + 2 + a1_size)];

    prog->registers[reg - 1] = arg1;
    prog->carry = (arg1 == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}