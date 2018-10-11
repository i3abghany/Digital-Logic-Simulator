#include "Gate.h"

Gate::Gate() {
    in1 = NULL;
    in2 = NULL;
    out = NULL;
}
void Gate::setIn1(Node* n) {
    in1 = n;
}

void Gate::setIn2(Node * n) {
    in2 = n;
}

void Gate::setOut(Node * n) {
    out = n;
}

Node* Gate::getIn1() {
    return in1;
}

Node* Gate::getIn2() {
    return in2;
}

Node* Gate::getOut() {
    return out;
}

Gate::~Gate() {

}




