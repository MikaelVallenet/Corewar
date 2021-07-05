/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** buff_tools
*/

#include <stdlib.h>
#include "asm.h"

void add_buff_str(head_t *head, char *str, int len)
{
    for (int i = 0; i < len; i += 1)
        add_buff_char(head, str[i]);
}

void add_buff_char(head_t *head, char c)
{
    char *new = malloc(sizeof(char) * (head->buff_len + 1));

    new[head->buff_len] = c;
    if (head->buffer == NULL) {
        head->buffer = new;
        head->buff_len += 1;
        return;
    }
    for (int i = 0; i < head->buff_len; i ++)
        new[i] = head->buffer[i];
    free(head->buffer);
    head->buff_len += 1;
    head->buffer = new;
}

/**
** Add a 2 or 4 bytes value
** @param head_t* Global var
** @param int Value to add
** @param int Number of bytes ( 2 or 4 )
*/
void add_42bytes_value(head_t *head, int value, int bytes)
{
    if (bytes == 4) {
        add_buff_char(head, (value >> 24) & 255);
        add_buff_char(head, (value >> 16) & 255);
    }
    add_buff_char(head, (value >> 8) & 255);
    add_buff_char(head, value & 255);
}