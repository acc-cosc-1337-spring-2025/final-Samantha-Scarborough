// phase.h
#ifndef PHASE_H
#define PHASE_H

#include "Roll.h"

enum class RollOutcome {
    natural,
    craps,
    point,
    seven_out,
    nopoint
};

class Phase {
public:
    virtual RollOutcome get_outcome(Roll* roll) = 0; // pure virtual
    virtual ~Phase() = default;                      // virtual destructor
};

#endif // PHASE_H
//Question 4