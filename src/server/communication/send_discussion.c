/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** sent_discussion
*/

#include "discussion.h"
#include "server_answer.h"

void send_discussion(discussion_t *discussion, int fd, char *code)
{
    send_server_answer(fd, code, print_messages_list,
        get_comments_nb(discussion->messages_list));
    for (comment_t *tmp = discussion->messages_list; tmp; tmp = tmp->next)
        send_answer_data(fd, strings_to_array(2, tmp->author_uuid,
            tmp->message), 0, tmp->time);
}