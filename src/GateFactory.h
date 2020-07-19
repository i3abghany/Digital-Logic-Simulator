#ifndef LOGIC_SIMULATOR_GATE_FACTORY_H
#define LOGIC_SIMULATOR_GATE_FACTORY_H

#include <iostream>
#include "AndGate.h"
#include "OrGate.h"
#include "XORGate.h"
#include "NANDGate.h"
#include "XNORGate.h"
#include "NORGate.h"
#include "NOTGate.h"

class GateFactory {
    public:
	static Gate *CreateGate(const std::string &);
};

#endif
