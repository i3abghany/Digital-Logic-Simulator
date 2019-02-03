cmake_minimum_required(VERSION 3.12)
project(Logic_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Logic_Simulator main.cpp Node.cpp Node.h Gate.cpp Gate.h AndGate.cpp AndGate.h OrGate.cpp OrGate.h Simulator.cpp Simulator.h XORGate.cpp XORGate.h NANDGate.cpp NANDGate.h NORGate.cpp NORGate.h XNORGate.cpp XNORGate.h)
