/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** remove_client
*/

#include "user.h"
#include "server_answer.h"

#include <stdlib.h>
#include <unistd.h>

static user_t *destroy_node(user_t *node)
{
    if (!node)
        return NULL;
    if (node->discussions_list)
        destroy_discussions_list(node->discussions_list);
    free(node);
    return NULL;
}

user_t *remove_user_node_from_fd(user_t *list, int fd)
{
    user_t *tmp = get_user_from_fd(list, fd);

    if (!tmp)
        return list;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp == list)
        list = list->next;
    destroy_node(tmp);
    return list;
}

user_t *remove_user_node_from_uuid(user_t *list, const char *uuid)
{
    user_t *tmp = get_user_from_uuid(list, uuid);

    if (!tmp)
        return list;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp == list)
        list = list->next;
    destroy_node(tmp);
    return list;
}

user_t *destroy_users_list(user_t *list)
{
    while (list)
        list = remove_user_node_from_uuid(list, list->uuid);
    return NULL;
}