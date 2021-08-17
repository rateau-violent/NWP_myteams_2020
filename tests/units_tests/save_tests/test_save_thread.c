/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_thread
*/

#include "thread.h"

#include <criterion/criterion.h>
#include <stdbool.h>

bool compare_comments(const comment_t *c1, const comment_t *c2);

bool compare_threads(const thread_t *t1, const thread_t *t2)
{
    if (!t1 && !t2)
        return true;
    if ((!t1 && t2) || (t1 && !t2))
        return false;
    return (!strcmp(t1->title, t2->title)
        && !strcmp(t1->message, t2->message)
        && !strcmp(t1->uuid, t2->uuid)
        && !strcmp(t1->author, t2->author)
        && (t1->time == t2->time)
        && compare_comments(t1->comments_list, t2->comments_list)
        && compare_threads(t1->next, t2->next));
}

Test(save_thread, empty)
{
    thread_t *t = create_empty_thread();
    const char *filepath = "save_thread_empty";
    thread_t *save = NULL;

    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert_null(save);
}

Test(save_thread, one_thread_witout_comment)
{
    thread_t *t = add_thread_node(NULL,"u1", "t1", "m1");
    const char *filepath = "save_thread_one_thread_witout_comment";
    thread_t *save = NULL;

    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert(compare_threads(t, save));
}

Test(save_thread, two_threads_witout_comment)
{
    thread_t *t = add_thread_node(NULL,"u1", "t1", "m1");
    const char *filepath = "save_thread_two_threads_witout_comment";
    thread_t *save = NULL;

    t = add_thread_node(t, "u1", "t1", "m2");
    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert(compare_threads(t, save));
}

Test(save_thread, one_node_one_message)
{
    thread_t *t = add_thread_node(NULL,"u1", "u1", "dest1");
    const char *filepath = "save_thread_one_node_one_message";
    thread_t *save = NULL;

    t->comments_list = add_comment_node(NULL, "u1", "m1");
    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert(compare_threads(t, save));
}

Test(save_thread, one_node_two_messages)
{
    thread_t *t = add_thread_node(NULL,"u2", "u1", "dest1");
    const char *filepath = "save_thread_one_node_two_messages";
    thread_t *save = NULL;

    t->comments_list = add_comment_node(NULL, "u1", "m1");
    t->comments_list = add_comment_node(t->comments_list, "u1", "m2");
    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert(compare_threads(t, save));
}

Test(save_thread, two_nodes_one_message)
{
    thread_t *t = add_thread_node(NULL,"u1", "t1", "o1");
    const char *filepath = "save_thread_two_nodes_one_message";
    thread_t *save = NULL;

    t->comments_list = add_comment_node(t->comments_list, "u1", "m1");
    t = add_thread_node(t, "u2", "t1", "o2");
    t->next->comments_list = add_comment_node(t->next->comments_list,
        "u2", "m1");
    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert(compare_threads(t, save));
}

Test(save_thread, two_nodes_two_messages)
{
    thread_t *t = add_thread_node(NULL,"u1", "u1", "o1");
    const char *filepath = "save_thread_two_nodes_two_messages";
    thread_t *save = NULL;

    t->comments_list = add_comment_node(t->comments_list, "u1", "m1");
    t->comments_list = add_comment_node(t->comments_list, "u1", "m2");
    t = add_thread_node(t, "u2", "t1", "o2");
    t->next->comments_list = add_comment_node(t->next->comments_list,
        "u2", "m1");
    t->next->comments_list = add_comment_node(t->next->comments_list,
        "u2", "m2");
    save_threads_list(t, filepath);
    save = load_threads_list(filepath);
    cr_assert(compare_threads(t, save));
}

Test(save_thread, empty_after_destroy)
{
    thread_t *t = create_empty_thread();
    const char *filepath = "save_thread_empty_after_destroy";
    thread_t *save = NULL;

    save_threads_list(t, filepath);
    destroy_threads_list(t);
    save = load_threads_list(filepath);
    cr_assert_null(save);
}