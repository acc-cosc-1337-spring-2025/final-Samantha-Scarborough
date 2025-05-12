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