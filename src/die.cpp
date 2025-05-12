// Die.cpp
#include "Die.h"
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

// Constructor definition
Die::Die() {
    sides = 6;

    // Seed the random number generator once per program run
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// roll function definition
int Die::roll() {
    return (std::rand() % sides) + 1;  // Returns 1 through 6
}
//Question 1