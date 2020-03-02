#include <iostream>

#include "Simulator.h"

using namespace std;

int main() {
    Simulator s;
    string fN = R"(C:/Users/pi/Desktop/test.cir)";
    s.load(fN);
    return 0;
}
