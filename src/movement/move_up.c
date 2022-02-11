/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** move_up
*/

#include "my_project.h"

void move_up(sokoban_t *sokoban)
{
    char to_put;
    dPos_t pos;
    int move = 0;

    if (sokoban == NULL)
        exit(84);
    pos = sokoban->position;
    move = can_move((dPos_t){ pos.x, pos.y - 1 }, \
            (dPos_t){ pos.x, pos.y - 2 }, sokoban->map, sokoban->virgin_map);
    if (move == -1 || move == 84)
        return;
    if (!sokoban->under_player)
        sokoban->under_player = ' ';
    to_put = sokoban->under_player;
    sokoban->under_player = sokoban->map[pos.y - 1][pos.x];
    if (move == 1) {
        sokoban->under_player = ' ';
        sokoban->under_x = sokoban->map[pos.y - 2][pos.x];
        sokoban->map[pos.y - 2][pos.x] = 'X';
    }
    sokoban->map[pos.y - 1][pos.x] = 'P';
    sokoban->map[pos.y][pos.x] = to_put;
    sokoban->position.y--;
    sokoban->nb_hit++;
}
