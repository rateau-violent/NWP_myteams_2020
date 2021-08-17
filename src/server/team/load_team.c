/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** load_team
*/

#include "team.h"
#include "my.h"

#include <stdlib.h>
#include <fcntl.h>

static const char *FILE_EXTENSION = "_team.save";

static team_t *add_empty_node(team_t *t)
{
    t->next = create_empty_team();
    t->next->prev = t;
    t = t->next;
    return t;
}

static team_t *get_subscribers_list(team_t *t, const char *filepath)
{
    char *full_path = my_strcat(3, filepath, "_", t->uuid);

    t->subscribers_list = load_subscribers_list(full_path);
    free(full_path);
    return t;
}

static team_t *get_channels_list(team_t *t, const char *filepath)
{
    char *full_path = my_strcat(3, filepath, "_", t->uuid);

    t->channels_list = load_channels_list(full_path);
    free(full_path);
    return t;
}

static team_t *load_loop(int fd, const char *filepath, team_t *list)
{
    team_t *tmp = NULL;
    team_t buff = {0};

    while (read(fd, &buff, sizeof(team_t))) {
        if (!list) {
            list = create_empty_team();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_team_list(list);
        team_cpy(tmp, &buff);
        tmp = get_channels_list(tmp, filepath);
        tmp = get_subscribers_list(tmp, filepath);
    }
    return list;
}

team_t *load_teams_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    team_t *list = NULL;

    if (full_path)
        free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, filepath, list);
    close(fd);
    return list;
}