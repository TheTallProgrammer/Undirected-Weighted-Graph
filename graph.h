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

    //    Graph(std::vector<Node> *, std::vector<std::pair<Node, Node>> *, std::vector<Vertex> *);
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
        void initializeVertex(int *, string *, Vertex *);
        //    bool addEdge(dType start, dType end, int edgeWeight);
        //    bool removeEdge(dType start, dType end);
        //    bool getEdgeWeight(dType start, dType end);

    private:

        int count;



};

#endif //GRAPH_GRAPH_H
