/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include "asm.h"
#include "./label.h"

static void label_replace_buffer(dict_label_t *list, head_t *header, int pos)
{
    char *buffer = header->buffer + list->appariton[pos];
    int count = list->len_appariton[pos];

    if (count == 2) {
        buffer[0] = ((list->address - list->cmd_appariton[pos]) >> 8) & 255;
        buffer[1] = (list->address - list->cmd_appariton[pos]) & 255;
    } else {
        for (int i = 0; i < 4; i++)
            buffer[i] =
            ((list->address -
            list->cmd_appariton[pos]) >> ((3 - i) * 8)) & 255;
    }
}

void label_place_label(head_t *header, dict_label_t *list)
{
    while (list != NULL) {
        for (int i = 0; i < list->appariton_len; i++) {
            label_replace_buffer(list, header, i);
        }
        list = list->next;
    }
}