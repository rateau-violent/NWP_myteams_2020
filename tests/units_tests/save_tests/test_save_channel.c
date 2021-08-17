/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_channel
*/

#include "channel.h"

#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compare_threads(const thread_t *t1, const thread_t *t2);

bool compare_channels(const channel_t *c1, const channel_t *c2)
{
    if (!c1 && !c2)
        return true;
    if ((!c1 && c2) || (c1 && !c2))
        return false;
    return (!strcmp(c1->name, c2->name)
        && !strcmp(c1->description, c2->description)
        && !strcmp(c1->uuid, c2->uuid)
        && compare_threads(c1->threads_list, c2->threads_list)
        && compare_channels(c1->next, c2->next));
}

/*
** empty
*/

Test(save_channel, empty)
{
    channel_t *c = create_empty_channel();
    const char *filepath = "save_channel_empty";
    channel_t *save = NULL;

    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert_null(save);
}

/*
** one node
*/

Test(save_channel, one_node_without_thread_without_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_without_thread_without_comment";
    channel_t *save = NULL;

    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, one_node_one_thread_without_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_one_thread_without_comment";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, one_node_one_thread_one_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_one_thread_one_comment";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    c->threads_list->comments_list = add_comment_node(c->threads_list->comments_list, "u1", "m1");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, one_node_one_thread_two_comments)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_one_thread_two_comments";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    c->threads_list->comments_list = add_comment_node(c->threads_list->comments_list, "u1", "m1");
    c->threads_list->comments_list = add_comment_node(c->threads_list->comments_list, "u2", "m2");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, one_node_two_threads_without_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_two_threads_without_comment";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    c->threads_list = add_thread_node(c->threads_list, "u1", "t2", "m2");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, one_node_two_threads_one_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_two_threads_one_comment";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    c->threads_list->comments_list = add_comment_node(c->threads_list->comments_list, "u1", "m2");
    c->threads_list = add_thread_node(c->threads_list, "u1", "t2", "m3");
    c->threads_list->next->comments_list = add_comment_node(c->threads_list->next->comments_list, "u2", "m4");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, one_node_two_threads_two_comments)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_one_node_two_threads_two_comments";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    c->threads_list->comments_list = add_comment_node(c->threads_list->comments_list, "u1", "m2");
    c->threads_list->comments_list = add_comment_node(c->threads_list->comments_list, "u1", "m3");
    c->threads_list = add_thread_node(c->threads_list, "u1", "t2", "m4");
    c->threads_list->next->comments_list = add_comment_node(c->threads_list->next->comments_list, "u2", "m5");
    c->threads_list->next->comments_list = add_comment_node(c->threads_list->next->comments_list, "u2", "m6");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

/*
** two nodes
*/

Test(save_channel, two_nodes_without_thread_without_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_two_nodes_without_thread_without_comment";
    channel_t *save = NULL;

    c = add_channel_node(c, "c2", "d2");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}

Test(save_channel, two_nodes_one_thread_without_comment)
{
    channel_t *c = add_channel_node(NULL, "c1", "d1");
    const char *filepath = "save_channel_two_nodes_one_thread_without_comment";
    channel_t *save = NULL;

    c->threads_list = add_thread_node(c->threads_list, "u1", "t1", "m1");
    c = add_channel_node(c, "c2", "d2");
    c->threads_list = add_thread_node(c->threads_list, "u1", "t2", "m3");
    save_channels_list(c, filepath);
    save = load_channels_list(filepath);
    cr_assert(compare_channels(c, save));
}