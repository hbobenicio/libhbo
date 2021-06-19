#ifndef HBO_ARRAYLIST_H
#define HBO_ARRAYLIST_H

#include <stddef.h>
#include <stdbool.h>

#define HBO_ARRAYLIST_DEFAULT_CAPACITY 10
#define HBO_ARRAYLIST_GROWING_FACTOR 2
#define HBO_ARRAYLIST_ITEM int

// TODO provide this struct via Macros for generics simulation
// (or maybe with the new _Generic macro)
typedef struct {
    size_t capacity;
    size_t length;

    HBO_ARRAYLIST_ITEM* items;
} hbo_arraylist;

hbo_arraylist hbo_arraylist_new();
hbo_arraylist hbo_arraylist_new_with_capacity(size_t cap);

bool hbo_arraylist_init(hbo_arraylist* self);
bool hbo_arraylist_init_with_capacity(hbo_arraylist* self, size_t cap);

void hbo_arraylist_free(hbo_arraylist* self);

void hbo_arraylist_append(hbo_arraylist* self, HBO_ARRAYLIST_ITEM item);
void hbo_arraylist_append_assuming_capacity(hbo_arraylist* self, HBO_ARRAYLIST_ITEM item);

void hbo_arraylist_ensure_capacity(hbo_arraylist* self, size_t new_cap);

#endif
