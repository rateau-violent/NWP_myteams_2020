/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "user.h"
#include "team.h"

#include <netinet/in.h>
#include <sys/select.h>

typedef struct server_s
{
    unsigned long port;
    int socket_fd;
    fd_set active_fd_set;
    fd_set read_fd_set;
    user_t *users_list;
    team_t *teams_list;
    struct sockaddr_in addr;
} server_t;


void save_server_data(server_t *server);

server_t *load_server_data(server_t *server);


channel_t *retrieve_channel(team_t *teams_list, const char *team_uuid,
    const char *channel_uuid);

thread_t *retrieve_thread(team_t *teams_list, const char *team_uuid,
    const char *channel_uuid, const char *thread_uuid);

#endif /* !SERVER_H_ */