/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** printer
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

static void move_if_required(int address, int i, int *moved)
{
    if (address + i >= MEM_SIZE && !*moved) {
        move(3, 0);
        *moved = 1;
    }
}

void print_prog_case(prog_t *prog, int address, int bytes, global_t *global)
{
    int x = 0;
    int y = 3;
    int moved = 0;

    for (int i = 0; i < address; i++) {
        x++;
        if (x >= COLS + 1) {
            x = 0;
            y++;
        }
    }
    move(y, x);
    attron(COLOR_PAIR(prog->color));
    for (int i = 0; i < bytes; i++) {
        move_if_required(address, i, &moved);
        usleep(1800 - (global->speed * 600));
        addch(prog->name[0]);
        refresh();
    }
    attroff(COLOR_PAIR(prog->color));
}

void show_start_panel(global_t *global)
{
    clear();
    move(1, COLS / 2 - 4);
    attron(COLOR_PAIR(10));
    printw("COREWAR");
    attroff(COLOR_PAIR(10));
    attron(COLOR_PAIR(61));
    move(36, 0);
    for (int i = 0; i < COLS; i++)
        addch('=');
    attroff(COLOR_PAIR(61));
    attron(COLOR_PAIR(11));
    move(3, 0);
    for (int i = 0; i < MEM_SIZE; i++)
        addch(' ');
    attroff(COLOR_PAIR(11));
    mvprintw(40, 5, "Champions alive : %d", get_progs_size(global));
    mvprintw(42, 5, "Cycle : 0");
    mvprintw(44, 5, "Actions : 0");
    mvprintw(46, 5, "Killing cycles : 0");
    refresh();
}

void print_cycle(global_t *global)
{
    move(40, 23);
    printw("%d", get_progs_size(global));
    for (int i = 0; i < 10; i++)
        addch(' ');
    move(42, 13);
    printw("%d", global->cycle);
    move(44, 15);
    printw("%d", global->actions);
    move(46, 22);
    printw("%d", global->cycles_to_die);
    for (int i = 0; i < 10; i++)
        addch(' ');
    move(3, 0);
    refresh();
}