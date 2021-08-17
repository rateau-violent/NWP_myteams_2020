/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** get_client
*/

#include "user.h"

#include <string.h>

bool fd_already_exists(user_t *user, int fd)
{
    if (!user->fds)
        return false;
    for (size_t i = 0; i < user->connection_nb; i++)
        if (user->fds[i] == fd)
            return true;
    return false;
}

user_t *get_user_from_fd(user_t *list, const int fd)
{
    user_t *it = list;

    for (; it; it = it->next)
        if (fd_already_exists(it, fd))
            break;
    return it;
}

user_t *get_user_from_username(user_t *list, const char *username)
{
    for (; list; list = list->next)
        if (!strcmp(list->username, username))
            break;
    return list;
}

user_t *get_user_from_uuid(user_t *list, const char *uuid)
{
    for (; list; list = list->next)
        if (!strcmp(list->uuid, uuid))
            break;
    return list;
}

size_t get_users_nb(user_t *list)
{
    size_t i = 0;

    for (user_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}