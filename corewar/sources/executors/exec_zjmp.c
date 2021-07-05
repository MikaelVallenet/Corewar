/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_zjmp
*/

#include <stdio.h>
#include "cmd.h"

void execute_zjmp(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int add = get_2bytes_arg(global, address + 1);

    if (prog->carry)
        add_pc(&prog->pc, add);
    else
        add_pc(&prog->pc, 3);
}