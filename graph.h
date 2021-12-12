/*********************
Name: Logan Falkenberg
Final Project
Purpose: This file is the header file for the graph class. Includes all needed libraries/modules in order for the main file to function.
**********************/

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <vector>
#include<bits/stdc++.h>
#include "data.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "linkedlist.h"

//template<class dType>
class Graph{

    public:

        Graph();
        ~Graph();

        bool isEmpty();
        int numOfVertices();
        int numOfEdges();
        int getEdgeWeight(std::pair<int,int> *);
        bool addVertex(int, string *);
        bool removeEdge(int, int);
        bool removeVertex(int);
        bool getVertex(int, Data &);
        void initializeVertex(int *, string *, Node *);
        bool newLocation(Node *, Node *);
        void printAdjList();
        bool addEdge(int , int, int);
        void clearGraph();

    private:
        Node *root;
        std::vector<LinkedList> adjList;
        std::vector<int> adjListLabels;
        int count, edgeCount;
};

#endif //GRAPH_GRAPH_H
