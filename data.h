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

struct Node {
    Data data;
    Node *left, *right;
};

struct Vertex{
    Node *vertex;
};

template <typename T>
struct Edge{
    T weight;
    Vertex *start, *end;
};


#endif //GRAPH_DATA_H
