// Shooter.h
#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "Die.h"
#include "Roll.h"

class Shooter {
public:
    Shooter();  // Constructor
    ~Shooter(); // Destructor to clean up memory

    Roll* throw_dice(Die& die1, Die& die2); // Returns dynamically created Roll*
    void display_rolled_values() const;     // Prints all roll values

private:
    std::vector<Roll*> rolls; // Vector of Roll pointers (dynamically allocated)
};

#endif // SHOOTER_H
//Question 3