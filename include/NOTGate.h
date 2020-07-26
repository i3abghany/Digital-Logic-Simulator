#ifndef LOGIC_SIMULATOR_NOTGATE_H
#define LOGIC_SIMULATOR_NOTGATE_H

#include "Gate.h"

class NOTGate : public Gate {
public:
    NOTGate();
    void calculateOutput();
    ~NOTGate();
};


#endif //LOGIC_SIMULATOR_NOTGATE_H
