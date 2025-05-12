// main.cpp
#include <iostream>
#include "Die.h"

int main() {
    Die myDie;

    std::cout << "Rolling the die 10 times:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "Roll " << (i + 1) << ": " << myDie.roll() << std::endl;
    }

    return 0;
}
//Question 1


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Die.h"
#include "Roll.h"
#include "Shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include "phase.h"

int main() {
    std::srand(std::time(0));  // Ensure true random numbers

    Die die1, die2;
    Shooter shooter;
    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

    ComeOutPhase come_out_phase;
    RollOutcome outcome = come_out_phase.get_outcome(roll);

    // Come Out Loop
    while (outcome == RollOutcome::natural || outcome == RollOutcome::craps) {
        std::cout << "Rolled " << rolled_value << " roll again" << std::endl;

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
        outcome = come_out_phase.get_outcome(roll);
    }

    // Start of Point Phase
    std::cout << "Rolled " << rolled_value << " start of point phase" << std::endl;
    std::cout << "Roll until " << rolled_value << " or a 7 is rolled" << std::endl;

    int point = rolled_value;
    roll = shooter.throw_dice(die1, die2);
    rolled_value = roll->roll_value();

    PointPhase point_phase(point);
    outcome = point_phase.get_outcome(roll);

    // Point Phase Loop
    while (outcome != RollOutcome::seven_out && outcome != RollOutcome::point) {
        std::cout << "Rolled " << rolled_value << " roll again" << std::endl;

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
        outcome = point_phase.get_outcome(roll);
    }

    // End of Point Phase
    std::cout << "Rolled " << rolled_value << " end of point phase" << std::endl;

    // Show all rolls
    shooter.display_rolled_values();

    return 0;
}
//Question 5 