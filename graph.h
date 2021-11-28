//
// Created by Logan on 11/22/2021.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <vector>
#include<bits/stdc++.h>
#include "data.h"

//template<class dType>
class Graph{

    public:

        Graph();
        ~Graph();

        bool isEmpty();
        int numOfVertices();
        int numOfEdges();
        bool getEdgeWeight(std::pair<int,int> *);
        bool addVertex(int, string *);
        bool addEdge(std::pair<int,int> *);
        bool removeEdge(std::pair<int,int> *);
        bool removeVertex(int);
        bool getVertex(int);
        void depthFirstSearch();
        void breadthFirstSearch();
        void initializeVertex(int *, string *, Node *);
        bool newLocation(Node *, Node *);


    private:

        Node *root;
        // Creating a 2d vector array for the adjMatrix
        std::vector<std::vector<Node>> adjMatrix;
        int count, adjMatSize;
};

#endif //GRAPH_GRAPH_H
