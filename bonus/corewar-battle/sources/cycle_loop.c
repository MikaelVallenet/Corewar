/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cycle_loop
*/

#include <ncurses.h>
#include <unistd.h>
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

static void define_menus_changes(global_t *global)
{
    if (global->difficulty == 0)
        global->cycles_delta = 1;
    else if (global->difficulty == 2)
        global->cycles_delta = 9;
}

void use_cycle_loop(global_t *global)
{
    define_menus_changes(global);
    while (require_continue(global)) {
        usleep(200 - (global->speed * 80));
        sort_progs(global);
        execute_commands(global);
        remove_dead_progs(global);
        global->cycle += 1;
        display_killfeed(global);
        print_cycle(global);
    }
    show_winner(global);
    endwin();
    show_logo();
}
