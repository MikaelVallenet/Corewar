/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** args_manager
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "args.h"

static void manage_flag(int argc, char **argv, int i, args_infos_t *infos)
{
    if (i + 1 >= argc)
        show_error("Error: Invalid number of arguments.\n");
    if (my_strcmp(argv[i], "-dump") == 0) {
        manage_dump_arg(argv[i + 1], infos);
        return;
    }
    if (my_strcmp(argv[i], "-n") == 0) {
        manage_prog_number_arg(argv[i + 1], infos);
        return;
    }
    if (my_strcmp(argv[i], "-a") == 0)
        manage_load_address_arg(argv[i + 1], infos);
    else
        show_error("Error: Invalid argument.\n");
}

static void manage_file(char *path, args_infos_t *infos, global_t *global)
{
    char *buffer;

    verify_file(path, &buffer);
    parse_cor_file(buffer, infos->prog_nbr, infos->load_addres, global);
    if (infos->prog_nbr != NULL) {
        free(infos->prog_nbr);
        infos->prog_nbr = NULL;
    }
    if (infos->load_addres != NULL) {
        free(infos->load_addres);
        infos->load_addres = NULL;
    }
    free(buffer);
}

/**
** Manage arguments
** @param int argc
** @param char** argv
** @param global_t* Global structure
*/
void manage_args(int argc, char **argv, global_t *global)
{
    args_infos_t infos = {NULL, NULL, NULL, global};

    show_help(argc, argv);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            manage_flag(argc, argv, i, &infos);
            i++;
        } else
            manage_file(argv[i], &infos, global);
    }
    if (infos.dump != NULL)
        free(infos.dump);
    if (get_progs_size(global) < 2)
        show_error("Error: 2 champions minimum are required.\n");
}