/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_parse_commands
*/

#include <criterion/criterion.h>
#include "../../asm/includes/asm.h"
void init_head(head_t *head, char **av);
void add_buff_char(head_t *head, char c);
long my_getlongnbr(char const *str);

Test(finds_commands_error, dir_classical)
{
    head_t head;
    char **tab = malloc(sizeof(char*) * 5);

    tab[0] = my_strdup("live");
    tab[1] = my_strdup("%2");
    tab[2] = NULL;
    tab[3] = NULL;
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    finds_commands_error(&head, tab);
    cr_assert_eq(head.buff_len, 5);
}

Test(finds_commands_error, sti)
{
    head_t head;
    char **tab = malloc(sizeof(char*) * 5);

    tab[0] = my_strdup("sti");
    tab[1] = my_strdup("r2");
    tab[2] = my_strdup("23");
    tab[3] = my_strdup("%2");
    tab[4] = NULL;
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    finds_commands_error(&head, tab);
    cr_assert_eq(head.buff_len, 7);
}