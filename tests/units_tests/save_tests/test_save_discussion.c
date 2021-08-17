/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_discussion
*/

#include "discussion.h"

#include <stdbool.h>
#include <string.h>
#include <criterion/criterion.h>

bool compare_comments(const comment_t *c1, const comment_t *c2);

bool compare_discussions(const discussion_t *d1, const discussion_t *d2)
{
    if (!d1 && !d2)
        return true;
    if ((!d1 && d2) || (d1 && !d2))
        return false;
    return (!strcmp(d1->username, d2->username)
        && !strcmp(d1->other_uuid, d2->other_uuid)
        && compare_comments(d1->messages_list, d2->messages_list)
        && compare_discussions(d1->next, d2->next));
}

Test(save_discussion, empty)
{
    discussion_t *d = create_empty_discussion();
    const char *filepath = "save_discussion_empty";
    discussion_t *save = NULL;

    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert_null(save);
}

Test(save_discussion, one_node_without_message)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "dest1");
    const char *filepath = "save_discussion_one_node_without_message";
    discussion_t *save = NULL;

    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert(compare_discussions(d, save));
}

Test(save_discussion, two_nodes_without_message)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "dest1");
    const char *filepath = "save_discussion_two_nodes_without_message";
    discussion_t *save = NULL;

    d = add_discussion_node(d, "u1", "dest2");
    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert(compare_discussions(d, save));
}

Test(save_discussion, one_node_one_message)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "dest1");
    const char *filepath = "save_discussion_one_node_one_message";
    discussion_t *save = NULL;

    d->messages_list = add_comment_node(NULL, "u1", "m1");
    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert(compare_discussions(d, save));
}

Test(save_discussion, one_node_two_messages)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "dest1");
    const char *filepath = "save_discussion_one_node_two_messages";
    discussion_t *save = NULL;

    d->messages_list = add_comment_node(NULL, "u1", "m1");
    d->messages_list = add_comment_node(d->messages_list, "u1", "m2");
    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert(compare_discussions(d, save));
}

Test(save_discussion, two_nodes_one_message)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "o1");
    const char *filepath = "save_discussion_two_nodes_one_message";
    discussion_t *save = NULL;

    d->messages_list = add_comment_node(d->messages_list, "u1", "m1");
    d = add_discussion_node(d, "u1", "o2");
    d->next->messages_list = add_comment_node(d->next->messages_list,
        "u2", "m1");
    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert(compare_discussions(d, save));
}

Test(save_discussion, two_nodes_two_messages)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "o1");
    const char *filepath = "save_discussion_two_nodes_two_messages";
    discussion_t *save = NULL;

    d->messages_list = add_comment_node(d->messages_list, "u1", "m1");
    d->messages_list = add_comment_node(d->messages_list, "u1", "m2");
    d = add_discussion_node(d, "u1", "o2");
    d->next->messages_list = add_comment_node(d->next->messages_list,
        "u2", "m1");
    d->next->messages_list = add_comment_node(d->next->messages_list,
        "u2", "m2");
    save_discussions_list(d, filepath);
    save = load_discussions_list(filepath);
    cr_assert(compare_discussions(d, save));
}

Test(save_discussion, empty_after_destroy)
{
    discussion_t *d = create_empty_discussion();
    const char *filepath = "save_discussion_empty_after_destroy";
    discussion_t *save = NULL;

    save_discussions_list(d, filepath);
    destroy_discussions_list(d);
    save = load_discussions_list(filepath);
    cr_assert_null(save);
}

Test(save_discussion, two_nodes_two_messages_after_destroy)
{
    discussion_t *d = add_discussion_node(NULL, "u1", "o1");
    const char *filepath = "save_discussion_two_nodes_two_messages_after_destroy";
    discussion_t *save = NULL;

    d->messages_list = add_comment_node(d->messages_list, "u1", "m1");
    d->messages_list = add_comment_node(d->messages_list, "u1", "m2");
    d = add_discussion_node(d, "u1", "o2");
    d->next->messages_list = add_comment_node(d->next->messages_list,
        "u2", "m1");
    d->next->messages_list = add_comment_node(d->next->messages_list,
        "u2", "m2");
    save_discussions_list(d, filepath);
    destroy_discussions_list(d);
    save = load_discussions_list(filepath);
    cr_assert_not_null(save);
}