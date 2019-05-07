#include "NANDGate.h"

NANDGate::NANDGate() = default;
NANDGate::~NANDGate() = default;

void NANDGate::calculateOutput() {
    if((in1->getValue() + in2->getValue()) < 2)
        out->setValue(1);
    else
        out->setValue(0);
}
