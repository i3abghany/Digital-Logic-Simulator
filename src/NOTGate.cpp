#include "../include/NOTGate.h"

NOTGate::~NOTGate() = default;
NOTGate::NOTGate() = default;



void NOTGate::calculateOutput() {
    if(in1->getValue() == 1)
        out->setValue(0);
    else out->setValue(1);
}