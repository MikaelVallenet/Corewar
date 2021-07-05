/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_get_labels
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../asm/includes/asm.h"

void get_all_label(dict_label_t **list, char *str);
void label_list_pop_first(dict_label_t **list);
void label_list_pop_block(dict_label_t **list, dict_label_t *block);
void label_list_pop_list(dict_label_t **list);

Test(test_simple_label_gest, reg)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1"
    "\n      zjmp %:live";
    label_list_pop_first(&labels);
    get_all_label(&labels, str);
    label_list_pop_first(&labels);
    label_list_pop_first(&labels);
    cr_assert_null(labels);
}

Test(test_simple_label_gest, reg2)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1"
    "\n      zjmp %:live";
    label_list_pop_list(&labels);
    get_all_label(&labels, str);
    label_add_pos(labels, "%:l2", (int [3]){30, 40, 2});
    label_list_pop_list(&labels);
    cr_assert_null(labels);
}

Test(test_simple_label_gest, reg3)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1"
    "\n      zjmp %:live";
    get_all_label(&labels, str);
    label_list_pop_block(&labels, labels->next);
    cr_assert_null(labels->next);
}