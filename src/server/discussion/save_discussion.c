/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_discussion
*/

#include "discussion.h"
#include "my.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

static const char *FILE_EXTENSION = "_discussions.save";

static discussion_t *add_empty_node(discussion_t *d)
{
    d->next = create_empty_discussion();
    d->next->prev = d;
    d = d->next;
    return d;
}

void save_discussions_list(discussion_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    free(full_path);
    if (fd == -1)
        return;
    for (; list; list = list->next) {
        if (!strcmp(list->other_uuid, ""))
            continue;
        write(fd, list, sizeof(discussion_t));
        full_path = my_strcat(3, filepath, "_", list->other_uuid);
        if (list->messages_list)
            save_comments_list(list->messages_list, full_path);
        free(full_path);
    }
    close(fd);
}

static discussion_t *get_messages_list(discussion_t *d, const char *filepath)
{
    char *full_path = my_strcat(3, filepath, "_", d->other_uuid);

    d->messages_list = load_comments_list(full_path);
    free(full_path);
    return d;
}

static discussion_t *load_loop(int fd, const char *filepath,
    discussion_t *list)
{
    discussion_t *tmp = NULL;
    discussion_t buff = {0};

    while (read(fd, &buff, sizeof(discussion_t)) > 0) {
        if (!list) {
            list = create_empty_discussion();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_discussions_list(list);
        tmp = discussion_cpy(tmp, &buff);
        tmp = get_messages_list(tmp, filepath);
    }
    return list;
}

discussion_t *load_discussions_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    discussion_t *list = NULL;

    free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, filepath, list);
    close(fd);
    return list;
}