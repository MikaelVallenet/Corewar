/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** end__game
*/

#include <stdlib.h>
#include "my.h"
#include "corewar.h"

void show_winner(global_t *global)
{
    if (global->last_alive == NULL) {
        my_putstr("No winner !\n");
        return;
    }
    my_putstr("The player ");
    my_putnbr(global->last_live_id);
    my_putchar('(');
    my_putstr(global->last_alive);
    my_putstr(")has won.\n");
    free(global->last_alive);
}