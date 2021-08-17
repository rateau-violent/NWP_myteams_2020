/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_channel
*/

#include "channel.h"
#include "my.h"

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static const char *FILE_EXTENSION = "_channel.save";

static channel_t *add_empty_node(channel_t *channel)
{
    channel->next = create_empty_channel();
    channel->next->prev = channel;
    channel = channel->next;
    return channel;
}

void save_channels_list(channel_t *list, const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = create_file(full_path);

    if (full_path)
        free(full_path);
    if (fd == -1)
        return;
    for (; list; list = list->next) {
        if (!strcmp(list->uuid, ""))
            continue;
        write(fd, list, sizeof(channel_t));
        full_path = my_strcat(3, filepath, "_", list->uuid);
        if (list->threads_list)
            save_threads_list(list->threads_list, full_path);
        free(full_path);
    }
    close(fd);
}

static channel_t *get_threads_list(channel_t *channel, const char *filepath)
{
    char *full_path = my_strcat(3, filepath, "_", channel->uuid);

    channel->threads_list = load_threads_list(full_path);
    free(full_path);
    return channel;
}

static channel_t *load_loop(int fd, const char *filepath, channel_t *list)
{
    channel_t *tmp = NULL;
    channel_t buff = {0};

    while (read(fd, &buff, sizeof(channel_t)) > 0) {
        if (!list) {
            list = create_empty_channel();
            tmp = list;
        } else
            tmp = add_empty_node(tmp);
        if (!tmp)
            return destroy_channels_list(list);
        tmp = channel_cpy(tmp, &buff);
        tmp = get_threads_list(tmp, filepath);
    }
    return list;
}

channel_t *load_channels_list(const char *filepath)
{
    char *full_path = my_strcat(2, filepath, FILE_EXTENSION);
    int fd = open(full_path, O_RDONLY);
    channel_t *list = NULL;

    if (full_path)
        free(full_path);
    if (fd == -1)
        return NULL;
    list = load_loop(fd, filepath, list);
    close(fd);
    return list;
}