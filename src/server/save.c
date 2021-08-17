/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save
*/

#include <stdlib.h>

#include "server.h"
#include "my.h"
#include "logging_server.h"

static const char *SAVE_DIR = ".server_data/";
static const char *SAVE_NAME = "server";

void save_server_data(server_t *server)
{
    char *name = my_strcat(2, SAVE_DIR, SAVE_NAME);

    if (create_dir(SAVE_DIR) == -1)
        return;
    if (server->teams_list)
        save_teams_list(server->teams_list, name);
    if (server->users_list)
        save_users_list(server->users_list, name);
    free(name);
}

server_t *load_server_data(server_t *server)
{
    char *path = my_strcat(2, SAVE_DIR, SAVE_NAME);

    server->users_list = load_users_list(path);
    server->teams_list = load_teams_list(path);
    for (user_t *it = server->users_list; it; it = it->next)
        server_event_user_loaded(it->uuid, it->username);
    free(path);
    return server;
}
