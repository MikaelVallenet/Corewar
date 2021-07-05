/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_lfork
*/

#include "cmd.h"

void execute_lfork(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int arg = get_arg_value(global, DIR2, address + 1, prog);
    prog_t *new = create_prog_copy(prog, global);

    new->address = address + prog->size + arg;
    new->pc = prog->pc + arg;
    place_prog_at(global, new, new->address);
    add_prog(global, new);
    add_pc(&prog->pc, 3);
}