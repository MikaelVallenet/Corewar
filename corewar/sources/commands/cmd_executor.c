/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cmd_executor
*/

#include "my.h"
#include "cmd.h"

static void test_command(global_t *global, prog_t *prog,
int address, int value)
{
    if (check_cmd(global, address)) {
        COMMANDS[value - 1].exec_function(global, prog);
        prog->last_execute = global->cycle;
    } else
        add_pc(&prog->pc, 1);
}

void execute_commands(global_t *global)
{
    int value;
    int duration;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        value = global->memory[get_execute_address(global->progs[i])];
        duration = get_command_duration(value);
        if (duration == -1 || value < 1 || value > 16)
            add_pc(&global->progs[i]->pc, 1);
        else if (global->progs[i]->last_execute == -1 || ABS(global->cycle -
        global->progs[i]->last_execute) >= duration)
            test_command(global, global->progs[i],
            get_execute_address(global->progs[i]), value);
    }
}