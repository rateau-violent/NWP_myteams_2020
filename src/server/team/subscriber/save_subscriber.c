/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_subscriber
*/

#include "subscriber.h"
#include "my.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

static const char *FILE_EXTENSION = "_subcriber.save";

static subscriber_t *add_empty_node(subscriber_t *s)
{
    s->next = create_empty_subscriber();
    s->next->prev = s;
    s = s->next;
    return s;
}

static subscriber_t *load_loop(int fd, subscriber_t *list)
{
    subscriber_t *tmp = NULL;
    subscriber_t buff = {0};

    while (read(fd, &buff, sizeof(subscriber_t)) > 0) {
        if (!list) {
            list = create_empty_subscriber();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_subscribers_list(list);
        strcpy(tmp->uuid, buff.uuid);
    }
    return list;
}

void save_subscribers_list(subscriber_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    free(full_path);
    if (fd == -1)
        return;
    for (; list; list = list->next) {
        if (!strcmp(list->uuid, ""))
            continue;
        write(fd, list, sizeof(subscriber_t));
    }
    close(fd);
}

subscriber_t *load_subscribers_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    subscriber_t *list = NULL;

    if (full_path)
        free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, list);
    close(fd);
    return list;
}