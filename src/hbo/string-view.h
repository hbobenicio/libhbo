#ifndef HBO_STRING_VIEW_H
#define HBO_STRING_VIEW_H

#include <stddef.h>

typedef struct {
    char* str;
    size_t length;
} hbo_string_view;

#endif
