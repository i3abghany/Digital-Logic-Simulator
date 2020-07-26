#include "Gate.h"

#ifndef LOGIC_SIMULATOR_NORGATE_H
#define LOGIC_SIMULATOR_NORGATE_H

class NORGate : public Gate {
public:
	NORGate();
	void calculateOutput();
	~NORGate();
};

#endif

