#include <iostream>

#include "../include/Node.h"

Node::Node() {
    name = "";
    value = 0;
}

Node::Node(string n) {
    name = std::move(n);
    value = 0;
}

Node::Node(string n, short v) {
    name = std::move(n), value = v;
}

void Node::printNode() {
    std::cout << name << " " << value << std::endl;
}

void Node::setName(string n) {
    name = std::move(n);
}

string Node::getName() {
    return name;
}

short Node::getValue() {
    return value;
}

void Node::setValue(short v) {
    value = v;
}