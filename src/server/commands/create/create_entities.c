/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_entities
*/

#include <string.h>

#include "client_request.h"
#include "server.h"
#include "server_answer.h"
#include "logging_server.h"

void create_team(server_t *server, int fd, client_request_t *request)
{
    team_t *team = NULL;
    server_answer_t *answer = NULL;
    answer_data_t *data = NULL;

    server->teams_list = add_team_node(server->teams_list, request->args[0],
        request->args[1]);
    team = get_team_from_name(server->teams_list, request->args[0]);
    answer = create_server_answer("140", team_created, 1);
    data = create_answer_data(strings_to_array(3, team->uuid,
        team->name, team->description), 0, 0);
    for (user_t *it = server->users_list; it; it = it->next) {
        send_to_user(it, answer, sizeof(server_answer_t));
        send_to_user(it, data, sizeof(answer_data_t));
    }
    server_event_team_created(team->uuid, team->name,
        get_user_from_fd(server->users_list, fd)->uuid);
}

void create_channel(server_t *server, team_t *team, int fd,
    client_request_t *request)
{
    channel_t *channel = NULL;

    if (get_channel_from_name(team->channels_list, request->args[0]))
        return (void)send_server_answer(fd, "440", error_already_exists, 0);
    team->channels_list = add_channel_node(team->channels_list,
        request->args[0], request->args[1]);
    channel = get_channel_from_name(team->channels_list, request->args[0]);
    send_answer_to_subscribers(create_server_answer("140", channel_created, 1),
        server->users_list, team->subscribers_list);
    send_data_to_subscribers(create_answer_data(strings_to_array(3,
        channel->uuid, channel->name, channel->description), 0, 0),
        server->users_list, team->subscribers_list);
    server_event_channel_created(team->uuid, channel->uuid, channel->name);
}

void create_thread(server_t *server, team_t *team, int fd,
    client_request_t *r)
{
    channel_t *channel = retrieve_channel(server->teams_list, r->team,
        r->channel);
    thread_t *thread = NULL;
    user_t *user = get_user_from_fd(server->users_list, fd);

    if (get_thread_from_title(channel->threads_list, r->args[0]))
        return (void)send_server_answer(fd, "440", error_already_exists, 0);
    channel->threads_list = add_thread_node(channel->threads_list,
        user->uuid, r->args[0], r->args[1]);
    thread = get_thread_from_title(channel->threads_list, r->args[0]);
    send_answer_to_subscribers(create_server_answer("140", thread_created, 1),
        server->users_list, team->subscribers_list);
    send_data_to_subscribers(create_answer_data(strings_to_array(4,
        thread->uuid, user->uuid, thread->title, thread->message), 0,
        thread->time), server->users_list, team->subscribers_list);
    server_event_thread_created(channel->uuid, thread->uuid, user->uuid,
        thread->title, thread->message);
}

void create_reply(server_t *server, team_t *team, int fd, client_request_t *r)
{
    thread_t *thread = retrieve_thread(server->teams_list, r->team,
        r->channel, r->thread);
    user_t *user = get_user_from_fd(server->users_list, fd);
    comment_t *reply = NULL;

    if (!strcmp(r->args[0], ""))
        return;
    thread->comments_list = add_comment_node(thread->comments_list,
        user->username, r->args[0]);
    reply = get_last_comment(thread->comments_list);
    send_answer_to_subscribers(create_server_answer("140", reply_created, 1),
        server->users_list, team->subscribers_list);
    send_data_to_subscribers(create_answer_data(strings_to_array(3,
        thread->uuid, user->uuid, reply->message), 0, reply->time),
        server->users_list, team->subscribers_list);
    server_event_reply_created(thread->uuid, user->uuid, reply->message);
}