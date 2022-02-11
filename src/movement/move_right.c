/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** move_left
*/

#include "my_project.h"

void move_right(sokoban_t *sokoban)
{
    char to_put;
    dPos_t pos;
    int move = 0;

    if (sokoban == NULL)
        exit(84);
    pos = sokoban->position;
    move = can_move((dPos_t){ pos.x + 1, pos.y }, \
            (dPos_t){ pos.x + 2, pos.y }, sokoban->map, sokoban->virgin_map);
    if (move == -1 || move == 84)
        return;
    if (sokoban->nb_hit == 0)
        sokoban->under_player = ' ';
    to_put = sokoban->under_player;
    sokoban->under_player = sokoban->map[pos.y][pos.x + 1];
    if (move == 1) {
        sokoban->under_player = ' ';
        sokoban->under_x = sokoban->map[pos.y][pos.x + 2];
        sokoban->map[pos.y][pos.x + 2] = 'X';
    }
    sokoban->map[pos.y][pos.x + 1] = 'P';
    sokoban->map[pos.y][pos.x] = to_put;
    sokoban->position.x++;
    sokoban->nb_hit++;
}
