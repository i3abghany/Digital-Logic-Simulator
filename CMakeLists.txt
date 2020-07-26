cmake_minimum_required(VERSION 3.10)
project(Logic_Simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
add_executable(Logic_Simulator src/main.cpp src/Node.cpp include/Node.h src/Gate.cpp include/Gate.h src/AndGate.cpp include/AndGate.h src/OrGate.cpp include/OrGate.h src/Simulator.cpp include/Simulator.h src/XORGate.cpp include/XORGate.h src/NANDGate.cpp include/NANDGate.h src/NORGate.cpp include/NORGate.h src/XNORGate.cpp include/XNORGate.h src/NOTGate.cpp include/NOTGate.h src/GateFactory.cpp include/GateFactory.h)
