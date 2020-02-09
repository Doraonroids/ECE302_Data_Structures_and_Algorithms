#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset() construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE("Test bitset(9) construction", "[bitset]") {
    Bitset b(9);
    REQUIRE(b.size() == 9);
    REQUIRE(b.good());
}
TEST_CASE("Test bitset(9) construction", "[bitset]") {
    Bitset b(9);
    REQUIRE(b.size() == 9);
    REQUIRE(b.good());
}

TEST_CASE("Test bitset(string(010101)) construction", "[bitset]") {
    Bitset b("010101");
    REQUIRE(b.size() == 6);
    REQUIRE(b.test(1) == 1);
    REQUIRE(b.test(3) == 1);
    REQUIRE(b.test(5) == 1);
    REQUIRE(b.test(0) == 0);
    REQUIRE(b.test(2) == 0);
    REQUIRE(b.test(4) == 0);
    REQUIRE(b.good());
}


TEST_CASE("Test size returns", "[bitset]") {
    Bitset b;
    REQUIRE(b.size() == 6);
}