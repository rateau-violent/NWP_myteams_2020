/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_private_messages
*/

#include "commands.h"

static void save_new_discussion(user_t *send_user, user_t *receive_user,
const char *message)
{
        discussion_t *buffer = NULL;

    send_user->discussions_list = add_discussion_node(send_user->
        discussions_list, receive_user->username, receive_user->uuid);
    for (buffer = send_user->discussions_list; buffer->next;
        buffer = buffer->next)
    ;
    buffer->messages_list = add_comment_node(
        buffer->messages_list,
        send_user->uuid, message);
    receive_user->discussions_list = add_discussion_node(receive_user->
        discussions_list, send_user->username, send_user->uuid);
    for (buffer = receive_user->discussions_list; buffer->next;
        buffer = buffer->next)
    ;
    buffer->messages_list = add_comment_node(
        buffer->messages_list,
        send_user->uuid, message);
}

void save_private_messages(user_t *send_user, user_t *receive_user,
    const char *message)
{
    discussion_t *send_user_discussion = get_discussion_from_other(send_user->
        discussions_list, receive_user->uuid);
    discussion_t *receive_user_discussion = get_discussion_from_other(
        receive_user->discussions_list, send_user->uuid);

    if (!send_user_discussion && !receive_user_discussion)
        return save_new_discussion(send_user, receive_user, message);

    send_user_discussion->messages_list = add_comment_node(
        send_user->discussions_list->messages_list,
        send_user->uuid, message);
    receive_user_discussion->messages_list = add_comment_node(
        receive_user->discussions_list->messages_list,
        send_user->uuid, message);
}