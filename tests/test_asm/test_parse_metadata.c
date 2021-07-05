/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** test_get_labels
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../asm/includes/asm.h"

void parse_metadata(head_t *head);
char *my_strdup(char *str);

Test(test_simple_metatdata, reg)
{
    head_t head;
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.file_content = my_strdup(".name \"zork\"\n.comment \"just a\"");
    parse_metadata(&head);
    cr_assert_str_eq(head.buffer + 4, "zork");
}

Test(test_simple_metatdata, reg2)
{
    head_t head;
    head.buffer = NULL;
    head.buff_len = 0;
    head.buffer_start = head.buffer;
    head.error = 0;
    head.file_content = my_strdup("#bob\n.name \"zork\"\n.comment \"jssss\"");
    parse_metadata(&head);
    cr_assert_str_eq(head.buffer + 4, "zork");
}