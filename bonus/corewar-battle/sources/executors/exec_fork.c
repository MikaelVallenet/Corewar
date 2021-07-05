/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** exec_fork.c
*/

#include <stdlib.h>
#include "my.h"
#include "cmd.h"

prog_t *create_prog_copy(prog_t *prog, global_t *global)
{
    prog_t *new = malloc(sizeof(prog_t));

    new->carry = prog->carry;
    my_strcpy(prog->comment, new->comment);
    new->content = malloc(sizeof(char) * prog->size);
    for (int i = 0; i < prog->size; i++)
        new->content[i] = global->memory[select_address(prog->address + i)];
    new->id = prog->id;
    new->last_execute = prog->last_execute;
    new->live_call_cyle = prog->live_call_cyle;
    my_strcpy(prog->name, new->name);
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        new->registers[i] = prog->registers[i];
    new->size = prog->size;
    new->color = prog->color;
    new->pc_print = -1;
    return (new);
}

void execute_fork(global_t *global, prog_t *prog)
{
    int address = get_execute_address(prog);
    int arg = get_arg_value(global, DIR2, address + 1, prog);
    prog_t *new = create_prog_copy(prog, global);

    new->address = address + prog->size + arg % IDX_MOD;
    new->pc = prog->pc + arg % IDX_MOD;
    place_prog_at(global, new, new->address);
    add_prog(global, new);
    add_pc(&prog->pc, 3);
}