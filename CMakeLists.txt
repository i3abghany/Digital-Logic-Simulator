cmake_minimum_required(VERSION 3.12)
project(Logic_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Logic_Simulator src/main.cpp src/Node.cpp src/Node.h src/Gate.cpp src/Gate.h src/AndGate.cpp src/AndGate.h src/OrGate.cpp src/OrGate.h src/Simulator.cpp src/Simulator.h src/XORGate.cpp src/XORGate.h src/NANDGate.cpp src/NANDGate.h src/NORGate.cpp src/NORGate.h src/XNORGate.cpp src/XNORGate.h src/NOTGate.cpp src/NOTGate.h)
