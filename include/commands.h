/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "server.h"
#include "client_request.h"

void logout_user(server_t *server, const int fd, client_request_t *request);
void login_user(server_t *server, const int fd, client_request_t *request);
void print_users(server_t *server, const int fd, client_request_t *request);
void get_user_info(server_t *server, const int fd, client_request_t *request);
void send_private_message(server_t *server, const int fd,
    client_request_t *request);
void list(server_t *server, const int fd, client_request_t *request);
void create(server_t *server, const int fd, client_request_t *request);
void info(server_t *server, const int fd, client_request_t *request);
void subscribe_team(server_t *server, const int fd,
    client_request_t *request);
void unsubscribe_team(server_t *server, const int fd,
    client_request_t *request);
void subscribed_team(server_t *server, const int fd,
    client_request_t *request);
void list_messages(server_t *server, const int fd, client_request_t *request);

typedef struct {
    const char *command_name;
    void (*ft)(server_t *, const int, client_request_t *request);
} commands_t;

static const commands_t COMMANDS[] = {
    {"/logout", &logout_user},
    {"/login", &login_user},
    {"/users", &print_users},
    {"/user", &get_user_info},
    {"/send", &send_private_message},
    {"/messages", &list_messages},
    {"/list", &list},
    {"/create", &create},
    {"/info", &info},
    {"/subscribe", &subscribe_team},
    {"/unsubscribe", &unsubscribe_team},
    {"/subscribed", &subscribed_team}
};

static const size_t COMMANDS_NB = sizeof(COMMANDS) / sizeof(commands_t);


void save_private_messages(user_t *send_user, user_t *receive_user,
const char *message);


void create_team(server_t *server, int fd, client_request_t *request);

void create_channel(server_t *server, team_t *team, int fd,
    client_request_t *request);

void create_thread(server_t *server, team_t *team, int fd,
    client_request_t *r);

void create_reply(server_t *server, team_t *team, int fd,
    client_request_t *request);

void team_context(server_t *server, team_t *team, int fd,
    client_request_t *request);

void server_context(server_t *server, int fd, team_t *team,
    client_request_t *request);

#endif /* !COMMANDS_H_ */
