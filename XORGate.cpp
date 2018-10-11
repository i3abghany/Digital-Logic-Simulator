#include "XORGate.h"

XORGate::XORGate() {

}
XORGate::~XORGate() {

}


void XORGate::calculateOutput() {
    if(in1->getValue() + in2->getValue() == 1)
        out->setValue(1);
    else
        out->setValue(0);
}