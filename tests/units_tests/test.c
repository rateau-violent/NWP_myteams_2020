/*
** EPITECH PROJECT, 2020
** test
** File description:
** stumper
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strlen, testing_my_strlen)
{
    char *test = "test";
    int i = 4;
    int result = 0;

    result = my_strlen(test);
    cr_assert_eq(i, result);
}
