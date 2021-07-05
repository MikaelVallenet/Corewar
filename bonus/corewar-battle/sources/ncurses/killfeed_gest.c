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

void killfeed_rise_up(global_t *global)
{
    for (int i = 1; i < FEED_LINE; i++) {
        for (int j = 0; j < 32; j++)
            global->killfeed[i - 1][j] = '\0';
        my_strncpy(global->killfeed[i], global->killfeed[i - 1],
        my_strlen(global->killfeed[i]));
        for (int j = 0; j < 32; j++)
            global->killfeed[i][j] = '\0';
    }
    for (int j = 0; j < 32; j++)
        global->killfeed[FEED_LINE - 1][j] = '\0';
}

void killfeed_add_deaf(global_t *global, char *name)
{
    int len = my_strlen(name);
    char *message = malloc(len + 5 + 1);

    len += 5;
    my_strcpy(name, message);
    my_strcat(message, " died");
    message[len] = '\0';
    for (int count = 0; len > 0; count++) {
        killfeed_rise_up(global);
        my_strncpy(message + count * FEED_CHAR,
        global->killfeed[FEED_LINE - 1], FEED_CHAR);
        len -= FEED_CHAR;
    }
    free(message);
}

void display_killfeed(global_t *global)
{
    int x = 0;
    int y = 0;

    getmaxyx(stdscr, y, x);
    y = y;
    for (int i = 0; i < FEED_LINE; i++) {
        for (int j = 0; j < 32; j++)
            mvprintw(i + 38, x - FEED_CHAR + j, "%c", ' ');
    }
    for (int i = 0; i < FEED_LINE; i++) {
        mvprintw(i + 38, x - FEED_CHAR, "%s", global->killfeed[i]);
    }
}