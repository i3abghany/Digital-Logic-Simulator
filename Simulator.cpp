// Main Simulator class .cpp file

#include "Simulator.h"

#include <fstream>

#include "AndGate.h"
#include "OrGate.h"
#include "XORGate.h"
#include "NANDGate.h"

using namespace std;

// Default constructor of the class Simulator.
Simulator::Simulator() {
    NA = vector<Node*>();
    GA = vector<Gate*>();
}

// Returning the number of gates.
int Simulator::getGS() {
    return GA.size();
}

// Returning the number of nodes.
int Simulator::getNS() {
    return NA.size();
}


/*
 * @param s name of the node to check if present in the vector or not.
 *
 * if the node called s is present in the vector, return a pointer to the node, else return null which indicates NO.
 */
Node* Simulator::findNode(string s) {
    for (int i = 0; i < NA.size(); ++i) {
        if(NA[i]->getName() == s)
            return NA[i];
    }
    return NULL;
}

/*
 * @param s the name of a new node to add to the vector of nodes with the default constructor.
 */

Node* Simulator::addNode(string s) {
    NA.emplace_back(new Node(s));
    return NA[NA.size()-1];
}

/*
 * @param s the name of the node to be added to the vector if not present, if it's already
 * in the vector, return a pointer to the node that exists.
 */

Node* Simulator::findOrAdd(string s) {
    Node* n = findNode(s);
    if(n != NULL)
        return n;
    return addNode(s);
}

/*
 * @param type the type of the gate which could be AND, OR, XOR or NAND.
 *
 */

Gate* Simulator::addGate(string type) {
    Gate* x = NULL;
    if(type == "AND")
        x = new AndGate();
    else if(type == "OR")
        x = new OrGate();
    else if(type == "XOR")
        x = new XORGate();
    else if(type == "NAND")
        x = new NANDGate();
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

/*
 * @param fileName the actual place and name of the file that the simulator should read from.
 * The command SET is used to define the value of a specific node called s.
 * The command SIM is used to calculate all the outputs of the gates in the entire simulator, using the function simulate()
 * The command OUT, if followed by a node name, it will output the value of the node.
 * The command Out, if followed by "ALL", without the quotes, will print all the nodes and their values.
 */

void Simulator::load(string fileName) {
    ifstream f1;
    f1.open(fileName);
    while(!f1.eof()) {
        string s;
        f1 >> s;
        if(s == "SET") {
            string n; short v;
            f1 >> n >> v;
            findOrAdd(n)->setValue(v);
        } else if(s == "OUT") {
            string k;
            f1 >> k;
            if(k == "ALL")
                printAllNodes();
            else findOrAdd(k)->printNode();
        }
        else if(s == "SIM") simulate();
        else {
            Gate* g = addGate(s);
            string n1, n2, n3;
            f1 >> n1 >> n2 >> n3;
            // adding to the gate g new nodes called n1, n2 as inputs and n3 as output node.
            g->setIn1(findOrAdd(n1));
            g->setIn2(findOrAdd(n2));
            g->setOut(findOrAdd(n3));
        }
    }
    f1.close();
}

 // The destructor of the simulator class, deleting all the node pointers and gate pointers to release the memory reserved
 // by the simulator.

Simulator::~Simulator() {
    for (int i = 0; i < NA.size(); ++i)
        delete NA[i];
    for (int j = 0; j < GA.size(); ++j)
        delete GA[j];
}