extern "C" {
    #include <hbo/arraylist.h>
}

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

SCENARIO("arraylists can be created with default values or with a predefined capacity", "[hbo_arraylist]") {

    GIVEN("an arraylist created with the default constructor") {
        hbo_arraylist list = hbo_arraylist_new();

        THEN("its values should be the defaults") {
            REQUIRE(list.capacity == HBO_ARRAYLIST_DEFAULT_CAPACITY);
        }

        THEN("there must be no items") {
            REQUIRE(list.length == 0);
        }

        WHEN("the arraylist is freed") {
            hbo_arraylist_free(&list);

            THEN("its values should all be zeroed") {
                REQUIRE(list.capacity == 0);
                REQUIRE(list.length == 0);
                REQUIRE(list.items == nullptr);
            }
        }
    }
    
    GIVEN("an arraylist created with a predefined capacity N") {
        constexpr size_t N = 3;
        hbo_arraylist list = hbo_arraylist_new_with_capacity(N);

        THEN("it must be an empty list with N items pre-allocated") {
            REQUIRE(list.capacity == N);
            REQUIRE(list.length == 0);
            REQUIRE(list.items != nullptr);
        }

        hbo_arraylist_free(&list);
    }
}

// TODO separate this test scenario in 2 test cases:
// 1) N < cap; and
// 2) N == cap.
SCENARIO("arraylists should not reallocate or increase theirs capacities when we add N items, where N <= arraylist's current capacity") {

    GIVEN("an arraylist initialized with default capacity") {
        hbo_arraylist list = hbo_arraylist_new();

        const size_t capacity_before_inserts = list.capacity;
        int* const items_ptr = list.items;

        WHEN("we add N items, where N < list.capacity") {
            constexpr size_t N = 5;
            std::array<int, N> input_items = {1, 2, 3, 4, 5};

            static_assert(N == input_items.size(), "there must be N input items in the array.");
            assert(N < capacity_before_inserts);

            for (size_t i = 0; i < N; i++) {
                hbo_arraylist_append(&list, (HBO_ARRAYLIST_ITEM) input_items[i]);
            }

            THEN("its capacity must be the same before the inserts (no allocation should happen)") {
                REQUIRE(capacity_before_inserts == list.capacity);
            }

            THEN("items must point to the same address") {
                REQUIRE(items_ptr == list.items);
            }
            
            THEN("we must have N items") {
                REQUIRE(list.length == N);
            }

            THEN("they must be all in order") {
                for (size_t i = 0; i < input_items.size(); i++) {
                    REQUIRE(input_items[i] == list.items[i]);
                }
            }
        }
        hbo_arraylist_free(&list);
    }
}

SCENARIO("arraylists should reallocate and increase theirs capacities when we add N items, where N > arraylists's current capacity") {
    GIVEN("an arraylist initialized with capacity K") {
        constexpr size_t K = 3;
        hbo_arraylist list = hbo_arraylist_new_with_capacity(K);
        const size_t initial_capacity = list.capacity;
        REQUIRE(initial_capacity == K);

        WHEN("we add N items in it, where N > K") {
            constexpr size_t N = 5;
            for (size_t i = 0; i < N; i++) {
                hbo_arraylist_append(&list, (HBO_ARRAYLIST_ITEM) i);
            }

            THEN("its capacity must increase to fit all elements") {
                REQUIRE(list.capacity > initial_capacity);
            }
            THEN("all inserted items must be there (reallocation must copy all previous values)") {
                REQUIRE(list.length == N);
                for (size_t i = 0; i < N; i++) {
                    REQUIRE(list.items[i] == (HBO_ARRAYLIST_ITEM) i);
                }
            }
        }

        hbo_arraylist_free(&list);
    }
}