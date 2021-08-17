/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_client
*/

#include "user.h"
#include "my.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static const char *FILE_EXTENSION = "_user.save";

static user_t *add_empty_node(user_t *u)
{
    u->next = create_empty_user();
    u->next->prev = u;
    u = u->next;
    return u;
}

static user_t *get_discussions_list(user_t *user, const char *filepath)
{
    char *full_path = my_strcat(3, filepath, "_", user->uuid);

    user->discussions_list = load_discussions_list(full_path);
    free(full_path);
    return user;
}

static user_t *load_loop(int fd, const char *filepath, user_t *list)
{
    user_t *tmp = NULL;
    user_t buff = {0};

    while (read(fd, &buff, sizeof(user_t)) > 0) {
        if (!list) {
            list = create_empty_user();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_users_list(list);
        tmp = user_cpy(tmp, &buff);
        tmp = get_discussions_list(tmp, filepath);
    }
    return list;
}

user_t *load_users_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    user_t *list = NULL;

    if (full_path)
        free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, filepath, list);
    close(fd);
    return list;
}