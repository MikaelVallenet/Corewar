/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** progs_sorter
*/

#include "corewar.h"

static void swap_progs(global_t *global, int idx1, int idx2)
{
    prog_t *swap = global->progs[idx1];

    global->progs[idx1] = global->progs[idx2];
    global->progs[idx2] = swap;
}

static int parcour_progs(global_t *global)
{
    int sorted = 1;

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i + 1] == NULL)
            break;
        if (global->progs[i]->id > global->progs[i + 1]->id) {
            swap_progs(global, i, i + 1);
            sorted = 0;
        }
    }
    return (sorted);
}

void sort_progs(global_t *global)
{
    if (global->progs == NULL)
        return;
    while (!parcour_progs(global));
}