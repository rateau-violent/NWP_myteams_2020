/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** test_save_user
*/

#include "user.h"

#include <criterion/criterion.h>
#include <stdbool.h>
#include <string.h>

bool compare_discussions(const discussion_t *d1, const discussion_t *d2);

bool compare_users(const user_t *u1, const user_t *u2)
{
    if (!u1 && !u2)
        return true;
    if ((!u1 && u2) || (u1 && !u2))
        return false;
    return (!strcmp(u1->username, u2->username)
        && !strcmp(u1->uuid, u2->uuid)
        && !u2->connection_nb
        && !u2->fds
        && compare_discussions(u1->discussions_list, u2->discussions_list)
        && compare_users(u1->next, u2->next));
}

Test(save_user, empty)
{
    user_t *u = create_empty_user();
    user_t *save = NULL;
    const char *filepath = "save_user_empty";

    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert_null(save);
}

Test(save_user, one_node_without_discussion_without_message)
{
    user_t *u = add_user_node(NULL, 1);
    user_t *save = NULL;
    const char *filepath = "save_user_one_node_without_discussion_without_message";

    strcpy(u->username, "n1");
    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert(compare_users(u, save));
}

Test(save_user, one_node_one_discussion_without_message)
{
    user_t *u = add_user_node(NULL, 1);
    user_t *save = NULL;
    const char *filepath = "save_user_one_node_one_discussion_without_message";

    strcpy(u->username, "n1");
    u->discussions_list = add_discussion_node(u->discussions_list, "u1", "u2");
    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert(compare_users(u, save));
}

Test(save_user, one_node_one_discussion_one_message)
{
    user_t *u = add_user_node(NULL, 1);
    user_t *save = NULL;
    const char *filepath = "save_user_one_node_one_discussion_one_message";

    strcpy(u->username, "n1");
    u->discussions_list = add_discussion_node(u->discussions_list, "u1", "u2");
    u->discussions_list->messages_list = add_comment_node(u->discussions_list->messages_list, "u3", "u4");
    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert(compare_users(u, save));
}

Test(save_user, two_nodes_without_discussion_without_message)
{
    user_t *u = add_user_node(NULL, 1);
    user_t *save = NULL;
    const char *filepath = "save_user_two_nodes_without_discussion_without_message";

    strcpy(u->username, "n1");
    u = add_user_node(u, 2);
    strcpy(u->next->username, "n2");
    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert(compare_users(u, save));
}

Test(save_user, two_nodes_one_discussion_without_message)
{
    user_t *u = add_user_node(NULL, 1);
    user_t *save = NULL;
    const char *filepath = "save_user_two_nodes_one_discussion_without_message";

    strcpy(u->username, "n1");
    u->discussions_list = add_discussion_node(u->discussions_list, "u1", "u2");
    u = add_user_node(u, 2);
    strcpy(u->next->username, "n1");
    u->next->discussions_list = add_discussion_node(u->next->discussions_list, "u3", "u4");
    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert(compare_users(u, save));
}

Test(save_user, two_nodes_one_discussion_one_message)
{
    user_t *u = add_user_node(NULL, 1);
    user_t *save = NULL;
    const char *filepath = "save_user_two_nodes_one_discussion_one_message";

    strcpy(u->username, "n1");
    u->discussions_list = add_discussion_node(u->discussions_list, "u1", "u2");
    u->discussions_list->messages_list = add_comment_node(u->discussions_list->messages_list, "u3", "u4");
    u = add_user_node(u, 2);
    strcpy(u->next->username, "n2");
    u->next->discussions_list = add_discussion_node(u->next->discussions_list, "u5", "u6");
    u->next->discussions_list->messages_list = add_comment_node(u->next->discussions_list->messages_list, "u7", "u8");
    save_users_list(u, filepath);
    save = load_users_list(filepath);
    cr_assert(compare_users(u, save));
}