#include "../include/NORGate.h"

NORGate::NORGate() = default;
NORGate::~NORGate() = default;

void NORGate::calculateOutput() {
    if(in1->getValue() + in2->getValue() == 0)
        out->setValue(1);
    else
        out->setValue(0);
}
