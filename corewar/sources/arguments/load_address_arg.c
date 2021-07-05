/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** load_address
*/

#include <stddef.h>
#include "args.h"
#include "my.h"

static void check_already_use(long nb, global_t *global)
{
    if (!is_prog_address_valid(global, nb))
        show_error("Error: This load address is already used.\n");
}

void manage_load_address_arg(char *value, args_infos_t *infos)
{
    long nb = -1;

    if (infos->load_addres != NULL)
        show_error("Error: Bad load_address argument placement.\n");
    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] < '0' && value[i] > '9')
            show_error("Error: Invalid load_address value.\n");
    }
    if (my_strcmp(value, "0") == 0) {
        nb = 0;
    } else {
        nb = my_getnbr(value);
        if (nb == 0)
            show_error("Error: Invalid load_address value.\n");
    }
    if (nb % MEM_SIZE != 0)
        show_error("Error: Invalid load_address value.\n");
    check_already_use(nb, infos->global);
    infos->load_addres = my_strdup(value);
}