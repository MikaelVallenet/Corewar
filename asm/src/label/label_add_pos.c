/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include "asm.h"
#include "./label.h"

static int go_to_label_aux(char *str, int i)
{
    for (int j = 0; j < my_strlen(LABEL_CHARS); j++) {
        if (str[i] == LABEL_CHARS[j])
            return (i);
    }
    return (-1);
}

static int go_to_label(char *str)
{
    int return_val = 0;
    for (int i = 0; i < my_strlen(str); i++){
        return_val = go_to_label_aux(str, i);
        if (return_val != -1)
            return (return_val);
    }
    return (0);
}

void label_add_pos(dict_label_t *list, char *name, int data[3])
{
    name += go_to_label(name);
    while (list != NULL) {
        if (my_strcmp(name, list->name) == 0) {
            list->appariton = int_tab_realloc(list->appariton,
            list->appariton_len, list->appariton_len + 1);
            list->appariton[list->appariton_len] = data[0];
            list->cmd_appariton = int_tab_realloc(list->cmd_appariton,
            list->appariton_len, list->appariton_len + 1);
            list->cmd_appariton[list->appariton_len] = data[1];
            list->len_appariton = int_tab_realloc(list->len_appariton,
            list->appariton_len, list->appariton_len + 1);
            list->len_appariton[list->appariton_len] = data[2];
            list->appariton_len++;
            return;
        }
        list = list->next;
    }
    exit_error("Missing Label declaration");
}
