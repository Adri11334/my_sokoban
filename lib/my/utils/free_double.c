/*
** EPITECH PROJECT, 2022
** my lib
** File description:
** freezer (minishell1)
*/

#include <stddef.h>

int free_double_char(char **array)
{
    if (array == NULL)
        return -1;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return 0;
}
