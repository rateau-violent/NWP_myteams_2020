/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** send_lists
*/

#include "team.h"
#include "user.h"
#include "server_answer.h"

void send_users_list(user_t *list, int fd, char *code)
{
    send_server_answer(fd, code, print_users_list, get_users_nb(list));
    for (user_t *tmp = list; tmp; tmp = tmp->next)
        send_answer_data(fd, strings_to_array(2, tmp->uuid, tmp->username),
            tmp->logged_in, 0);
}

void send_teams_list(team_t *list, int fd, char *code)
{
    send_server_answer(fd, code , print_teams_list, get_teams_nb(list));
    for (team_t *tmp = list; tmp; tmp = tmp->next)
        send_answer_data(fd, strings_to_array(3, tmp->uuid, tmp->name,
            tmp->description), 0, 0);
}

void send_channels_list(channel_t *list, int fd, char *code)
{
    send_server_answer(fd, code, print_channels_list, get_channels_nb(list));
    for (channel_t *tmp = list; tmp; tmp = tmp->next)
        send_answer_data(fd, strings_to_array(3, tmp->uuid, tmp->name,
            tmp->description), 0, 0);
}

void send_threads_list(thread_t *list, int fd, char *code)
{
    send_server_answer(fd, code, print_threads_list, get_threads_nb(list));
    for (thread_t *tmp = list; tmp; tmp = tmp->next)
        send_answer_data(fd, strings_to_array(4, tmp->uuid, tmp->author,
            tmp->title, tmp->message), 0, tmp->time);
}

void send_thread_replies(thread_t *thread, int fd, char *code)
{
    send_server_answer(fd, code, print_comments_list,
        get_comments_nb(thread->comments_list));
    for (comment_t *tmp = thread->comments_list; tmp; tmp = tmp->next)
        send_answer_data(fd, strings_to_array(3, thread->uuid,
            tmp->author_uuid, tmp->message), 0, tmp->time);
}