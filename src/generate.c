/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** generate
*/

#include "my_project.h"

sokoban_t *create_sokoban(char *map)
{
    sokoban_t *sokoban = NULL;

    if (map == NULL) {
        write_red("Error while charging map inside sokoban..\n");
        exit(84);
    }
    sokoban = malloc(sizeof(sokoban_t));
    if (sokoban == NULL) {
        free(map);
        write_red("Error while charging sokoban..\n");
        exit(84);
    }
    sokoban->map = my_str_to_words_array(map, (char[]) { '\n' });
    sokoban->virgin_map = my_str_to_words_array(map, (char[]) { '\n' });
    return sokoban;
}

sokoban_t *init_sokoban(char *map)
{
    sokoban_t *sokoban = create_sokoban(map);

    if (sokoban == NULL) {
        free(map);
        write_red("Error while charging sokoban..\n");
        exit(84);
    }
    sokoban->position = where_is_player(sokoban->map);
    if (sokoban->position.x == -1 || sokoban->position.y == -1) {
        write_red("Can't find the player in the map.\n");
        free(sokoban->map);
        free(sokoban);
        exit(84);
    }
    sokoban->nb_hit = 0;
    sokoban->map_size = get_map_size(sokoban->map);
    sokoban->status_backup = PLAYING;
    sokoban->status = PLAYING;
    return sokoban;
}
