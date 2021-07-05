/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** main
*/

#include <stdlib.h>
#include "corewar.h"

int main(int argc, char **argv)
{
    global_t global = {-1, 0, CYCLE_TO_DIE, NULL, NULL, -1, 0, NULL};

    global.memory = malloc(sizeof(int) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        global.memory[i] = 0;
    manage_args(argc, argv, &global);
    place_progs(&global);
    use_cycle_loop(&global);
    remove_all_progs(&global);
    free(global.memory);
    free(global.progs);
    return (0);
}