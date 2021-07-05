/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** pc_printer
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

static void reprint_pc(prog_t *prog)
{
    int x = 0;
    int y = 3;
    int address = prog->pc_print;

    for (int i = 0; i < address; i++) {
        x++;
        if (x >= COLS + 1) {
            x = 0;
            y++;
        }
    }
    move(y, x);
    attron(COLOR_PAIR(prog->color));
    addch(prog->name[0]);
    attroff(COLOR_PAIR(prog->color));
    refresh();
}

void print_pc(prog_t *prog, global_t *global)
{
    int x = 0;
    int y = 3;
    int address = get_execute_address(prog);

    if (prog->pc_print != -1)
        reprint_pc(prog);
    for (int i = 0; i < address; i++) {
        x++;
        if (x >= COLS + 1) {
            x = 0;
            y++;
        }
    }
    move(y, x);
    attron(COLOR_PAIR(12));
    addch(prog->name[0]);
    attroff(COLOR_PAIR(12));
    prog->pc_print = address;
    refresh();
    usleep(6 - (global->speed));
}