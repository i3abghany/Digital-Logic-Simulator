#ifndef LOGIC_SIMULATOR_SIMULATOR_H
#define LOGIC_SIMULATOR_SIMULATOR_H

#include "Gate.h"
#include<vector>

using namespace std;

class Simulator {
protected:
    std::vector<Node*> NA;
    std::vector<Gate*> GA;
    std::vector<Node*> inputNodes;

public:
    Simulator();
    ~Simulator();

    int getGS();
    int getNS();

    Node* findNode(const std::string&);
    Node* addNode(const std::string&);
    Node* findOrAdd(const std::string&);
    Node* addInputNode(const std::string&);
    Gate* addGate(const std::string&);

    void simulate();
    void load(const std::string&);

    void TruthTable();
    void printAllNodesForTruthTable();
    void printAllNodes();
    Node* findInInputNodes(const std::string &);
};


#endif //LOGIC_SIMULATOR_SIMULATOR_H
