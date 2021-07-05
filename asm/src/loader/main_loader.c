/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** main_loader
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

void destroy_head(head_t *head)
{
    fclose(head->fd);
    if (head->buffer)
        free(head->buffer);
    free(head);
}

void init_head(head_t *head, char **av)
{
    head->buff_len = 0;
    head->buffer = NULL;
    head->buffer_start = head->buffer;
    head->error = 0;
    head->labels = NULL;
    head->fd = fopen(av[1], "r");
    if (head->fd == NULL)
        OPEN_ERROR;
    fread_file(head->fd, &head->file_content);
    fseek(head->fd, 0, SEEK_SET);
}