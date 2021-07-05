/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** menu_handler
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

void open_menu(global_t *global)
{
    int ch = 0;
    global->menu = (menu_t){0};
    while (!global->menu.ifRunning) {
        clear();
        if (scene_gest(&global->menu)) {
            global->menu.last_key = global->menu.key;
            global->menu.key = 0;
            continue;
        }
        global->menu.last_key = 0;
        refresh();
        global->menu.key = wgetch(stdscr);
        if (ch == global->menu.key)
            continue;
        ch = global->menu.key;
        if (global->menu.key == 27)
            global->menu.ifRunning = 1;
    }
    global->speed = global->menu.settings[0];
    global->difficulty = global->menu.settings[1];
}