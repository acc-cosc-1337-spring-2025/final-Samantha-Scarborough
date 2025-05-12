#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
// main.cpp
#include <iostream>
#include <cassert>   // For assert
#include "Die.h"

int main() {
    Die myDie;

    std::cout << "Rolling the die 10 times and asserting valid range (1-6):\n";

    for (int i = 0; i < 10; ++i) {
        int result = myDie.roll();
        std::cout << "Roll " << (i + 1) << ": " << result << std::endl;

        // Assert the result is within 1 to 6
        assert(result >= 1 && result <= 6);
    }

    std::cout << "All rolls were valid. Test passed.\n";

    return 0;
}
//Question 1