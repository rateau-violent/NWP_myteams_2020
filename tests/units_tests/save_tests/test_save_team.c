/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** test_save_team
*/

#include "team.h"

#include <criterion/criterion.h>
#include <string.h>
#include <stdbool.h>

bool compare_channels(const channel_t *c1, const channel_t *c2);

bool compare_subscribers(const subscriber_t *s1, const subscriber_t *s2);

bool compare_teams(const team_t *t1, const team_t *t2)
{
    if (!t1 && !t2)
        return true;
    if ((!t1 && t2) || (t1 && !t2))
        return false;
    return (!strcmp(t1->name, t2->name)
        && !strcmp(t1->description, t2->description)
        && !strcmp(t1->uuid, t2->uuid)
        && compare_channels(t1->channels_list, t2->channels_list)
        && compare_subscribers(t1->subscribers_list, t2->subscribers_list)
        && compare_teams(t1->next, t2->next));
}

Test(save_team, empty)
{
    team_t *t = create_empty_team();
    team_t *save = NULL;
    const char *filepath = "save_team_empty";

    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert_null(save);
}

Test(save_team, one_node_without_channel_without_thread_without_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_one_node_without_channel_without_thread_without_comment";

    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, one_node_one_channel_without_thread_without_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_one_node_one_channel_without_thread_without_comment";

    t->channels_list = add_channel_node(t->channels_list, "c1", "d2");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, one_node_one_channel_one_thread_without_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_one_node_one_channel_one_thread_without_comment";

    t->channels_list = add_channel_node(t->channels_list, "c1", "d2");
    t->channels_list->threads_list = add_thread_node(t->channels_list->threads_list, "u1", "t2", "m1");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, one_node_one_channel_one_thread_one_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_one_node_one_channel_one_thread_one_comment";

    t->channels_list = add_channel_node(t->channels_list, "c1", "d2");
    t->channels_list->threads_list = add_thread_node(t->channels_list->threads_list, "u1", "t2", "m1");
    t->channels_list->threads_list->comments_list = add_comment_node(t->channels_list->threads_list->comments_list, "u1", "m2");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, two_nodes_without_channel_without_thread_without_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_two_nodes_without_channel_without_thread_without_comment";

    t = add_team_node(t, "t2", "d2");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, two_nodes_one_channel_without_thread_without_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_two_nodes_one_channel_without_thread_without_comment";

    t->channels_list = add_channel_node(t->channels_list, "c1", "d1");
    t = add_team_node(t, "t2", "d2");
    t->next->channels_list = add_channel_node(t->next->channels_list, "c2", "d2");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, two_nodes_one_channel_one_thread_without_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_two_nodes_one_channel_one_thread_without_comment";

    t->channels_list = add_channel_node(t->channels_list, "c1", "d1");
    t->channels_list->threads_list = add_thread_node(t->channels_list->threads_list, "u1", "t3", "m1");
    t = add_team_node(t, "t2", "d2");
    t->next->channels_list = add_channel_node(t->next->channels_list, "c2", "d2");
    t->next->channels_list->threads_list = add_thread_node(t->next->channels_list->threads_list, "u1", "t3", "m2");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, two_nodes_one_channel_one_thread_one_comment)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_two_nodes_one_channel_one_thread_one_comment";

    t->channels_list = add_channel_node(t->channels_list, "c1", "d1");
    t->channels_list->threads_list = add_thread_node(t->channels_list->threads_list, "u1", "t3", "m2");
    t->channels_list->threads_list->comments_list = add_comment_node(t->channels_list->threads_list->comments_list, "u1", "m3");
    t = add_team_node(t, "t2", "d2");
    t->next->channels_list = add_channel_node(t->next->channels_list, "c2", "d2");
    t->next->channels_list->threads_list = add_thread_node(t->next->channels_list->threads_list, "u1", "t3", "m1");
    t->next->channels_list->threads_list->comments_list = add_comment_node(t->next->channels_list->threads_list->comments_list, "u1", "m3");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, one_subscriber)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_one_subscriber";

    t->subscribers_list = add_subscriber_node(t->subscribers_list, "sub1");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}

Test(save_team, two_subscribers)
{
    team_t *t = add_team_node(NULL, "t1", "d1");
    team_t *save = NULL;
    const char *filepath = "save_team_two_subscribers";

    t->subscribers_list = add_subscriber_node(t->subscribers_list, "sub1");
    t->subscribers_list = add_subscriber_node(t->subscribers_list, "sub2");
    save_teams_list(t, filepath);
    save = load_teams_list(filepath);
    cr_assert(compare_teams(t, save));
}