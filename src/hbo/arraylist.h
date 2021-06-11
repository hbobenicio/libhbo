#ifndef HBO_ARRAYLIST_H
#define HBO_ARRAYLIST_H

#include <stdlib.h>

#define HBO_ARRAYLIST_DEFAULT_CAPACITY 10

// TODO provide this struct via Macros for generics simulation
// (or maybe with the new _Generic macro)
typedef struct {
    size_t capacity;
    size_t length;

    int* items;
} hbo_arraylist;

hbo_arraylist arraylist_new();
hbo_arraylist arraylist_from_capacity(size_t cap);
void arraylist_free(hbo_arraylist* list);

void arraylist_append(hbo_arraylist* self, int item);

#endif

