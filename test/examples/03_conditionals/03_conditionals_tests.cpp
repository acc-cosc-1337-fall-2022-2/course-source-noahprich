#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"
#include "if_else_if.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
 
TEST_CASE("Test is overtime function")
{
	REQUIRE(is_overtime(30) == false);
	REQUIRE(is_overtime(40) == false);
	REQUIRE(is_overtime(41) == true);
}

TEST_CASE("Test get generation")
{
	REQUIRE(get_generation(1997) == "Centenial");
	REQUIRE(get_generation(1980) == "Millenial");
}