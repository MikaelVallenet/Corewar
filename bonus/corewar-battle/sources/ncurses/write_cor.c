/*
** EPITECH PROJECT, 2021
** write_cor
** File description:
** write_cor
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

void write_c(int line)
{
    (line == 0)? printw("%s", " ______   ") : 0;
    (line == 1)? printw("%s", "/\\  ___\\  ") : 0;
    (line == 2)? printw("%s", "\\ \\ \\____ ") : 0;
    (line == 3)? printw("%s", " \\ \\_____\\") : 0;
    (line == 4)? printw("%s", "  \\/_____/") : 0;
}

void write_o(int line)
{
    (line == 0)? printw("%s", " ______   ") : 0;
    (line == 1)? printw("%s", "/\\  __ \\  ") : 0;
    (line == 2)? printw("%s", "\\ \\ \\/\\ \\ ") : 0;
    (line == 3)? printw("%s", " \\ \\_____\\") : 0;
    (line == 4)? printw("%s", "  \\/_____/") : 0;
}

void write_r(int line)
{
    (line == 0)? printw("%s", " ______   ") : 0;
    (line == 1)? printw("%s", "/\\  == \\  ") : 0;
    (line == 2)? printw("%s", "\\ \\  __<  ") : 0;
    (line == 3)? printw("%s", " \\ \\_\\ \\_\\") : 0;
    (line == 4)? printw("%s", "  \\/_/ /_/") : 0;
}

void write_e(int line)
{
    (line == 0)? printw("%s", " ______   ") : 0;
    (line == 1)? printw("%s", "/\\  ___\\  ") : 0;
    (line == 2)? printw("%s", "\\ \\  __\\  ") : 0;
    (line == 3)? printw("%s", " \\ \\_____\\") : 0;
    (line == 4)? printw("%s", "  \\/_____/") : 0;
}

void write_w(int line)
{
    (line == 0)? printw("%s", " __     __   ") : 0;
    (line == 1)? printw("%s", "/\\ \\  _ \\ \\  ") : 0;
    (line == 2)? printw("%s", "\\ \\ \\/ \".\\ \\ ") : 0;
    (line == 3)? printw("%s", " \\ \\__/\".~\\_\\") : 0;
    (line == 4)? printw("%s", "  \\/_/   \\/_/") : 0;
}