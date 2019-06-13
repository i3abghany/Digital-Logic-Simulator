// Main Simulator class .cpp file

#include "Simulator.h"

#include <fstream>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <iomanip>

#include "AndGate.h"
#include "OrGate.h"
#include "XORGate.h"
#include "NANDGate.h"
#include "XNORGate.h"
#include "NORGate.h"

// Default constructor of the class Simulator.
Simulator::Simulator() {
    NA = std::vector<Node*>();
    GA = std::vector<Gate*>();
    inputNodes = std::vector<Node*>();
}

int Simulator::getGS() {
    return GA.size();
}

int Simulator::getNS() {
    return NA.size();
}

// searches for a node with the name s.
Node* Simulator::findNode(const std::string &s) {
    for (int i = 0; i < NA.size(); ++i) {
        if(NA[i]->getName() == s)
            return NA[i];
    }
    return nullptr;
}

// Adds a node to the nodes array.
Node* Simulator::addNode(const std::string &s) {
    NA.emplace_back(new Node(s));
    return NA[NA.size()-1];
}

// Search for a node with name s, if not existed, make a new node called s.
Node* Simulator::findOrAdd(const std::string &s) {
    Node* n = findNode(s);
    if(n != nullptr)
        return n;
    return addNode(s);
}

// Creates a gate of the according type.
Gate* Simulator::addGate(const std::string &type) {
    Gate* x = nullptr;
    if(type == "AND")
        x = new AndGate();
    else if(type == "OR")
        x = new OrGate();
    else if(type == "XOR")
        x = new XORGate();
    else if(type == "NAND")
        x = new NANDGate();
    else if(type == "XNOR")
        x = new XNORGate();
    else if(type == "NOR")
        x = new NORGate();
    GA.emplace_back(x);
    return GA[GA.size() - 1];
}



// calculating the output of every gate in the simulator.
void Simulator::simulate() {
    for (int i = 0; i < GA.size(); ++i)
        GA[i]->calculateOutput();
}

void Simulator::printAllNodes() {
    for (int i = 0; i < NA.size(); ++i)
        NA[i]->printNode();
}

/* Used to load the file that contains the components of the digital system.
 * The command SET is used to define the value of a specific node called s.
 * The command SIM is used to calculate all the outputs of the gates in the entire simulator, using the function simulate()
 *The command TRUTH is used to generate and print the truth table of the system
 * The command TSET is used to set a node as an input node in the truth table.
*/
void Simulator::load(const std::string &fileName) {
    std::ifstream f1;
    f1.open(fileName);
    if(!f1.good()) {
        throw std::runtime_error("Could not open the file.\n");
    }
    while(!f1.eof()) {
        std::string s;
        f1 >> s;
        if(s == "SET") {
            std::string n; short v;
            f1 >> n >> v;
            findOrAdd(n)->setValue(v);
        } else if(s == "TSET") {
            std::string n;
            f1 >> n;
            findOrAdd(n)->setValue(0);
            addInputNode(n);
        }
        else if(s == "OUT") {
            std::string out_option;
            f1 >> out_option;
            if(out_option == "ALL")
                printAllNodes();
            else findOrAdd(out_option)->printNode();
        }
        else if(s == "SIM") simulate();
        else if(s == "TRUTH") TruthTable();
        else {
            Gate* g = addGate(s);
            std::string n1, n2, n3;
            f1 >> n1 >> n2 >> n3;
            // adding to the gate g new nodes called n1, n2 as inputs and n3 as output node.
            g->setIn1(findOrAdd(n1));
            g->setIn2(findOrAdd(n2));
            g->setOut(findOrAdd(n3));
        }
    }
    f1.close();
}

Node* Simulator::addInputNode(const std::string &s) {
    inputNodes.emplace_back(new Node(s));
    return inputNodes[inputNodes.size() - 1];
}

void Simulator::printAllNodesForTruthTable() {
    std::cout << std::endl;

    for(int i = 0; i < inputNodes.size(); i++) {
        std::cout << std::setw(5) << findOrAdd(inputNodes[i]->getName())->getValue();
    }

    for(int i = 0; i < NA.size(); i++) {
        if (findInInputNodes(NA[i]->getName()) == nullptr) {
            std::cout << std::setw(5) << NA[i]->getValue();
        }
    }
}

Node* Simulator::findInInputNodes(const std::string &s) {
    for(int i = 0; i < inputNodes.size(); i++)
        if(inputNodes[i]->getName() == s)
            return inputNodes[i];
    return nullptr;
}

void Simulator::TruthTable() {
    // The header of the truth table, inputs and outputs.
    unsigned long long NumberOfInputNodes = inputNodes.size();
    int NumberOfPossibilities = (int)pow(2, NumberOfInputNodes);
    for(int i = 0; i < inputNodes.size(); i++)
        std::cout << std::setw(5) << inputNodes[i]->getName();
    for(int i = 0; i < NA.size(); i++) {
        if(findInInputNodes(NA[i]->getName()) == nullptr)
            std::cout << std::setw(5) << NA[i]->getName();
    }

    // using a bitset to generate all the combinations of the truth table.
    const size_t sz = 8;
    for(int i = 0; i < NumberOfPossibilities; i++) {
        std::string currentPossibility = std::bitset<sz>(i).to_string();

        // deleting the leading zeros.
        currentPossibility = currentPossibility.substr(currentPossibility.size() - NumberOfInputNodes);

        for(int j = 0; j < NumberOfInputNodes; j++) {
            findOrAdd(inputNodes[j]->getName())->setValue(currentPossibility[j] - '0');
        }

        simulate();
        printAllNodesForTruthTable();
    }
}

Simulator::~Simulator() {
    for (auto &n : NA) {
        delete n;
    }
    for (auto &g : GA) {
        delete g;
    }
}
