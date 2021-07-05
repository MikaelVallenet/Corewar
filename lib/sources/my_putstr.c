/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_putstr
*/

#include <unistd.h>

int my_strlen(char *str);

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}