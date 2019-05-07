#include "Gate.h"

#ifndef LOGIC_SIMULATOR_XNORGATE_H
#define LOGIC_SIMULATOR_XNORGATE_H


class XNORGate : public Gate{
public:
    XNORGate();
    void calculateOutput();
    ~XNORGate();
};


#endif //LOGIC_SIMULATOR_XNORGATE_H

