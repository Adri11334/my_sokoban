/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** fit_in_screen
*/

#include "my_project.h"

void check_screen_size(sokoban_t *sokoban)
{
    if (LINES < sokoban->map_size.y + 2|| COLS < sokoban->map_size.x + 1) {
        if (sokoban->status != INVALID_SCREEN_SIZE) {
            sokoban->status_backup = sokoban->status;
            sokoban->status = INVALID_SCREEN_SIZE;
        }
    } else {
        if (sokoban->status == INVALID_SCREEN_SIZE) {
            sokoban->status = PLAYING;
        }
    }
}
