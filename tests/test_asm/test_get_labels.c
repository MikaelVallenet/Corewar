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

Test(test_simple_get_label, reg)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living program\"\n\n"
    "l2:   sti r1, %:live, %1\n      and r1, %0, r1\nlive: live %1\n      "
    "zjmp %:live";

    get_all_label(&labels, str);
    cr_assert_not_null(labels);
}

Test(test_simple_get_label, reg2)
{
    dict_label_t *labels = NULL;
    char *str = "#blob\n.name \"zork\"\n.comment \"just a basic living program"
    "\"\n\nl2:   sti r1, %:live, %1\n      and"
    " r1, %0, r1\nlive";

    get_all_label(&labels, str);
    cr_assert_not_null(labels);
}

Test(test_simple_get_label, reg3)
{
    dict_label_t *labels = NULL;
    char *str = ".name \"zork\"\n.comment \"just a basic living "
    "program\"\n\nl2:   sti r1, %:live, %1\n"
    "      and r1, %0, r1\nlive: live %1\n      zjmp %:live";

    get_all_label(&labels, str);
    label_add_pos(labels, "%:live", (int [3]){10, 20, 2});
    cr_assert_eq(labels->next->appariton[0], 10);
}