// Shooter.cpp
#include "Shooter.h"
#include <iostream>

// Constructor
Shooter::Shooter() {
    // Nothing to do here
}

// Destructor: delete all dynamically allocated rolls
Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}

// throw_dice: creates and returns a new Roll*, stores it
Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* new_roll = new Roll(die1, die2);
    new_roll->roll_dice();
    rolls.push_back(new_roll);
    return new_roll;
}

// display_rolled_values: iterates and displays each rolled value
void Shooter::display_rolled_values() const {
    for (const Roll* roll : rolls) {
        std::cout << "Rolled value: " << roll->roll_value() << std::endl;
    }
}
// main.cpp
#include <iostream>
#include <cassert>
#include "Die.h"
#include "Roll.h"
#include "Shooter.h"

int main() {
    Die die1;
    Die die2;
    Shooter shooter;

    std::cout << "Testing shooter with 10 throws...\n";

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice(die1, die2);
        int result = roll->roll_value();

        std::cout << "Throw " << (i + 1) << ": " << result << std::endl;

        // Test Case 1–5: Assert valid range
        assert(result >= 2 && result <= 12);
    }

    std::cout << "\nAll values valid. Displaying rolled values:\n";
    shooter.display_rolled_values();

    // Destructor will clean up Roll* instances automatically
    std::cout << "Test completed. Memory cleaned up.\n";
    return 0;
}
//Question 3 