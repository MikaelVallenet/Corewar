/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** colors_manager
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

static void register_colors(void)
{
    start_color();
    for (int i = 1; i < 7; i++)
        init_pair(i, COLOR_BLACK, i);
    init_pair(10, COLOR_BLUE, COLOR_BLACK);
    init_pair(11, COLOR_BLACK, COLOR_WHITE);
    init_pair(12, COLOR_WHITE, COLOR_BLACK);
    init_pair(40, COLOR_BLUE, COLOR_BLACK);
    init_pair(41, COLOR_RED, COLOR_BLACK);
    init_pair(42, COLOR_YELLOW, COLOR_BLACK);
    init_pair(43, COLOR_BLUE, COLOR_BLACK);
    init_pair(44, COLOR_GREEN, COLOR_BLACK);
    init_pair(45, COLOR_RED, COLOR_BLACK);
    init_pair(46, COLOR_YELLOW, COLOR_BLACK);
    init_pair(61, COLOR_WHITE, COLOR_BLUE);
}

void register_ncurses(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    register_colors();
}

int give_color(global_t *global)
{
    global->color += 1;
    global->color = (global->color > 7) ? 1 : global->color;
    return (global->color);
}