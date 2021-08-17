/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** save_subscriber
*/

#include "subscriber.h"

#include <criterion/criterion.h>
#include <stdbool.h>

bool compare_subscribers(const subscriber_t *s1, const subscriber_t *s2)
{
    if (!s1 && !s2)
        return true;
    if ((!s1 && s2) || (s1 && !s2))
        return false;
    return (!strcmp(s1->uuid, s2->uuid)
        && compare_subscribers(s1->next, s2->next));
}

Test(save_subscribers_list, empty)
{
    subscriber_t *s = create_empty_subscriber();
    subscriber_t *save = NULL;
    const char *filepath = "save_subscriber_empty";

    save_subscribers_list(s, filepath);
    save = load_subscribers_list(filepath);
    cr_assert_null(save);
}

Test(save_subscribers_list, one_node)
{
    subscriber_t *s = add_subscriber_node(NULL, "1234");
    subscriber_t *save = NULL;
    const char *filepath = "save_subscriber_one_node";

    save_subscribers_list(s, filepath);
    save = load_subscribers_list(filepath);
    cr_assert(compare_subscribers(s, save));
}

Test(save_subscribers_list, two_nodes)
{
    subscriber_t *s = add_subscriber_node(NULL, "1234");
    subscriber_t *save = NULL;
    const char *filepath = "save_subscriber_two_nodes";

    s = add_subscriber_node(s, "2345");
    save_subscribers_list(s, filepath);
    save = load_subscribers_list(filepath);
    cr_assert(compare_subscribers(s, save));
}