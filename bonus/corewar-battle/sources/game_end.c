/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** end__game
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#include "my.h"
#include "corewar.h"

void show_logo(void)
{
    int fd = open("sprite.txt", O_RDONLY);
    char buffer[65535];
    struct stat sb;

    stat("sprite.txt", &sb);
    if (fd == -1)
        exit(84);
    read(fd, &buffer, sb.st_size);
    buffer[sb.st_size] = 0;
    write(0, buffer, sb.st_size);
    close(fd);
}

static void write_line(int len)
{
    for (int j = 0; j < len; j++)
        addch(' ');
}

static void show_end_message(global_t *global)
{
    if (global->last_alive) {
        mvprintw(LINES / 2 - 1, COLS / 2 - 9 - my_strlen(global->last_alive)
        / 2, "The winner is : %s !", global->last_alive);
        free(global->last_alive);
    } else
        mvprintw(LINES / 2 - 1, COLS / 2 - 5, "No winner.");
    attron(A_STANDOUT);
    mvprintw(LINES / 2 + 1, COLS / 2 - 11, "[Return to main menu]");
    refresh();
    attroff(A_STANDOUT);
}

void show_winner(global_t *global)
{
    int cur;

    attroff(A_STANDOUT);
    for (int i = 1; i <= 10; i += 2) {
        cur = LINES / 2 - i / 2;
        move(cur, COLS / 2 - ((i * 4) / 2));
        for (int j = 0; j < i; j++) {
            write_line(i * 4);
            move(cur, COLS / 2 - ((i * 4) / 2));
            cur += 1;
        }
        refresh();
        usleep(50000);
    }
    show_end_message(global);
    while (getch() != 10);
}
