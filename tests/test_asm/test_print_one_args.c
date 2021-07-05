/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_parse_commands
*/

#include <criterion/criterion.h>
#include "../../asm/includes/asm.h"
void print_one_args(head_t *head, char c, char *str);
void init_head(head_t *head, char **av);
void add_buff_char(head_t *head, char c);
long my_getlongnbr(char const *str);

Test(print_one_args, reg)
{
    head_t head;
    char *str = malloc(sizeof(char) * 3);

    my_strcpy("r2", str);
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    print_one_args(&head, REG, str);
    cr_assert_eq(head.buff_len, 1);
}

Test(print_one_args, dir4)
{
    head_t head;
    char *str = malloc(sizeof(char) * 3);

    my_strcpy("%23", str);
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    print_one_args(&head, DIR4, str);
    cr_assert_eq(head.buff_len, 4);
}

Test(print_one_args, dir2)
{
    head_t head;
    char *str = malloc(sizeof(char) * 3);

    my_strcpy("%2", str);
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    print_one_args(&head, DIR2, str);
    cr_assert_eq(head.buff_len, 2);
}

Test(print_one_args, null)
{
    head_t head;

    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    print_one_args(&head, 0, "23");
    cr_assert_null(head.buffer);
}

Test(print_one_args, ind)
{
    head_t head;
    char *str = malloc(sizeof(char) * 3);

    my_strcpy("23", str);
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.labels = NULL;
    head.fd = 0;
    print_one_args(&head, IND, str);
    cr_assert_eq(head.buff_len, 2);
}