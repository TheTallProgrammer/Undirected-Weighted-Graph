//
// Created by Logan on 11/22/2021.
//

#include "graph.h"

// Creates a vector array for Node vertices (v) and another vector with each cell
// containing two Nodes that will represent one edge (e). It contains a third vector of type Vertex
// Which stores the vertex, and the adjacents to that vertex in a set
// Essentially, one vector for vertices and another vector for edges, and a third vector for vertexes
// Keeps to the formula g = (v,e)
//Graph::Graph(std::vector<Node> *vrtcy, std::vector<std::pair<Node, Node>> *e){
//    std::vector<Node> *vrtcy_ = vrtcy;
//    std::vector<std::pair<Node, Node>> *e_ = e;
//    count = 0;
//} // End of constructor

Graph::Graph(){
    count = 0;
    std::vector<Node> *vertices;
    std::vector<std::pair<Node, Node>> *edges;
} // End of constructor

Graph::~Graph(){

} // End od destructor

bool Graph::isEmpty(){return count;} // End of isEmpty

int Graph::numOfVertices(){
    int numOfVert = 0;
    return numOfVert;

} // End of getNumVertices

int Graph::numOfEdges(){
    int numOfEd = 0;
    return numOfEd;

} // End of numOfEdges

bool Graph::getEdgeWeight(std::pair<int,int> *vertexIds) {
    bool edgeExists = false;
    return edgeExists;

} // End of getEdgeWeight

bool Graph::addVertex(int id, string *data){
    bool addedVertex = false;
    // Checking to see if the data is valid
    if(id > 0 && data->length() > 0){
        // Allocate new data and assign it the id and the data that are passed into the method
        Vertex *newVertex = new Vertex();
        initializeVertex(&id, data, newVertex);
    }
    return addedVertex;

} // End of addVertex

bool Graph::addEdge(std::pair<int,int> *vertexIds){
    bool addedEdge = false;
    return addedEdge;

} // End of addEdge

bool Graph::removeEdge(std::pair<int,int> *vertexIds){
    bool removedEdge = false;
    return removedEdge;

} // End of removeEdge

bool Graph::removeVertex(int id){
    bool removedVertex = false;
    return removedVertex;

} // End of removeVertex

bool Graph::getVertex(int id){
    bool gotVertex = false;
    return gotVertex;

} // End of getVertex

void Graph::depthFirstSearch() {

} // End of depthFirstSearch

void Graph::breadthFirstSearch() {

} // End of breadthFirstSearch

void Graph::initializeVertex(int *id, string *data, Vertex *newVertex){
    newVertex->vertex->data.id = *id;
    newVertex->vertex->data.data = *data;
    newVertex->vertex->left = nullptr;
    newVertex->vertex->right = nullptr;
} // End of initializeVertex
