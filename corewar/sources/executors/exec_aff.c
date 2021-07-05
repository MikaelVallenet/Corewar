/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_aff
*/

#include "my.h"
#include "cmd.h"

void execute_aff(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int reg = get_arg_value(global, REG, address + 2, prog);
    char c = reg % 256;

    my_putchar(c);
    prog->carry = (c == 0) ? 1 : 0;
    add_pc(&prog->pc, 3);
}