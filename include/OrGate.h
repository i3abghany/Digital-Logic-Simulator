#ifndef LOGIC_SIMULATOR_ORGATE_H
#define LOGIC_SIMULATOR_ORGATE_H

#include "Gate.h"

class OrGate : public Gate {
public:
    OrGate();
    void calculateOutput();
    ~OrGate();
};


#endif //LOGIC_SIMULATOR_ORGATE_H
