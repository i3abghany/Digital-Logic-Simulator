#include <iostream>

#include "Node.h"

Node::Node() {
    name = "";
    value = 0;
}
Node::Node(string n) {
    name = n;
    value = 0;
}

Node::Node(string n, short v) {
    name = n, value = v;
}

void Node::printNode() {
    std::cout << name << " " << value << std::endl;
}

void Node::setName(string n) {
    name = n;
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