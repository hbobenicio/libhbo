#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include <hbo/arraylist.h>

TEST_CASE("Basic Tests", "[arraylist]") {
    hbo_arraylist list = arraylist_from_capacity(3);

    REQUIRE(list.capacity == 3);
    REQUIRE(list.length == 0);
    REQUIRE(list.items != nullptr);

    arraylist_append(&list, 1);
    arraylist_append(&list, 2);
    arraylist_append(&list, 3);
    arraylist_append(&list, 4);
    arraylist_append(&list, 5);

    REQUIRE(list.capacity == 6);
    REQUIRE(list.length == 5);
    REQUIRE(list.items[0] == 1);
    REQUIRE(list.items[1] == 2);
    REQUIRE(list.items[2] == 3);
    REQUIRE(list.items[3] == 4);
    REQUIRE(list.items[4] == 5);

    arraylist_free(&list);

    REQUIRE(list.capacity == 0);
    REQUIRE(list.length == 0);
    REQUIRE(list.items == nullptr);

    list = arraylist_new();

    REQUIRE(list.capacity == HBO_ARRAYLIST_DEFAULT_CAPACITY);
    REQUIRE(list.length == 0);
    REQUIRE(list.items != nullptr);

    arraylist_free(&list);
}
