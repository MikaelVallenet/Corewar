/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include "asm.h"
#include "./label.h"

static int test_if_label(char *str)
{
    int i = 1;

    if (str[0] != '\n')
        return (0);
    for (i = 1; str[i] != '\0' && str[i] != ':'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            return (0);
    }
    if (str[i] != '\0')
        return (i);
    return (0);
}

int *int_tab_realloc(int *tab, int old_size, int new_size)
{
    int i = 0;

    int *temp = malloc(sizeof(int) * (new_size));
    for (i = 0; i < old_size; i++)
        temp[i] = tab[i];
    if (tab != NULL)
        free(tab);
    return (temp);
}

void label_add_adresse(dict_label_t *list, char *name, int address)
{
    while (list != NULL) {
        if (my_strcmp(name, list->name) == 0) {
            list->address = address;
            return;
        }
        list = list->next;
    }
    exit_error("Missing Label declaration");
}

void get_all_label(dict_label_t **list, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#')
            for (; str[i] && str[i] != '\n'; i++);
        if (test_if_label(str + i) != 0) {
            dict_label_creat(list, str + i);
        }
    }
}