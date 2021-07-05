/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** file_writer
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

static char *create_filepath(char *str)
{

    char *fp = malloc(sizeof(char) * (my_strlen(str) + 3));
    int i = 0;
    int j = 0;

    for (i = my_strlen(str) - 1; str[i - 1] != '/' && i > 0; i -= 1);
    for (; str[j] != '\0'; j += 1) {
        if (str[j] == '/') {
            j = -1;
            break;
        }
    }
    if (j != - 1)
        i = 0;
    fp = my_strcpy(str + i, fp);
    fp[my_strlen(fp) - 1] = '\0';
    my_strcat(fp, "cor");
    return (fp);
}

void file_writer(head_t *head, char *filepath)
{
    char *fp = create_filepath(filepath);
    int fd = open(fp, O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        exit_error("Can't write a file.\n");
    } else {
        write(fd, head->buffer, head->buff_len);
    }
    free(fp);
    close(fd);
}