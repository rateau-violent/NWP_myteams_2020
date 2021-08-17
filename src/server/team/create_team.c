/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** create_team
*/

#include "team.h"
#include "myteams.h"

#include <stdlib.h>
#include <string.h>

static team_t *create_team(const char *name, const char *description)
{
    team_t *new = calloc(1, (sizeof(team_t)));
    char *uuid = NULL;

    if (!new)
        return NULL;
    uuid = generate_uuid();
    if (!uuid)
        return destroy_team_list(new);
    strcpy(new->name, name);
    strcpy(new->description, description);
    strcpy(new->uuid, uuid);
    free(uuid);
    return (!new->name || !new->description || !new->uuid) ?
        destroy_team_list(new) : new;
}

team_t *create_empty_team(void)
{
    team_t *new = calloc(1, sizeof(team_t));

    if (!new)
        return NULL;
    strcpy(new->name, "");
    strcpy(new->description, "");
    new->subscribers_list = create_empty_subscriber();
    new->channels_list = create_empty_channel();
    strcpy(new->uuid, "");
    return (!new->name || !new->description || !new->subscribers_list ||
        !new->channels_list) ? destroy_team_list(new) : new;
}

team_t *add_team_node(team_t *list, const char *name, const char *description)
{
    team_t *tmp = list;

    if (!list)
        return create_team(name, description);
    while (tmp->next) {
        if (!strcmp(tmp->name, name))
            return list;
        tmp = tmp->next;
    }
    tmp->next = create_team(name, description);
    if (tmp->next)
        tmp->next->prev = tmp;
    return list;
}

team_t *team_cpy(team_t *t1, const team_t *t2)
{
    if (!t1 || !t2)
        return NULL;
    strcpy(t1->name, t2->name);
    strcpy(t1->description, t2->description);
    strcpy(t1->uuid, t2->uuid);
    return t1;
}