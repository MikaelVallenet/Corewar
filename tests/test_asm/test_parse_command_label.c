/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_parse_commands
*/

#include <criterion/criterion.h>
#include "../../asm/includes/asm.h"
#include "../../asm/src/label/label.h"
void init_head(head_t *head, char **av);
void add_buff_char(head_t *head, char c);
long my_getlongnbr(char const *str);
int check_lab(char *str);
int print_label_minus(head_t *head, char c, char *str);

Test(print_label_minus, dir_duo_classico)
{
    head_t head;
    int nb;

    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = malloc(sizeof(dict_label_t));
    head.fd = 0;
    head.labels->name = malloc(sizeof(char) * 8);
    my_strcpy("live", head.labels->name);
    head.labels->next = NULL;
    nb = print_label_minus(&head, DIR2, "%:live") & 0;
    cr_assert_eq(nb, 0);
}

Test(check_lab, good_lab)
{
    char *str = "%:live";
    int nb;

    nb = check_lab(str);
    cr_assert_eq(nb, 2);
}

Test(check_lab, bad_lab)
{
    char *str = "%:li(ve";
    int nb;

    nb = check_lab(str);
    cr_assert_eq(nb, 0);
}