#ifndef LOGIC_SIMULATOR_NANDGATE_H
#define LOGIC_SIMULATOR_NANDGATE_H

#include "Gate.h"

class NANDGate : public Gate{
public:
    void calculateOutput();
    NANDGate();
    ~NANDGate();
};


#endif //LOGIC_SIMULATOR_NANDGATE_H
