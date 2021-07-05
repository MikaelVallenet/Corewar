/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** write_cor2
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

void write_a(int line)
{
    (line == 0)? printw("%s", " ______   ") : 0;
    (line == 1)? printw("%s", "/\\  __ \\  ") : 0;
    (line == 2)? printw("%s", "\\ \\  __ \\ ") : 0;
    (line == 3)? printw("%s", " \\ \\_\\ \\_\\") : 0;
    (line == 4)? printw("%s", "  \\/_/\\/_/") : 0;
}

void draw_title(void)
{
    int max_x = 0;
    int max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    void (*wites[7])(int) = {write_c, write_o, write_r, write_e, write_w,
    write_a, write_r};
    for (int i = 0; i < 5; i++) {
        move(i + 0.1 * max_y, max_x / 2 - 79 / 2);
        for (int j = 0; j < 7; j++) {
            attron(COLOR_PAIR(40 + j));
            wites[j](i);
            attroff(COLOR_PAIR(40 + j));
            (j != 6)? printw(" ") : 0;
        }
    }
}