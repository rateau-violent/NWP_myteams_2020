/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** server_answer
*/

#ifndef SERVER_ANSWER_H_
#define SERVER_ANSWER_H_

#include <time.h>

#include "user.h"
#include "team.h"
#include "logging_client.h"


enum answer_header {
    client_unauthorized,
    error_already_exists,
    unknown_team,
    unknown_channel,
    unknown_thread,
    unknown_user,
    logged_in,
    logged_out,
    received_message,
    print_team,
    subscribed,
    unsubscribed,
    team_created,
    channel_created,
    print_channel,
    print_teams_list,
    print_channels_list,
    thread_reply_received,
    print_users_list,
    print_user,
    print_messages_list,
    print_comments_list,
    reply_created,
    thread_created,
    print_thread,
    print_threads_list,
    user_not_logged_in,
    invalid_command
};


typedef struct
{
    char s1[MAX_BODY_LENGTH + 1];
    char s2[MAX_BODY_LENGTH + 1];
    char s3[MAX_BODY_LENGTH + 1];
    char s4[MAX_BODY_LENGTH + 1];
    int nb;
    time_t time;
} answer_data_t;

answer_data_t *create_answer_data(char **strings, int nb, time_t time);
answer_data_t *destroy_answer_data(answer_data_t *data);


void send_answer_data(int fd, char **strings, int nb, time_t time);

void send_data_to_subscribers(answer_data_t *data, user_t *users,
    subscriber_t *sub);


typedef struct server_answer_s
{
    enum answer_header header;
    char code[4];
    size_t read_nb;
} server_answer_t;

server_answer_t *create_server_answer(char *code, enum answer_header header,
    size_t read_nb);
server_answer_t *destroy_server_answer(server_answer_t *answer);

void send_server_answer(int fd, char *code, enum answer_header header,
    size_t read_nb);
int receive_server_answer(int fd);

void send_answer_to_subscribers(server_answer_t *answer, user_t *users,
    subscriber_t *sub);


typedef struct
{
    enum answer_header header;
    int (*error)(void);
} client_error_t;

static const client_error_t CLIENT_ERRORS[] = {
    { error_already_exists, client_error_already_exist },
    { client_unauthorized, client_error_unauthorized }
};

static const size_t CLIENT_ERRORS_SIZE = sizeof(CLIENT_ERRORS) /
    sizeof(client_error_t);



typedef struct
{
    enum answer_header header;
    int (*error)(const char *);
} unknown_entity_t;

static const unknown_entity_t UNKNOWN_ENTITY_ERRORS[] = {
    { unknown_team, &client_error_unknown_team },
    { unknown_channel, &client_error_unknown_channel },
    { unknown_thread, &client_error_unknown_thread },
    { unknown_user, &client_error_unknown_user }
};

static const size_t UNKNOWN_ENTITY_ERRORS_SIZE = sizeof(UNKNOWN_ENTITY_ERRORS)
    / sizeof(unknown_entity_t);



typedef struct
{
    enum answer_header header;
    int (*notif)(const char *, const char *);
} notification_event_t;

static const notification_event_t NOTIFICATION_EVENTS[] =
{
    { logged_in, client_event_logged_in },
    { logged_out, client_event_logged_out },
    { received_message, client_event_private_message_received },
    { subscribed, client_print_subscribed },
    { unsubscribed, client_print_unsubscribed }
};

static const size_t NOTIFICATION_EVENTS_SIZE = sizeof(NOTIFICATION_EVENTS)
    / sizeof(notification_event_t);


typedef struct
{
    enum answer_header header;
    int (*created)(const char *, const char *, const char *);
} created_event_t;

static const created_event_t CREATED_EVENTS[] = {
    { team_created, client_event_team_created },
    { channel_created, client_event_channel_created },
    { print_channel, client_print_channel },
    { print_team, client_print_team },
    { print_teams_list, client_print_teams },
    { print_channels_list, client_team_print_channels }
};

static const size_t CREATED_EVENTS_SIZE = sizeof(CREATED_EVENTS) /
    sizeof(created_event_t);


typedef struct
{
    enum answer_header header;
    int (*reply)(const char *, const char *, const char *, const char *);
} reply_received_t;

static const reply_received_t REPLY_RECEIVED[] =
{
    {thread_reply_received, client_event_thread_reply_received}
};

static const size_t REPLY_RECEIVED_SIZE = sizeof(REPLY_RECEIVED) /
    sizeof(reply_received_t);


typedef struct
{
    enum answer_header header;
    int (*user)(const char *, const char *, const int);
} print_user_t;

static const print_user_t PRINT_USER[] = {
    { print_user, client_print_user },
    { print_users_list, client_print_users}
};

static const size_t PRINT_USER_SIZE = sizeof(PRINT_USER) /
    sizeof(print_user_t);


typedef struct
{
    enum answer_header header;
    int (*messages)(const char *, const time_t, const char *);
} print_messages_list_t;

static const print_messages_list_t PRINT_MESSAGES_LIST[] = {
    { print_messages_list, client_private_message_print_messages }
};

static const size_t PRINT_MESSAGES_LIST_SIZE = sizeof(PRINT_MESSAGES_LIST) /
    sizeof(print_messages_list_t);


typedef struct
{
    enum answer_header header;
    int (*comment)(const char *, const char *, const time_t, const char *);
} print_comment_t;

static const print_comment_t PRINT_COMMENT[] = {
    { print_comments_list, client_thread_print_replies },
    { reply_created, client_print_reply_created }
};

static const size_t PRINT_COMMENT_SIZE = sizeof(PRINT_COMMENT) /
    sizeof(print_comment_t);


typedef struct
{
    enum answer_header header;
    int (*event)(const char *, const char *, const time_t, const char *,
        const char *);
} thread_event_t;


static const thread_event_t THREAD_EVENTS[] = {
    { thread_created, client_print_thread_created },
    { print_thread, client_print_thread },
    { print_threads_list, client_channel_print_threads }
};

static const size_t THREAD_EVENTS_SIZE = sizeof(THREAD_EVENTS) /
    sizeof(thread_event_t);


void send_users_list(user_t *list, int fd, char *code);

void send_teams_list(team_t *list, int fd, char *code);

void send_channels_list(channel_t *list, int fd, char *code);

void send_threads_list(thread_t *list, int fd, char *code);

void send_thread_replies(thread_t *thread, int fd, char *code);

void send_discussion(discussion_t *discussion, int fd, char *code);

void send_team_subscribers(team_t *team, user_t *all_users, int fd,
    char *code);

void send_user_subscription(user_t *user, team_t *all_teams, int fd,
    char *code);

void unknown_entity(int fd, char *uuid, enum answer_header header);

void send_to_user(user_t *user, void *msg, size_t msg_size);

#endif /* !SERVER_ANSWER_H_ */