/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** sokoban main file
*/

#include "my_project.h"

void load_screen()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
}

int game_loop(int *ch, sokoban_t *sokoban)
{
    if (sokoban == NULL)
        return 84;
    check_screen_size(sokoban);
    (*ch) = getch();
    switch (sokoban->status) {
        case INVALID_SCREEN_SIZE:
            return sokoban_invalid_screen(sokoban, (*ch));
        case IN_MENU:
            return sokoban_menu(sokoban, (*ch));
        case IN_PAUSE:
            return sokoban_pause(sokoban, (*ch));
        case PLAYING:
            return sokoban_run(sokoban, (*ch));
        case WIN:
            return sokoban_end(sokoban, (*ch));
        case LOOSE:
            return sokoban_end(sokoban, (*ch));
        default: return 84;
    }
}

void display_HUD(sokoban_t *sokoban)
{
    clear();
    move(0, 0);
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        printw("%s\n", sokoban->map[i]);
    }
    printw("Hit number %d\n", sokoban->nb_hit);
    refresh();
}

int my_sokoban(char *map)
{
    int ch;
    sokoban_t *sokoban = init_sokoban(map);

    if (sokoban == NULL)
        return put_error("Error while charging sokoban..\n");
    load_screen();
    check_screen_size(sokoban);
    display_HUD(sokoban);
    while (sokoban->status != EXIT) {
        if (ch == KEY_F(4)) {
            sokoban->status = EXIT;
            continue;
        }
        if (game_loop(&ch, sokoban) != 0)
            sokoban->status = EXIT;
    }
    endwin();
    free(sokoban->map);
    free(sokoban);
    return 0;
}
