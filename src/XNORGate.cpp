#include "../include/XNORGate.h"

XNORGate::XNORGate() = default;
XNORGate::~XNORGate() = default;

void XNORGate::calculateOutput() {
    if((!in1->getValue() && !in2->getValue()) || (in1->getValue() && in2->getValue()))
        out->setValue(1);
    else
        out->setValue(0);
}
