//
// Created by Logan on 11/22/2021.
//

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
#include <set>
using std::string;

struct Data {
    int id;
    string data;
};

struct Edge{
    int weight;
    Edge *next, *prev;
};

struct Node {
    Data data;
    Node *next, *prev;
    Edge edge;
};






#endif //GRAPH_DATA_H
