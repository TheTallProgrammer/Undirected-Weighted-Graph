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
    string information;
};

struct Node {
    Data data;
    Node *left, *right;
};

struct Vertex{
    // Constructor for the struct
    // Uses set to keep the order of the adjacents to the vertex
    Vertex(Node v, std::set<Node> *a){
        Node v_ = v;
        std::set<Node> a_ = *a;
    }
};

struct Edge{
    Data data;
    std::string weight;
    Edge *start, *end;
};


#endif //GRAPH_DATA_H
