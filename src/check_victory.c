/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** check_victory
*/

#include "my_project.h"

int is_victory(sokoban_t *sokoban)
{
    int y = 0;
    int x = 0;
    int is_empty = 0;

    while (sokoban->map[y] != NULL) {
        if (sokoban->map[y][x] == '\0') {
            x = 0;
            y++;
            continue;
        }
        if (sokoban->map[y][x] == 'O') {
            is_empty--;
        }
        x++;
    }
    if (is_empty == 0)
        return 0;
    return 1;
}

int count_x(char **map)
{
    int count = 0;
    int x = 0;
    int y = 0;

    if (map == NULL)
        return 0;
    while (map[y] != NULL) {
        if (map[y][x] == '\0') {
            x = 0;
            y++;
            continue;
        }
        if (map[y][x] == 'X')
            count++;;
        x++;
    }
    return count;
}

int is_locked(char **map, int y, int x)
{
    if (map == NULL)
        return 0;
    return (map[y][x] != 'O' && map[y][x] != ' ' && map[y][x] != 'P') ? 1 : 0;
}

void check_borders(dPos_t pos, char **map, char **v_map, int *l_x)
{
    int border_taken = 0;

    if (map == NULL || v_map == NULL)
        return;
    if (v_map[pos.y][pos.x] == 'O') {
        (*l_x)++;
        return;
    }
    if (is_locked(map, pos.y, pos.x + 1) == 1)
        border_taken++;
    if (is_locked(map, pos.y, pos.x - 1) == 1)
        border_taken++;
    if (is_locked(map, pos.y + 1, pos.x) == 1)
        border_taken++;
    if (is_locked(map, pos.y - 1, pos.x) == 1)
        border_taken++;
    if (border_taken >= 2)
        (*l_x)++;
}

void is_loose(sokoban_t *sokoban)
{
    int max_x = count_x(sokoban->map);
    int locked_x = 0;
    int x = 0;
    int y = 0;

    while (sokoban->map[y] != NULL) {
        if (sokoban->map[y][x] == '\0') {
            x = 0;
            y++;
            continue;
        }
        if (sokoban->map[y][x] == 'X') {
            check_borders((dPos_t){ x, y }, sokoban->map, sokoban->virgin_map,
            &locked_x);
        }
        x++;
    }
    if (locked_x == max_x) {
        if (is_victory(sokoban) == 0) {
            sokoban->status = WIN;
        } else {
            sokoban->status = LOOSE;
        }
    }
}
