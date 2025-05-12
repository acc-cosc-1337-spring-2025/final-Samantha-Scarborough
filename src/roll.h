// Roll.h
#ifndef ROLL_H
#define ROLL_H

#include "Die.h"

class Roll {
public:
    // Constructor: initializes die1 and die2 references via initializer list
    Roll(Die& d1, Die& d2);

    // Rolls both dice and stores the sum in rolled_value
    void roll_dice();

    // Returns the sum of the last roll
    int roll_value() const;

private:
    Die& die1;
    Die& die2;
    int rolled_value;
};

#endif // ROLL_H
//Question 2