#ifndef LOGIC_SIMULATOR_SIMULATOR_H
#define LOGIC_SIMULATOR_SIMULATOR_H

#include "Gate.h"
#include<vector>

using namespace std;

class Simulator {
protected:
    vector<Node*> NA;
    vector<Gate*> GA;
    vector<Node*> inputNodes;
    
public:
    Simulator();
    ~Simulator();

    int getGS();
    int getNS();

    Node* findNode(string);
    Node* addNode(string);
    Node* findOrAdd(string);
    Node* addInputNode(string);
    Gate* addGate(string);

    void simulate();
    void load(string);

    void TruthTable();
    void printAllNodesForTruthTable();
    void printAllNodes();
    Node* findInInputNodes(string);
};


#endif //LOGIC_SIMULATOR_SIMULATOR_H
