/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include <stdlib.h>
#include "asm.h"
#include "parser.h"

int pars_all_metadata(head_t *head, char *str)
{
    int name = 0;
    for (int i = 0; str[i]; i++) {
        if (pars_metadata(head, str, &i, &name))
            return (0);
    }
    exit_error(".comment or .name is invalid.");
    return (1);
}