/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_comment
*/

#include "comment.h"

#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compare_comments(const comment_t *c1, const comment_t *c2)
{
    if (!c1 && !c2)
        return true;
    if ((!c1 && c2) || (c1 && !c2))
        return false;
    return (!strcmp(c1->author_uuid, c2->author_uuid)
        && !strcmp(c1->message, c2->message)
        && (c1->time == c2->time)
        && compare_comments(c1->next, c2->next));
}

Test(save_comment, empty)
{
    comment_t *c = create_empty_comment();
    const char *filepath = "save_comment_empty";
    comment_t *save = NULL;

    save_comments_list(c, filepath);
    save = load_comments_list(filepath);
    cr_assert(compare_comments(c, save));
}

Test(save_comment, one_node)
{
    comment_t *c = add_comment_node(NULL, "name 1", "message 1");
    const char *filepath = "save_comment_one_node";
    comment_t *save = NULL;

    save_comments_list(c, filepath);
    save = load_comments_list(filepath);
    cr_assert(compare_comments(c, save));
}

Test(save_comment, two_nodes)
{
    comment_t *c = add_comment_node(NULL, "name 1", "message 1");
    const char *filepath = "save_comment_two_nodes";
    comment_t *save = NULL;

    c = add_comment_node(c, "name 2", "message 2");
    save_comments_list(c, filepath);
    save = load_comments_list(filepath);
    cr_assert(compare_comments(c, save));
}

Test(save_comment, empty_after_destroy)
{
    comment_t *c = create_empty_comment();
    const char *filepath = "save_comment_empty_after_destroy";
    comment_t *save = NULL;

    save_comments_list(c, filepath);
    destroy_comments_list(c);
    save = load_comments_list(filepath);
    cr_assert_not_null(save);
}

Test(save_comment, one_node_after_destroy)
{
    comment_t *c = add_comment_node(NULL, "name 1", "message 1");
    const char *filepath = "save_comment_one_node_after_destroy";
    comment_t *save = NULL;

    save_comments_list(c, filepath);
    destroy_comments_list(c);
    save = load_comments_list(filepath);
    cr_assert(compare_comments(add_comment_node(NULL, "name 1", "message 1"), save));
}

Test(save_comment, two_nodes_after_destroy)
{
    comment_t *c = add_comment_node(NULL, "name 1", "message 1");
    const char *filepath = "save_comment_two_nodes_after_destroy";
    comment_t *save = NULL;

    c = add_comment_node(c, "name 2", "message 2");
    save_comments_list(c, filepath);
    destroy_comments_list(c);
    save = load_comments_list(filepath);
    cr_assert_not_null(save);
}