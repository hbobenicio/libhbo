#include "arraylist.h"
#include <assert.h>

hbo_arraylist arraylist_new() {
    return arraylist_from_capacity(HBO_ARRAYLIST_DEFAULT_CAPACITY);
}

hbo_arraylist arraylist_from_capacity(size_t cap) {
    assert(cap > 0);

    hbo_arraylist list = {
        .capacity = cap,
        .length = 0,
        .items = (int*) malloc(cap * sizeof(int)), //calloc?
    };
    return list;
}

void arraylist_free(hbo_arraylist* list) {
    free(list->items);
    list->capacity = 0;
    list->length = 0;
    list->items = NULL;
}

void arraylist_append(hbo_arraylist* self, int item) {
    if (self->length + 1 > self->capacity) {
        self->capacity *= 2;
        self->items = realloc(self->items, self->capacity * sizeof(int));
    }
    self->items[self->length] = item;
    self->length++;
}
