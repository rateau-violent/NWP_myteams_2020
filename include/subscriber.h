/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** subscriber
*/

#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include "myteams.h"
#include "user.h"

typedef struct subscriber_s
{
    char uuid[UUID_LENGTH + 1];
    struct subscriber_s *prev;
    struct subscriber_s *next;
} subscriber_t;

subscriber_t *create_empty_subscriber(void);
subscriber_t *add_subscriber_node(subscriber_t *list, const char *uuid);
subscriber_t *subscriber_cpy(subscriber_t *s1, const subscriber_t *s2);


subscriber_t *get_subscriber_from_uuid(subscriber_t *list, const char *uuid);
bool is_a_subscriber(subscriber_t *list, user_t *user);


subscriber_t *remove_subscriber_node(subscriber_t *list, const char *uuid);
subscriber_t *destroy_subscribers_list(subscriber_t *list);


void save_subscribers_list(subscriber_t *list, const char *filepath);
subscriber_t *load_subscribers_list(const char *filepath);

#endif /* !SUBSCRIBER_H_ */
