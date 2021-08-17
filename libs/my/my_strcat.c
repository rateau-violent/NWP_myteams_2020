/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** my_strcat
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *my_strcat(size_t count, ...)
{
    va_list argPtr;
    char *new = calloc(1, sizeof(char));
    char *s = NULL;

    va_start(argPtr, count);
    for (size_t i = 0; i < count; i++) {
        s = va_arg(argPtr, char *);
        new = realloc(new, sizeof(char) * (strlen(new) + strlen(s) + 1));
        if (!new)
            return NULL;
        new = strcat(new, s);
        if (!new)
            return NULL;
    }
    va_end(argPtr);
    return new;
}