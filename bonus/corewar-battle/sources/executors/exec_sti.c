/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_sti
*/

#include "cmd.h"

void execute_sti(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    arg_type_t args[3] = {REG, get_argument_type(global, address, 2),
    get_argument_type(global, address, 3)};
    int reg = get_arg_value_mod(global, REG, address + 2, prog);
    int arg2 = get_arg_value_mod(global, args[1], address + 3, prog);
    int a2_size = get_type_size(args[1]);
    int arg3 = get_arg_value_mod(global, args[2], address + 3 + a2_size, prog);
    int add = arg2 + arg3;

    write_4bytes(global, address + add % IDX_MOD, reg);
    print_prog_case(prog, address + add % IDX_MOD, 4, global);
    prog->carry = (reg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}