// Roll.cpp
#include "Roll.h"

// Constructor with initializer list
Roll::Roll(Die& d1, Die& d2)
    : die1(d1), die2(d2), rolled_value(0) {
}

// Roll both dice and store the total in rolled_value
void Roll::roll_dice() {
    int value1 = die1.roll();
    int value2 = die2.roll();
    rolled_value = value1 + value2;
}

// Return the sum of the last roll
int Roll::roll_value() const {
    return rolled_value;
}
// main.cpp
#include <iostream>
#include <cassert>
#include "Die.h"
#include "Roll.h"

int main() {
    Die die1;
    Die die2;
    Roll roller(die1, die2);

    std::cout << "Testing 10 two-dice rolls:\n";

    for (int i = 0; i < 10; ++i) {
        roller.roll_dice();
        int result = roller.roll_value();

        std::cout << "Roll " << (i + 1) << ": " << result << std::endl;

        // Assert that the roll is within valid range for two six-sided dice
        assert(result >= 2 && result <= 12);
    }

    std::cout << "✅ All 10 rolls were within range (2 to 12). Test passed.\n";

    return 0;
}
//Questiion 2