#ifndef HBO_STRING_VIEW_H
#define HBO_STRING_VIEW_H

#include <stddef.h>

typedef struct {
    const char* str;
    size_t length;
} hbo_string_view;

hbo_string_view hbo_string_view_from_str(const char* str);
hbo_string_view hbo_string_view_from_slice(const char* str, size_t start_index, size_t end_index);

#endif
