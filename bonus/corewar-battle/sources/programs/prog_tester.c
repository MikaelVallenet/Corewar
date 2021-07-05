/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** prog_tester.c
*/

#include "corewar.h"

void verify_total_size(global_t *global)
{
    int size = 0;

    for (int i = 0; global->progs[i] != NULL; i++)
        size += global->progs[i]->size;
    if (size > MEM_SIZE)
        show_error("Error: too long programs.\n");
}