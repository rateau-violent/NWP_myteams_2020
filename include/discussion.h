/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** discussion
*/

#ifndef DISCUSSION_H_
#define DISCUSSION_H_

#include "comment.h"

typedef struct discussion_s
{
    char username[MAX_NAME_LENGTH + 1];
    char other_uuid[UUID_LENGTH + 1];
    comment_t *messages_list;
    struct discussion_s *prev;
    struct discussion_s *next;
} discussion_t;


discussion_t *add_discussion_node(discussion_t *list, const char *username,
    const char *other);
discussion_t *create_empty_discussion(void);
discussion_t *discussion_cpy(discussion_t *d1, const discussion_t *d2);

discussion_t *get_discussion_from_other(discussion_t *list,
    const char *other);
size_t get_discussions_nb(discussion_t *list);


discussion_t *destroy_discussions_list(discussion_t *list);


void save_discussions_list(discussion_t *list, const char *filepath);
discussion_t *load_discussions_list(const char *filename);

#endif /* !DISCUSSION_H_ */