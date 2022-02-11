/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** check_victory
*/

#include "my_project.h"

void is_victory(sokoban_t *sokoban)
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
    if (is_empty == 0) {
        write(2, "You win !", 11);
        sokoban->status = WIN;
    }
}
