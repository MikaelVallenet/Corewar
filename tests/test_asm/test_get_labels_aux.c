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
void label_add_pos(dict_label_t *list, char *name, int data[3]);
void label_add_adresse(dict_label_t *list, char *name, int address);

Test(test_simple_get_label, reg4)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1"
    "\n      zjmp %:live";
    get_all_label(&labels, str);
    label_add_pos(labels, "%:live", (int [3]){10, 20, 2});
    cr_assert_eq(labels->next->cmd_appariton[0], 20);
}

Test(test_simple_get_label, reg5)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1"
    "\n      zjmp %:live";
    get_all_label(&labels, str);
    label_add_pos(labels, "%:live", (int [3]){10, 20, 2});
    label_add_pos(labels, "%:live", (int [3]){30, 40, 2});
    cr_assert_eq(labels->next->cmd_appariton[1], 40);
}

Test(test_simple_get_label, reg6)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1"
    "\n      zjmp %:live";

    get_all_label(&labels, str);
    label_add_adresse(labels, "live", 10);
    cr_assert_eq(labels->next->address, 10);
}