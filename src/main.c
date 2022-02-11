/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** main file
*/

#include "my_project.h"

#include <unistd.h>

int display_help()
{
    char *text = NULL;

    text = get_file_content("assets/help.txt");
    if (text != NULL)
        write(1, text, my_strlen(text));
    else
        return put_error("Error while trying to display the help\n");
    return 0;
}

int main(int argc, char **argv, char **env)
{
    char *map = NULL;

    if (*env == NULL || argc < 2)
        return put_error("You need to provide an environment and a map\n");
    if (my_strcmp(argv[1], "-h") == 0)
        return display_help();
    map = get_file_content(argv[1]);
    if (map_is_valid(map) != 0)
        return put_error("You need to provide a valid map\n");
    return my_sokoban(map);
}
