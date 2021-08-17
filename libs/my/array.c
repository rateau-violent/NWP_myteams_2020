/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-victoire.rabeau
** File description:
** strings_to_array
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

size_t get_array_length(char **array)
{
    size_t size = 0;

    if (!array)
        return 0;
    while (array[size])
        size++;
    return size;
}

void destroy_array(char **array)
{
    if (!array)
        return;
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

char **strings_to_array(size_t count, ...)
{
    va_list argPtr;
    char **array = NULL;

    va_start(argPtr, count);
    for (size_t i = 0; i < count; i++) {
        array = realloc(array, sizeof(char *) * (i + 2));
        if (!array)
            return NULL;
        array[i] = strdup(va_arg(argPtr, char *));
        if (!array[i])
            return NULL;
        array[i + 1] = NULL;
    }
    va_end(argPtr);
    return array;
}