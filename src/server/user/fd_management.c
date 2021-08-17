/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** fd_management
*/

#include <stdlib.h>

#include "user.h"

user_t *add_fd_to_user(user_t *user, int fd)
{
    user->fds = realloc(user->fds, sizeof(int) * (user->connection_nb + 1));
    if (!user->fds)
        return NULL;
    user->fds[user->connection_nb] = fd;
    user->connection_nb++;
    return user;
}

user_t *remove_fd_from_user(user_t *user, int fd)
{
    size_t i = 0;

    if (!user->connection_nb)
        return user;
    for (; i < user->connection_nb; i++)
        if (user->fds[i] == fd)
            break;
    if (i == user->connection_nb)
        return user;
    if (i == user->connection_nb - 1)
        user->fds = realloc(user->fds, sizeof(int) * (user->connection_nb - 1));
    for (; i < user->connection_nb - 1; i++)
        user->fds[i] = user->fds[i + 1];
    user->connection_nb--;
    return user;
}