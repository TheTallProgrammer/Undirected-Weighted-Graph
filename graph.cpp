//
// Created by Logan on 11/22/2021.
//

#include "graph.h"

// Creates a vector array for Node vertices (v) and another vector with each cell
// containing two Nodes that will represent one edge (e). It contains a third vector of type Vertex
// Which stores the vertex, and the adjacents to that vertex in a set
// Essentially, one vector for vertices and another vector for edges, and a third vector for vertexes
Graph::Graph(std::vector<Node> *vctr, std::vector<std::pair<Node, Node>> *e, std::vector<Vertex> *vrtx){
    std::vector<Node> *vctr_ = vctr;
    std::vector<std::pair<Node, Node>> *e_ = e;
    std::vector<Vertex> *vrtx_ = vrtx;
} // End of constructor

Graph::~Graph(){

} // End od destructor

bool Graph::isEmpty(){

} // End of isEmpty

int Graph::getNumVerticies(){

} // End of getNumVerticies

int Graph::numOfEdges(){

} // End of numOfEdges

bool Graph::getEdgeWeight() {

} // End of getEdgeWeight

bool Graph::addVertex(){

} // End of addVertex

bool Graph::addEdge(){

} // End of addEdge

bool Graph::removeEdge(){

} // End of removeEdge

bool Graph::removeVertex(){

} // End of removeVertex

bool Graph::getVertex(){

} // End of getVertex

void Graph::depthFirstSearch() {

} // End of depthFirstSearch

void Graph::breadthFirstSearch() {

} // End of breadthFirstSearch
