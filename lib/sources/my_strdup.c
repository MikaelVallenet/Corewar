/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *str)
{
    int len;
    char *result;

    if (str == NULL)
        return (NULL);
    len = my_strlen(str);
    result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = '\0';
    return (result);
}

char *my_strndup(char *str, int len)
{
    char *result;

    if (str == NULL)
        return (NULL);
    result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = '\0';
    return (result);
}