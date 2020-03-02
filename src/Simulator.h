#ifndef LOGIC_SIMULATOR_SIMULATOR_H
#define LOGIC_SIMULATOR_SIMULATOR_H

#include "Gate.h"
#include<vector>


class Simulator {
protected:
    std::vector<Node*> NA;
    std::vector<Gate*> GA;
    std::vector<Node*> inputNodes;
    std::vector<Node*> outputNodes;

public:
    Simulator();
    ~Simulator();

    Node* findNode(const std::string&);
    Node* addNode(const std::string&);
    Node* findOrAdd(const std::string&);
    Node* addInputNode(const std::string&);
    Node* addOutputNode(const std::string&);
    Gate* addGate(const std::string&);

    void simulate();
    void load(const std::string&);

    void TruthTable();
    void printAllNodesForTruthTable();
    void printAllNodes();
};


#endif //LOGIC_SIMULATOR_SIMULATOR_H
