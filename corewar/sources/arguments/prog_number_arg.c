/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** prog_number_arg
*/

#include <stddef.h>
#include "my.h"
#include "args.h"

static void check_already_used(global_t *global, long nb)
{
    if (!is_prog_id_valid(global, nb))
        show_error("Error: This program number is already used.\n");
}

void manage_prog_number_arg(char *value, args_infos_t *infos)
{
    long nb = -1;

    if (infos->prog_nbr != NULL)
        show_error("Error: Bad prog_number argument placement.\n");
    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] < '0' && value[i] > '9')
            show_error("Error: Invalid prog_number value.\n");
    }
    if (my_strcmp(value, "0") == 0) {
        infos->prog_nbr = my_strdup(value);
    } else {
        nb = my_getnbr(value);
        if (nb == 0)
            show_error("Error: Invalid prog_number value.\n");
        infos->prog_nbr = my_strdup(value);
    }
    check_already_used(infos->global, nb);
}