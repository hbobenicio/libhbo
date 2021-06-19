extern "C" {
    #include <hbo/string-view.h>
}

#include <cstring>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

SCENARIO("string views must be created from null terminated C strings") {
    GIVEN("a string") {
        const char* str = "Hello, World!";
        size_t str_length = strlen(str);

        THEN("a string_view must point to the source string and have the same length of it") {
            hbo_string_view str_view = hbo_string_view_from_str(str);

            REQUIRE(str_view.str == str);
            REQUIRE(str_view.length == str_length);
        }
        THEN("a string_view must be constructable from a substring of it (aka a slice)") {
            constexpr size_t slice_length = 4;
            constexpr size_t start_index = 1;
            constexpr size_t end_index = start_index + slice_length;

            hbo_string_view slice = hbo_string_view_from_slice(str, start_index, end_index);

            REQUIRE(slice.length == slice_length);
            REQUIRE(strncmp("ello", slice.str, sizeof "ello") == 0);
        }
    }
}
