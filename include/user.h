/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** client
*/

#ifndef USER_H_
#define USER_H_


#include <stdbool.h>
#include "discussion.h"
#include "my.h"

typedef struct user_s
{
    char username[MAX_NAME_LENGTH + 1];
    char uuid[UUID_LENGTH + 1];
    int *fds;
    size_t connection_nb;
    discussion_t *discussions_list;
    struct user_s *prev;
    struct user_s *next;
    bool logged_in;
} user_t;


user_t *add_user_node(user_t *list, const int fd);
user_t *create_empty_user(void);
user_t *user_cpy(user_t *c1, const user_t *c2);


user_t *remove_user_node_from_fd(user_t *list, int fd);
user_t *remove_user_node_from_uuid(user_t *list, const char *uuid);
user_t *destroy_users_list(user_t *list);
void close_fds(user_t *user);


user_t *add_fd_to_user(user_t *user, int fd);
user_t *remove_fd_from_user(user_t *user, int fd);


user_t *get_user_from_fd(user_t *list, const int fd);
user_t *get_user_from_username(user_t *list, const char *username);
user_t *get_user_from_uuid(user_t *list, const char *uuid);
size_t get_users_nb(user_t *list);
bool fd_already_exists(user_t *user, int fd);

void save_users_list(user_t *list, const char *filepath);
user_t *load_users_list(const char *filepath);


enum user_context get_user_context(user_t *user);

#endif /* !USER_H_ */