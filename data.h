//
// Created by Logan on 11/22/2021.
//

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct Node {
    Data data;
    Node *left, *right;
};


#endif //GRAPH_DATA_H
