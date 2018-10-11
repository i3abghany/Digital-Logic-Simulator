#include "AndGate.h"

AndGate::AndGate() {

}

AndGate::~AndGate() {

}

void AndGate::calculateOutput() {
    if(in1->getValue() && in2->getValue())
        out->setValue(1);
    else
        out->setValue(0);
}