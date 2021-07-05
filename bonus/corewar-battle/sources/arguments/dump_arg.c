/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** dump_arg
*/

#include <stdlib.h>
#include "my.h"
#include "args.h"

void manage_dump_arg(char *value, args_infos_t *infos)
{
    long cycles = 0;
    char *base_ten;

    for (int i = 0; value[i] != '\0'; i++) {
        if (!((value[i] >= 'A' && value[i] <= 'F') ||
        (value[i] >= '0' && value[i] <= '9')))
            show_error("Error: Invalid dump value.\n");
    }
    base_ten = my_convert_base(value, "0123456789ABCDEF", "0123456789");
    cycles = my_getnbr(base_ten);
    free(base_ten);
    if (cycles <= 0)
        show_error("Error: Invalid dump value.\n");
    if (infos->dump != NULL)
        free(infos->dump);
    infos->dump = my_strdup(value);
    infos->global->nbr_cycle_dump = cycles;
}