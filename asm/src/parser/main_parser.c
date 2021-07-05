/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** parser
*/

#include <stdlib.h>
#include "asm.h"
#include "parser.h"

int parse_file(head_t *head)
{
    size_t size = 0;
    char *buffer = NULL;
    char **commands;

    parse_metadata(head);
    while (getline(&buffer, &size, head->fd) != -1 && !head->error) {
        commands = parse_commands(head, buffer);
        if (!commands || !commands[0])
            continue;
        finds_commands_error(head, commands);
    }
    label_place_label(head, head->labels);
    place_size_bytes(head);
    free(buffer);
    return (0);
}
