//
// Created by Logan on 11/22/2021.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
class Graph{

public:

    Graph();
    ~Graph();

    bool isEmpty();
    int numbOfVertices();
    int numOfEdges();
    bool hasEdge();
    bool addVertex();
    bool addEdge();
    bool removeEdge();
    bool removeVertex();
    bool getVertex();

private:





};

#endif //GRAPH_GRAPH_H
