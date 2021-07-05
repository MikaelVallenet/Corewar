/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_strcpy
*/

char *my_strcpy(char *str, char *dest)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *str, char *dest, int len)
{
    int i = 0;

    for (; str[i] != '\0' && i < len; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}