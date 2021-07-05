/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_add
*/

#include "cmd.h"

void execute_add(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int val1 = get_arg_value(global, REG, address + 2, prog);
    int val2 = get_arg_value(global, REG, address + 3, prog);
    int reg = global->memory[select_address(address + 4)];
    int result = val1 + val2;

    prog->registers[reg - 1] = result;
    prog->carry = (result == 0) ? 1 : 0;
    add_pc(&prog->pc, 5);
}