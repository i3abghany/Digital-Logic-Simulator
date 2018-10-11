#ifndef LOGIC_SIMULATOR_GATE_H
#define LOGIC_SIMULATOR_GATE_H

#include "Node.h"


/*
 * An abstract class that has the main properties of the 2-input-1-output logic gates.
 */
class Gate {
protected:  // so as to be accessed from the child classes.
    Node* in1;
    Node* in2;
    Node* out;
public:
    Gate(); //default constructor
    // setting the nodes of a gate trough these nodes.
    void setIn1(Node*);
    void setIn2(Node*);
    void setOut(Node*);

    // getters for the two inputs and outputs for the gate.
    Node* getIn1();
    Node* getIn2();
    Node* getOut();

    // pure virtual function to be inherited from the child classes, the classes that represent each logic gate.
    virtual void calculateOutput() = 0;
    virtual ~Gate() = 0;
};


#endif //LOGIC_SIMULATOR_GATE_H
