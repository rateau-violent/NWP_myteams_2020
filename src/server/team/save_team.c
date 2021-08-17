/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_team
*/

#include "team.h"
#include "my.h"

#include <stdlib.h>
#include <string.h>

static const char *FILE_EXTENSION = "_team.save";

static void save_loop(int fd, const char *filepath, team_t *list)
{
    char *full_path = NULL;

    for (; list; list = list->next) {
        if (!strcmp(list->uuid, ""))
            continue;
        write(fd, list, sizeof(team_t));
        full_path = my_strcat(3, filepath, "_", list->uuid);
        if (list->subscribers_list)
            save_subscribers_list(list->subscribers_list, full_path);
        if (list->channels_list)
            save_channels_list(list->channels_list, full_path);
        free(full_path);
    }
}

void save_teams_list(team_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    if (full_path)
        free(full_path);
    if (fd == -1)
        return;
    save_loop(fd, filepath, list);
    close(fd);
}