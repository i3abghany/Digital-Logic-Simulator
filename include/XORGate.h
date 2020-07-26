#ifndef LOGIC_SIMULATOR_XORGATE_H
#define LOGIC_SIMULATOR_XORGATE_H

#include "Gate.h"

class XORGate : public Gate {
public:
    XORGate();
    ~XORGate();
    void calculateOutput();
};



#endif //LOGIC_SIMULATOR_XORGATE_H
