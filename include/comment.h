/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** comment
*/

#ifndef COMMENT_H_
#define COMMENT_H_

#include <time.h>

#include "myteams.h"

typedef struct comment_s
{
    char author_uuid[UUID_LENGTH + 1];
    char message[MAX_BODY_LENGTH + 1];
    time_t time;
    struct comment_s *prev;
    struct comment_s *next;
} comment_t;


comment_t *add_comment_node(comment_t *list, const char *username,
    const char *message);
comment_t *create_empty_comment(void);
comment_t *comment_cpy(comment_t *c1, const comment_t *c2);


comment_t *remove_last_comment(comment_t *list);
comment_t *destroy_comments_list(comment_t *list);


size_t get_comments_nb(comment_t *list);
comment_t *get_last_comment(comment_t *list);


void save_comments_list(comment_t *list, const char *filepath);
comment_t *load_comments_list(const char *filepath);

#endif /* !COMMENT_H_ */