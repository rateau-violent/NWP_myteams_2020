/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** client_request
*/

#include "server.h"
#include "myteams.h"

enum user_context {
    no_context,
    in_server,
    in_team,
    in_channel,
    in_thread
};

typedef struct use_s
{
    char team[UUID_LENGTH + 1];
    char channel[UUID_LENGTH + 1];
    char thread[UUID_LENGTH + 1];
} use_t;

typedef struct client_request_s
{
    char command[20];
    char args[4][MAX_DESCRIPTION_LENGTH + 1];
    char team[UUID_LENGTH + 1];
    char channel[UUID_LENGTH + 1];
    char thread[UUID_LENGTH + 1];
    bool close_fd;
    enum user_context context;
} client_request_t;

void send_client_request(const char *command, char **args,
    const use_t *use, int fd);

int receive_client_request(server_t *server, int fd);

use_t *update_use(use_t *use, char **args);