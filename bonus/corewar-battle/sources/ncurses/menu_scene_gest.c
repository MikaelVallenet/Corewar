/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** colors_manager
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

void process_speed(menu_t *all)
{
    int max_x = 0;
    int max_y = 0;

    getmaxyx(stdscr, max_y, max_x);
    if (all->key == KEY_RIGHT)
        all->selecte_pos++;
    if (all->key == KEY_LEFT)
        all->selecte_pos--;
    if (all->selecte_pos < 0)
        all->selecte_pos = 2;
    if (all->key == '\n') {
        all->settings[0] = all->selecte_pos;
        all->selecte_pos = 1;
        all->scene = DIFF;
    }if (all->key == KEY_BACKSPACE && all->key != all->last_key) {
        all->selecte_pos = 0;
        all->scene = START;
    }
    all->selecte_pos %= 3;
    disp_speed_selection(all, max_x, max_y);
}

void process_diff(menu_t *all)
{
    int max_x = 0;
    int max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    if (all->key == KEY_RIGHT)
        all->selecte_pos++;
    if (all->key == KEY_LEFT)
        all->selecte_pos--;
    if (all->selecte_pos < 0)
        all->selecte_pos = 2;
    if (all->key == '\n') {
        all->settings[1] = all->selecte_pos;
        all->ifRunning = 1;
        all->selecte_pos = 1;
        all->scene = START;
    }if (all->key == KEY_BACKSPACE && all->key != all->last_key) {
        all->selecte_pos = 0;
        all->scene = SPEED;
    }
    all->selecte_pos %= 3;
    disp_diff_selection(all, max_x, max_y);
}

int scene_gest(menu_t *all)
{
    draw_title();
    if (all->scene == START){
        process_start(all);
        if (all->scene != START)
            return (1);
    }
    if (all->scene == SPEED){
        process_speed(all);
        if (all->scene != SPEED)
            return (1);
    }
    if (all->scene == DIFF){
        process_diff(all);
        if (all->scene != DIFF)
            return (1);
    }
    return (0);
}
