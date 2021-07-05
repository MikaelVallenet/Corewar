/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cycle_loop
*/

#include <stdio.h>
#include "corewar.h"

static int require_continue(global_t *global)
{
    if (global->nbr_cycle_dump > 0 &&
        global->cycle >= global->nbr_cycle_dump)
        return (0);
    if (get_progs_size(global) < 1)
        return (0);
    return (1);
}

void use_cycle_loop(global_t *global)
{
    while (require_continue(global)) {
        sort_progs(global);
        execute_commands(global);
        remove_dead_progs(global);
        global->cycle += 1;
    }
    show_winner(global);
}