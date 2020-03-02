#include <iostream>

#include "Simulator.h"

int main() {
    Simulator s;
    std::string fN = R"(C:/Users/pi/Desktop/test.txt)";
    s.load(fN);
    return 0;
}
