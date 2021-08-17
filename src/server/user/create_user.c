/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_user
*/

#include "user.h"
#include "myteams.h"

#include <stdlib.h>
#include <string.h>

static user_t *create_user(const int fd)
{
    user_t *new = calloc(1, sizeof(user_t));
    char *uuid = NULL;

    if (!new)
        return NULL;
    uuid = generate_uuid();
    if (!uuid)
        return destroy_users_list(new);
    strcpy(new->username, "");
    strcpy(new->uuid, uuid);
    free(uuid);
    new->fds = calloc(1, sizeof(int));
    if (!new->fds)
        return destroy_users_list(new);
    new->fds[0] = fd;
    new->connection_nb = 1;
    return (!new->uuid || !new->username) ?
        destroy_users_list(new) : new;
}

user_t *create_empty_user(void)
{
    user_t *new = calloc(1, sizeof(user_t));

    if (!new)
        return NULL;
    strcpy(new->username, "");
    strcpy(new->uuid, "");
    new->discussions_list = create_empty_discussion();
    return (!new->username || !new->uuid || !new->discussions_list) ?
        destroy_users_list(new) : new;
}

user_t *add_user_node(user_t *list, const int fd)
{
    user_t *it = list;

    if (!list)
        return create_user(fd);
    for (; it->next; it = it->next)
        if (fd_already_exists(it, fd))
            return list;
    it->next = create_user(fd);
    if (it->next)
        it->next->prev = it;
    return list;
}

user_t *user_cpy(user_t *dest, const user_t *src)
{
    if (!dest || !src)
        return NULL;
    strcpy(dest->username, src->username);
    strcpy(dest->uuid, src->uuid);
    dest->logged_in = src->logged_in;
    return dest;
}