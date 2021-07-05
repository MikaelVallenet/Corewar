/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** metadata
*/

#include <stdlib.h>
#include "asm.h"
#include "parser.h"

static int check_after_meta(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] != '"' && str[i] != ' ' && str[i] != '\t')
            return (1);
    }
    return (0);
}

static void parse_metadata_name(char *str, head_t *head, int *i)
{
    int count = 0;

    *i += 5;
    for (; (str[*i] == ' ' || str[*i] == '\t') && str[*i] != '"'
    && str[*i] != '\0'; *i += 1);
    if (str[*i] != '"')
        exit_error("Incorrect .name.");
    *i += 1;
    while (str[*i] != '"' && str[*i] != '\0'){
        add_buff_char(head, str[*i]);
        *i += 1;
        count++;
    }
    if (check_after_meta(str + *i))
        exit_error("Incorrect .name.");
    if (count > PROG_NAME_LENGTH)
        exit_error(".name too long.");
    while (count++ < PROG_NAME_LENGTH) {
        add_buff_char(head, 0);
    }
}

static void parse_metadata_comment(char *str, head_t *head, int *i)
{
    int count = 0;

    *i += 8;
    for (; (str[*i] == ' ' || str[*i] == '\t') && str[*i] != '"'
    && str[*i] != '\0'; *i += 1);
    if (str[*i] != '"')
        exit_error("Incorect comment.");
    *i += 1;
    while (str[*i] != '"' && str[*i] != '\0') {
        add_buff_char(head, str[*i]);
        *i += 1;
        count++;
    }
    if (check_after_meta(str + *i))
        exit_error("Incorect comment.");
    if (count > COMMENT_LENGTH)
        exit_error(".comment too long.");
    while (count++ < COMMENT_LENGTH + 4) {
        add_buff_char(head, 0);
    }
}

int pars_metadata(head_t *head, char *str, int *i, int *name)
{
    if (str[*i] == '#')
        for (; str[*i] && str[*i] != '\n'; *i += 1);
    if (my_strncmp(str + *i, ".name", 5) == 0) {
        parse_metadata_name(str, head, i);
        for (int j = 0; j < 8; j++)
            add_buff_char(head, 0);
        *name = 1;
    }
    if (*name && my_strncmp(str + *i, ".comment", 8) == 0) {
        parse_metadata_comment(str, head, i);
        return (1);
    }
    return (0);
}

void parse_metadata(head_t *head)
{
    get_all_label(&head->labels, head->file_content);
    for (int i = 0; i < 4; i++)
        add_buff_char(head, MAGIC_HEADER[i]);
    pars_all_metadata(head, head->file_content);
}