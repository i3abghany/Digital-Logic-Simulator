#ifndef LOGIC_SIMULATOR_SIMULATOR_H
#define LOGIC_SIMULATOR_SIMULATOR_H

#include "Gate.h"
#include<vector>

using namespace std;

class Simulator {
protected:
    vector<Node*> NA;
    vector<Gate*> GA;
    
public:
    Simulator();
    ~Simulator();

    int getGS();
    int getNS();

    Node* findNode(string);
    Node* addNode(string);
    Node* findOrAdd(string);

    Gate* addGate(string);

    void simulate();
    void load(string);

    void printAllNodes();
};


#endif //LOGIC_SIMULATOR_SIMULATOR_H
