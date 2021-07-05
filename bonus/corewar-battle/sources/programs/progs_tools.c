/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** progs_tools
*/

#include "corewar.h"

int is_prog_id_valid(global_t *global, long id)
{
    if (global->progs == NULL)
        return (1);
    for (int i = 0; global->progs[i] == NULL; i++) {
        if (global->progs[i]->id == id)
            return (0);
    }
    return (1);
}

int is_prog_address_valid(global_t *global, int address)
{
    if (global->progs == NULL)
        return (1);
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == address)
            return (0);
    }
    return (1);
}

void remove_dead_progs(global_t *global)
{
    int redo = 0;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (ABS(global->cycle - global->progs[i]->live_call_cyle) >
        global->cycles_to_die) {
            killfeed_add_deaf(global, global->progs[i]->name);
            remove_prog(global, global->progs[i]);
            redo = 1;
            break;
        }
    }
    if (redo)
        remove_dead_progs(global);
}

void remove_all_progs(global_t *global)
{
    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++)
        remove_prog(global, global->progs[i]);
}