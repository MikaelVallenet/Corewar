/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** progs_manager
*/

#include <stdlib.h>
#include "corewar.h"

int get_progs_size(global_t *global)
{
    int size = 0;

    if (global->progs == NULL)
        return (0);
    for (; global->progs[size] != NULL; size++);
    return (size);
}

/**
** Add an allocated program to programs list
** @param global_t* Global var
** @param prog_t* Allocated prog to add
*/
void add_prog(global_t *global, prog_t *prog)
{
    int size = get_progs_size(global);
    prog_t **new = malloc(sizeof(prog_t*) * (size + 2));

    new[size + 1] = NULL;
    new[size] = prog;
    if (global->progs == NULL) {
        global->progs = new;
        return;
    }
    for (int i = 0; i < size; i++)
        new[i] = global->progs[i];
    free(global->progs);
    global->progs = new;
}

void remove_prog(global_t *global, prog_t *prog)
{
    int size = get_progs_size(global);
    prog_t **new = malloc(sizeof(prog_t*) * size);
    int index = 0;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i] != prog) {
            new[index] = global->progs[i];
            index++;
        }
    }
    free(prog->content);
    free(prog->registers);
    free(prog);
    new[index] = NULL;
    free(global->progs);
    global->progs = new;
}

int get_first_valid_id(global_t *global)
{
    int id = 0;

    if (global->progs == NULL)
        return (0);
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->id == id)
            id++;
    }
    return (id);
}