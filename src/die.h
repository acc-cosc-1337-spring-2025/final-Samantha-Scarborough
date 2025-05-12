// Die.h
#ifndef DIE_H
#define DIE_H

class Die {
public:
    Die();         // Constructor

    int roll();    // Rolls the die and returns a value from 1 to 6

private:
    int sides;     // Number of sides on the die (always 6)
};

#endif // DIE_H
//Question 1