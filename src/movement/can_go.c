/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** can_go
*/

#include "my_project.h"

#include <unistd.h>

int can_push_box(char **map, char **v_map, dPos_t next_pos, dPos_t nnext_pos)
{
    if (map[next_pos.y][next_pos.x] == 'X'
    && v_map[next_pos.y][next_pos.x] != 'O') {
        if (map[nnext_pos.y][nnext_pos.x] != '#'
        && map[nnext_pos.y][nnext_pos.x] != '\0'
        && map[nnext_pos.y][nnext_pos.x] != 'X') {
            return 1;
        } else {
            return -1;
        }
    }
    return 0;
}

int is_enought_space(char **map, char **v_map, dPos_t next_pos)
{
    if (map[next_pos.y][next_pos.x] == '#'
    || map[next_pos.y][next_pos.x] == '\0') {
        return -1;
    }
    if (map[next_pos.y][next_pos.x] == 'X'
    && v_map[next_pos.y][next_pos.x] == 'O') {
        return -1;
    }
    return 0;
}

int can_move(dPos_t next_pos, dPos_t nnext_pos, char **map, char **v_map)
{
    int pushing = 0;

    if (map == NULL)
        return 84;
    if (next_pos.y == -1 || next_pos.x == -1)
        return -1;
    if (is_enought_space(map, v_map, next_pos) != 0)
        return -1;
    pushing = can_push_box(map, v_map, next_pos, nnext_pos);
    if (pushing != 0)
        return pushing;
    return 0;
}
