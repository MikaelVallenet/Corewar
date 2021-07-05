/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include <stdlib.h>
#include "asm.h"
#include "parser.h"

void place_size_bytes(head_t *head)
{
    int start = 4 + PROG_NAME_LENGTH;
    int size = head->buff_len - 4 - PROG_NAME_LENGTH - 8 - COMMENT_LENGTH - 4;
    head->buffer[start + 0 + 4] = (size) >> (24);
    head->buffer[start + 1 + 4] = (size) >> (16);
    head->buffer[start + 2 + 4] = (size) >> (8);
    head->buffer[start + 3 + 4] = (size);
}