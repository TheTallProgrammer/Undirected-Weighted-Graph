/*********************
Name: Logan Falkenberg
Final Project
Purpose: This is the header file for the all used structs in the graph class.
**********************/

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
};

struct Node {
    Data data;
    Node *next, *prev;
    Edge edge;
};

#endif //GRAPH_DATA_H
