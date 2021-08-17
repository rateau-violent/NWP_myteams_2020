/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_client
*/

#include "user.h"
#include "my.h"
#include "server_answer.h"

#include <stdlib.h>
#include <string.h>

static const char *FILE_EXTENSION = "_user.save";

void close_fds(user_t *user)
{
    if (!user->fds)
        return;
    for (size_t i = 0; i < user->connection_nb; i++) {
        send_server_answer(user->fds[i], "000", logged_out, 1);
        send_answer_data(user->fds[i], strings_to_array(2, user->uuid,
            user->username), 0, 0);
        close(user->fds[i]);
    }
    free(user->fds);
    user->fds = NULL;
}

static user_t *reinit_users_list(user_t *list)
{
    user_t *it = list;

    for (; it; it = it->next) {
        close_fds(it);
        it->logged_in = false;
        it->connection_nb = 0;
    }
    return list;
}

static void save_loop(int fd, const char *filepath, user_t *list)
{
    char *full_path = NULL;

    for (; list; list = list->next) {
        if (!strcmp(list->uuid, "") || !strcmp(list->username, ""))
            continue;
        write(fd, list, sizeof(user_t));
        full_path = my_strcat(3, filepath, "_", list->uuid);
        if (list->discussions_list)
            save_discussions_list(list->discussions_list, full_path);
        free(full_path);
    }
}

void save_users_list(user_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    if (full_path)
        free(full_path);
    if (fd == -1)
        return;
    save_loop(fd, filepath, reinit_users_list(list));
    close(fd);
}
