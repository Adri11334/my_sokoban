/*
** EPITECH PROJECT, 2022
** my utils lib
** File description:
** my_puterror
*/

#include <unistd.h>

void write_red(char *str);

int put_error(char *str)
{
    if (str != NULL)
        write_red(str);
    return 84;
}
