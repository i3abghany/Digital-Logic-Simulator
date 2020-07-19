#include "GateFactory.h"

Gate *GateFactory::CreateGate(const std::string &type) {
    Gate *x = nullptr;
    if (type == "AND")
        x = new AndGate();
    else if (type == "OR")
        x = new OrGate();
    else if (type == "XOR")
        x = new XORGate();
    else if (type == "NAND")
        x = new NANDGate();
    else if (type == "XNOR")
        x = new XNORGate();
    else if (type == "NOR")
        x = new NORGate();
    else if (type == "NOT")
        x = new NOTGate();
    else {
        throw std::invalid_argument("Unknown command " + type + ".\n");
    }
    return x;
}
