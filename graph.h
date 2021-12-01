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
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
        bool addEdge(int *, int *);
        bool removeEdge(std::pair<int,int> *);
        bool removeVertex(int);
        bool getVertex(int, Node &);
        void depthFirstSearch();
        void breadthFirstSearch();
        void initializeVertex(int *, string *, Node *);
        bool newLocation(Node *, Node *);
        void addToMatrix(Node *);
        void printMatrix();
        int genEdgeWeight();


    private:

        Node *root;
        // Creating a 2d vector array for the adjMatrix
        std::vector<std::vector<Node>> adjMatrix;
        std::vector<Node> vertices;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> edgeWeight;
        int count, adjMatSize, edgeCount, rowInt, colInt;
};

#endif //GRAPH_GRAPH_H
