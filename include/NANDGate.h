#ifndef LOGIC_SIMULATOR_NANDGATE_H
#define LOGIC_SIMULATOR_NANDGATE_H

#include "Gate.h"

class NANDGate : public Gate{
public:
    void calculateOutput() override;
    NANDGate();
    ~NANDGate() override;
};


#endif //LOGIC_SIMULATOR_NANDGATE_H
