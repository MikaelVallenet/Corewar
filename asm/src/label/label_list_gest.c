/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include "asm.h"
#include "./label.h"

void label_list_push(dict_label_t **list, dict_label_t *block)
{
    block->next = NULL;
    if (*list == NULL) {
        block->prev = block;
        *list = block;
    }else {
        block->prev = (*list)->prev;
        (*list)->prev->next = block;
        (*list)->prev = block;
    }
}

void label_list_pop_first(dict_label_t **list)
{
    dict_label_t *next_block = NULL;

    if (*list == NULL)
        return;
    next_block = (*list)->next;
    if (next_block != NULL)
        next_block->prev = (*list)->prev;
    free((*list)->name);
    if ((*list)->appariton != NULL){
        free((*list)->appariton);
        free((*list)->cmd_appariton);
        free((*list)->len_appariton);
    }
    free(*list);
    *list = next_block;
}

void label_list_pop_block(dict_label_t **list, dict_label_t *block)
{
    if (*list == block) {
        label_list_pop_first(list);
        return;
    }
    if (block->next == NULL) {
        block->prev->next = NULL;
        (*list)->prev = block->prev;
    }else {
        block->prev->next = block->next;
        block->next->prev = block->prev;
    }
    free(block->name);
    if (block->appariton != NULL){
        free(block->appariton);
        free(block->cmd_appariton);
        free(block->len_appariton);
    }
    free(block);
}

void label_list_pop_list(dict_label_t **list)
{
    while (*list != NULL)
        label_list_pop_first(list);
}

void dict_label_creat(dict_label_t **list, char *name)
{
    int length = 0;
    dict_label_t *block = NULL;

    name++;
    for (; name[length] != ':'; length++);
    block = malloc(sizeof(dict_label_t));
    block->name = malloc(length + 1);
    my_strncpy(name, block->name, length);
    block->appariton_len = 0;
    block->appariton = NULL;
    block->cmd_appariton = NULL;
    block->len_appariton = NULL;
    block->address = 0;
    block->next = NULL;
    block->prev = NULL;
    label_list_push(list, block);
}