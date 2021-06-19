#include "string-view.h"

#include <string.h>
#include <assert.h>
#include <stdint.h>

hbo_string_view hbo_string_view_from_str(const char* str) {
    return (hbo_string_view) {
        .str = str,
        .length = strlen(str),
    };
}

hbo_string_view hbo_string_view_from_slice(const char* str, size_t start_index, size_t end_index) {
    assert(end_index > start_index);

    return (hbo_string_view) {
        .str = str + start_index,
        .length = end_index - start_index,
    };
}
