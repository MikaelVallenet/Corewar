/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_strcmp
*/

int my_strlen(char *str);

static int compare_strs(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] > str2[i])
            return (1);
        else if (str1[i] < str2[i])
            return (-1);
    }
    return (0);
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) > my_strlen(str2))
        return (1);
    else if (my_strlen(str1) < my_strlen(str2))
        return (-1);
    return (compare_strs(str1, str2));
}

static int comparen_strs(char *str1, char *str2, int n)
{
    for (int i = 0; str1[i] != '\0' && i < n; i++) {
        if (str1[i] > str2[i])
            return (1);
        else if (str1[i] < str2[i])
            return (-1);
    }
    return (0);
}

int my_strncmp(char *str1, char *str2, int n)
{
    return (comparen_strs(str1, str2, n));
}