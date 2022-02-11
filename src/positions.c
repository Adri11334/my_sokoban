/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** positions
*/

#include "my_project.h"

dPos_t where_is_player(char **map)
{
    dPos_t position = { 0, 0 };

    while (map[position.y] != NULL) {
        if (map[position.y][position.x] == '\0') {
            position.x = 0;
            position.y++;
            continue;
        }
        if (map[position.y][position.x] == 'P')
            return position;
        position.x++;
    }
    position.x = -1;
    position.y = -1;
    return position;
}

dPos_t get_map_size(char **map)
{
    dPos_t dimensions = { 0, 0 };

    if (map == NULL)
        return dimensions;
    while (map[dimensions.y] != NULL) {
        while (map[dimensions.y][dimensions.x] != '\0')
            dimensions.x++;
        dimensions.y++;
    }
    return dimensions;
}
