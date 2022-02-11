/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** check_map
*/

#include <stddef.h>

int map_is_valid(const char *map)
{
    int index = 0;

    if (map == NULL)
        return 84;
    while (map[index] != '\0') {
        if (map[index] != ' ' && map[index] != '\n' && map[index] != '#'
        && map[index] != 'X' && map[index] != 'O' && map[index] != 'P')
            return 84;
        index++;
    }
    return 0;
}
