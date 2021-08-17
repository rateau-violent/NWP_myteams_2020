/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** channel
*/

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "thread.h"

typedef struct channel_s
{
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    char uuid[UUID_LENGTH + 1];
    thread_t *threads_list;
    struct channel_s *prev;
    struct channel_s *next;
} channel_t;


channel_t *add_channel_node(channel_t *list,
    const char *name, const char *description);
channel_t *create_empty_channel(void);
channel_t *channel_cpy(channel_t *t1, const channel_t *t2);


channel_t *get_channel_from_name(channel_t *list, const char *name);
channel_t *get_channel_from_uuid(channel_t *list, const char *uuid);
size_t get_channels_nb(channel_t *list);


channel_t *remove_channel_node(channel_t *list, const char *uuid);
channel_t *destroy_channels_list(channel_t *list);


void save_channels_list(channel_t *list, const char *filepath);
channel_t *load_channels_list(const char *filepath);

#endif /* !CHANNEL_H_ */