/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** register
*/

#ifndef REGISTER_H_
#define REGISTER_H_

#include "../../includes/asm.h"

/* PROTOTYPE */
void label_list_push(dict_label_t **list, dict_label_t *block);
void label_list_pop_first(dict_label_t **list);
void label_list_pop_block(dict_label_t **list, dict_label_t *block);
void label_list_pop_list(dict_label_t **list);
void dict_label_creat(dict_label_t **list, char *name);
void get_all_label(dict_label_t **list, char *str);
void dict_label_creat(dict_label_t **list, char *name);
void label_add_adresse(dict_label_t *list, char *name, int address);
void label_place_label(head_t *header, dict_label_t *list);
int *int_tab_realloc(int *tab, int old_size, int new_size);


#endif /* !REGISTER_H_ */
