//
// Created by Logan on 11/22/2021.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <vector>
#include "data.h"

//template<class dType>
class Graph{

public:

    Graph(std::vector<Node> &, std::vector<std::pair<Node, Node>> &);
    ~Graph();

    bool isEmpty();
    int getNumVerticies();
    int numOfEdges();
    bool getEdgeWeight();
    bool addVertex();
    bool addEdge();
    bool removeEdge();
    bool removeVertex();
    bool getVertex();
    void depthFirstSearch();
    void breadthFirstSearch();
    //    bool addEdge(dType start, dType end, int edgeWeight);
    //    bool removeEdge(dType start, dType end);
    //    bool getEdgeWeight(dType start, dType end);

private:





};

#endif //GRAPH_GRAPH_H
