/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** menu_handler
*/

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"

void disp_speed_selection(menu_t *all, int max_x, int max_y)
{
    int y = max_y * 0.8;
    int x_pos[3] = {(max_x / 4) * 1, (max_x / 4) * 2, (max_x / 4) * 3};
    char words[3][7] = {"SLOW", "NORMAL", "FAST"};

    mvprintw(max_y * 0.6, x_pos[1] - my_strlen("SELECT THE SPEED:") / 2,
    "SELECT THE SPEED:");
    for (int i = 0; i < 3; i++) {
        if (all->selecte_pos == i)
            attron(A_STANDOUT);
        mvprintw(y, x_pos[i] - my_strlen(words[i]) / 2, "%s", words[i]);
        attroff(A_STANDOUT);
    }
}

void disp_diff_selection(menu_t *all, int max_x, int max_y)
{
    int y = max_y * 0.8;
    int x_pos[3] = {(max_x / 4) * 1, (max_x / 4) * 2, (max_x / 4) * 3};
    char words[3][7] = {"EASY", "MEDIUM", "HARD"};

    mvprintw(max_y * 0.6, x_pos[1] - my_strlen("SELECT THE DIFFICULTY:") / 2,
    "SELECT THE DIFFICULTY:");
    for (int i = 0; i < 3; i++) {
        if (all->selecte_pos == i)
            attron(A_STANDOUT);
        mvprintw(y, x_pos[i] - my_strlen(words[i]) / 2, "%s", words[i]);
        attroff(A_STANDOUT);
    }
}

void process_start(menu_t *all)
{
    int max_x = 0;
    int max_y = 0;
    char *word = "PRESS ANY BUTTON TO START:";

    getmaxyx(stdscr, max_y, max_x);
    mvprintw(max_y * 0.8, (max_x / 2) - my_strlen(word) / 2, "%s", word);
    if (all->key != 0 && all->key != KEY_BACKSPACE) {
        all->selecte_pos = 1;
        all->scene = SPEED;
        all->key = 0;
    }
}
