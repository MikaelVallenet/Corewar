/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** progs_placer
*/

#include <stdio.h>
#include "corewar.h"

void place_prog_at(global_t *global, prog_t *prog, int address)
{
    for (int i = 0; i < prog->size; i++)
        global->memory[select_address(i + address)] = prog->content[i];
    prog->address = address;
}

static int test_place(prog_t *progp, prog_t *prog, int address)
{
    for (int j = progp->address; j < progp->address + progp->size; j++) {
        if (j >= address && j <= address + prog->size)
            return (0);
    }
    return (1);
}

int can_place_prog(global_t *global, prog_t *prog, int address)
{
    if (global->progs == NULL)
        return (1);
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == -1)
            continue;
        if (!test_place(global->progs[i], prog, address))
            return (0);
    }
    return (1);
}

static void place_normal(global_t *global, int space)
{
    int address = 0;

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == -1) {
            for (; !can_place_prog(global, global->progs[i],
            address); address++);
            address += (address == 0) ? 0 : space;
            place_prog_at(global, global->progs[i], address);
            address += global->progs[i]->size;
        }
    }
}

void place_progs(global_t *global)
{
    int empty = MEM_SIZE;
    int space;

    verify_total_size(global);
    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address != -1 && !can_place_prog(global,
        global->progs[i], global->progs[i]->address))
            show_error("Error: Bad champions placement.\n");
        if (global->progs[i]->address != -1) {
            empty -= global->progs[i]->size;
            place_prog_at(global, global->progs[i],
            global->progs[i]->address);
        }
    }
    space = empty / get_progs_size(global);
    place_normal(global, space);
}