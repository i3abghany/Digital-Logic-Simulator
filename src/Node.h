#include <string>

using namespace std;

#ifndef LOGIC_SIMULATOR_NODE_H
#define LOGIC_SIMULATOR_NODE_H


class Node {
protected:
    string name;
    short value;

public:
    void setName(string);
    string getName();

    void setValue(short);
    short getValue();


    Node();
    Node(string);
    Node(string, short);

    void printNode();

};


#endif //LOGIC_SIMULATOR_NODE_H
