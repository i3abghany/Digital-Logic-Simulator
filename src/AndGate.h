#ifndef LOGIC_SIMULATOR_ANDGATE_H
#define LOGIC_SIMULATOR_ANDGATE_H

#include "Gate.h"

class AndGate : public Gate {
public:
    void calculateOutput();
    AndGate();
    ~AndGate();
};


#endif //LOGIC_SIMULATOR_ANDGATE_H
