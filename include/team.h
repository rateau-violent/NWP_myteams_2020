/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** team
*/

#ifndef TEAM_H_
#define TEAM_H_

#include <stdbool.h>
#include "user.h"
#include "subscriber.h"
#include "channel.h"

typedef struct team_s
{
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    char uuid[UUID_LENGTH + 1];
    subscriber_t *subscribers_list;
    channel_t *channels_list;
    struct team_s *prev;
    struct team_s *next;
} team_t;


team_t *add_team_node(team_t *list, const char *name, const char *description);
team_t *create_empty_team(void);
team_t *team_cpy(team_t *t1, const team_t *t2);


team_t *remove_team_node(team_t *list, const char *name);
team_t *destroy_team_list(team_t *list);


team_t *get_team_from_name(team_t *list, const char *name);
team_t *get_team_from_uuid(team_t *list, const char *uuid);
size_t get_teams_nb(team_t *list);


void save_teams_list(team_t *list, const char *filepath);
team_t *load_teams_list(const char *filepath);


void dump_team(team_t *list);


bool team_or_user_error(team_t *team, user_t *user, int fd);
bool subscribers_list_error
    (subscriber_t *new_subscribers_list, user_t *user, int fd);

#endif /* !TEAM_H_ */