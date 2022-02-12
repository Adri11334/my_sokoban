/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** status
*/

#include "my_project.h"

int sokoban_run(sokoban_t *sokoban, int ch)
{
    switch (ch) {
        case KEY_UP: move_up(sokoban); break;
        case KEY_DOWN: move_down(sokoban); break;
        case KEY_LEFT: move_left(sokoban); break;
        case KEY_RIGHT: move_right(sokoban); break;
    }
    display_HUD(sokoban);
    is_loose(sokoban);
    return 0;
}

int sokoban_invalid_screen(sokoban_t *sokoban, int ch)
{
    clear();
    move((LINES / 2), (COLS / 2) - 14);
    printw("Please enlarge the terminal.");
    refresh();
    return 0;
}

int sokoban_pause(sokoban_t *sokoban, int ch)
{
    clear();
    move((LINES / 2), (COLS / 2) - 7);
    printw("In pause menu.");
    refresh();
    return 0;
}

int sokoban_menu(sokoban_t *sokoban, int ch)
{
    clear();
    move((LINES / 2), (COLS / 2) - 6);
    printw("In main menu.");
    refresh();
    return 0;
}

int sokoban_end(sokoban_t *sokoban, int ch)
{
    clear();
    display_HUD(sokoban);
    if (sokoban->status == WIN)
        printw("You won !");
    else
        printw("Game over..");
    refresh();
    return 0;
}
