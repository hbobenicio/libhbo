#include <stdlib.h>
#include <assert.h>

#include "arraylist.h"

hbo_arraylist hbo_arraylist_new() {
    return hbo_arraylist_new_with_capacity(HBO_ARRAYLIST_DEFAULT_CAPACITY);
}

hbo_arraylist hbo_arraylist_new_with_capacity(size_t cap) {

    hbo_arraylist list = {0};
    assert(hbo_arraylist_init_with_capacity(&list, cap));

    return list;
}

bool hbo_arraylist_init(hbo_arraylist* self) {
    return hbo_arraylist_init_with_capacity(self, HBO_ARRAYLIST_DEFAULT_CAPACITY);
}

bool hbo_arraylist_init_with_capacity(hbo_arraylist* self, size_t cap) {
    assert(cap > 0);

    HBO_ARRAYLIST_ITEM* items = (HBO_ARRAYLIST_ITEM*) malloc(cap * sizeof(HBO_ARRAYLIST_ITEM));
    if (items == NULL) {
        self->capacity = 0;
        self->length = 0;
        self->items = NULL;
        return false;
    }

    self->capacity = cap;
    self->length = 0;
    self->items = items;
    return true;
}

void hbo_arraylist_free(hbo_arraylist* self) {
    free(self->items);

    self->capacity = 0;
    self->length = 0;
    self->items = NULL;
}

void hbo_arraylist_append(hbo_arraylist* self, HBO_ARRAYLIST_ITEM item) {
    if (self->length + 1 > self->capacity) {
        self->capacity *= HBO_ARRAYLIST_GROWING_FACTOR;
        self->items = realloc(self->items, self->capacity * sizeof(HBO_ARRAYLIST_ITEM));
    }
    self->items[self->length] = item;
    self->length++;
}

void hbo_arraylist_ensure_capacity(hbo_arraylist* self, size_t new_cap) {
    (void) self;
    (void) new_cap;
    assert(false && "TODO not implemented yet");
}

void hbo_arraylist_append_assuming_capacity(hbo_arraylist* self, HBO_ARRAYLIST_ITEM item) {
    (void) self;
    (void) item;
    assert(false && "TODO not implemented yet");
}
