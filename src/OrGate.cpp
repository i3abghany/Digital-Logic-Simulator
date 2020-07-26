#include "../include/OrGate.h"

OrGate::OrGate() = default;
OrGate::~OrGate() = default;

void OrGate::calculateOutput() {
    if(in1->getValue() || in2->getValue())
        out->setValue(1);
    else
        out->setValue(0);
}
