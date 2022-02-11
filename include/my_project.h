/*
** EPITECH PROJECT, 2022
** project
** File description:
** my_project
*/

#ifndef MY_PROJECT_H_
#define MY_PROJECT_H_
    #include <stdlib.h>
    #include <stddef.h>

    #include <ncurses.h>

    #include "my.h"

    typedef struct dPos_s {
        int x;
        int y;
    } dPos_t;

    typedef enum status_e {
        PLAYING = 480,
        WIN,
        LOOSE,
        INVALID_SCREEN_SIZE,
        IN_PAUSE,
        IN_MENU,
        EXIT
    } status_t;

    typedef struct sokonban_s {
        char **map;
        char **virgin_map;
        int nb_hit;
        char under_player;
        char under_x;
        dPos_t position;
        dPos_t map_size;
        status_t status;
        status_t status_backup;
    } sokoban_t;

    int map_is_valid(const char *map);

    int my_sokoban(char *map);

    sokoban_t *create_sokoban(char *map);
    sokoban_t *init_sokoban(char *map);

    dPos_t get_map_size(char **map);
    dPos_t where_is_player(char **map);

    void check_screen_size(sokoban_t *sokoban);

    int sokoban_run(sokoban_t *sokoban, int ch);
    int sokoban_invalid_screen(sokoban_t *sokoban, int ch);
    int sokoban_pause(sokoban_t *sokoban, int ch);
    int sokoban_menu(sokoban_t *sokoban, int ch);

    int can_move(dPos_t next_pos, dPos_t nnext_pos, char **map, char **v_map);
    void move_up(sokoban_t *sokoban);
    void move_down(sokoban_t *sokoban);
    void move_left(sokoban_t *sokoban);
    void move_right(sokoban_t *sokoban);

    void display_HUD(sokoban_t *sokoban);
    void is_victory(sokoban_t *sokoban);

#endif /* !MY_PROJECT_H_ */
