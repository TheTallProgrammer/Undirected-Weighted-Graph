//
// Created by Logan on 11/22/2021.
//

#include "graph.h"

// Creates a vector array for Node vertices (v) and another vector with each cell
// containing two Nodes that will represent one edge (e)
// Which stores the vertex, and the adjacents to that vertex in a set
// Essentially, one vector for vertices and another vector for edges
// Keeps to the formula g = (v,e)
Graph::Graph(){
    root = nullptr;
    count = 0;
    adjMatSize = count*count;
    const int initialSize = 0;
    vertices = {};
    edges = {};
    adjMatrix = {initialSize, std::vector<Node>(initialSize)};
} // End of constructor

Graph::~Graph(){

} // End od destructor

bool Graph::isEmpty(){
    bool isEmpty = false;
    if (count == 0)
        isEmpty = true;
    return isEmpty;
} // End of isEmpty

int Graph::numOfVertices(){return count;} // End of getNumVertices

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
    if(id > 0 && data->length() > 0){
        Node *newVertex = new Node();
        initializeVertex(&id, data, newVertex);
        if(isEmpty()){
            root = newVertex;
            count++;
            adjMatSize = count*count;
            adjMatrix.resize(adjMatSize);
            vertices.push_back(*newVertex);
            addedVertex = true;
        } else {
            addedVertex = newLocation(root, newVertex);
        }
    }
    return addedVertex;
} // End of addVertex

void Graph::addToList(Node *newVertex){


} // End of add to list

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

bool Graph::getVertex(int id, Node &temp){
    bool gotVertex = false;
    for(int i =0; i < count; i++){
        if(vertices[i].data.id == id){
            std::cout << vertices[i].data.id << std::endl;
            temp.data.id = vertices[i].data.id;
            temp.data.data = vertices[i].data.data;
            gotVertex = true;
        }
    }
    return gotVertex;

} // End of getVertex

void Graph::depthFirstSearch() {

} // End of depthFirstSearch

void Graph::breadthFirstSearch() {

} // End of breadthFirstSearch

void Graph::initializeVertex(int *id, string *data, Node *newVertex){
    newVertex->data.id = *id;
    newVertex->data.data = *data;
    newVertex->left = nullptr;
    newVertex->right = nullptr;
} // End of initializeVertex

bool Graph::newLocation(Node *root, Node *newVertex) {
    bool addedLocation = false;
    std::cout << "picking a new location for the new vertex" << std::endl;
    return addedLocation;
} // End of newLocation
