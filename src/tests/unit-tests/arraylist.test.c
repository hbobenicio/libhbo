#include "arraylist.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void basic_tests();

int main() {
    basic_tests();
}

void basic_tests() {
    ArrayList list = arraylist_from_capacity(3);

    assert(list.capacity == 3);
    assert(list.length == 0);
    assert(list.items != NULL);

    arraylist_append(&list, 1);
    arraylist_append(&list, 2);
    arraylist_append(&list, 3);
    arraylist_append(&list, 4);
    arraylist_append(&list, 5);

    assert(list.capacity == 6);
    assert(list.length == 5);
    assert(list.items[0] == 1);
    assert(list.items[1] == 2);
    assert(list.items[2] == 3);
    assert(list.items[3] == 4);
    assert(list.items[4] == 5);

    arraylist_free(&list);

    assert(list.capacity == 0);
    assert(list.length == 0);
    assert(list.items == NULL);

    list = arraylist_new();

    assert(list.capacity == ARRAYLIST_DEFAULT_CAPACITY);
    assert(list.length == 0);
    assert(list.items != NULL);

    arraylist_free(&list);
}
