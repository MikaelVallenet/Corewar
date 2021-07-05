/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** args Header
*/

#ifndef ARGS_H
#define ARGS_H

#include "corewar.h"

typedef struct args_infos_s {
    char *dump;
    char *prog_nbr;
    char *load_addres;
    global_t *global;
} args_infos_t;

void manage_dump_arg(char *value, args_infos_t *infos);
void manage_prog_number_arg(char *value, args_infos_t *infos);
void manage_load_address_arg(char *value, args_infos_t *infos);

#endif /* !ARGS_H */