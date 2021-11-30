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
    count = 0, edgeCount = 0;
    adjMatSize = count*count;
    const int initialSize = 0;
    vertices = {};
    edges = {};
    adjMatrix = {initialSize, std::vector<Node>(initialSize)};
} // End of constructor

Graph::~Graph(){

} // End of destructor

bool Graph::isEmpty(){
    bool isEmpty = false;
    if (count == 0)
        isEmpty = true;
    return isEmpty;
} // End of isEmpty

int Graph::numOfVertices(){return count;} // End of getNumVertices

int Graph::numOfEdges(){return edgeCount;} // End of numOfEdges

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

bool Graph::newLocation(Node *root, Node *newVertex) {
    Node *temp = root;
    while((root!= nullptr) && temp->next!= nullptr){
        temp = temp->next;
    }
    count++;
    temp->next = newVertex;
    newVertex->prev = temp;
    newVertex->next = nullptr;
    addToMatrix(newVertex);
    return true;
} // End of newLocation

void Graph::addToMatrix(Node *newVertex){
    for(int i = 0; i < adjMatSize; i++){
        for(int j = 0; j < adjMatSize; j++){
            if(i==count-1 && j!=count-1){
                std::cout << "if" << std::endl;
                adjMatrix[i][j] = *newVertex;
                edgeCount++;
            }
            else if(j==count-1&&i!=count-1){
                std::cout << "else if" << std::endl;
                adjMatrix[i][j] = *newVertex;
            }
            else{
                // Filling in empty spots with blank nodes
                Node *temp = new Node();
                temp->data.data = "N/A";
                temp->data.id = i;
                std::cout << "else" << std::endl;
                adjMatrix[i][j] = *temp;
            }
        }
    }
} // End of add to list

void Graph::printMatrix(){
    std::cout << "count: " << count << std::endl;
    for(int i =0; i < count; i++){
        std::cout << "loop 1" << std::endl;
        for(int j = 0; j < count; j++){
            std::cout << "loop 2" << std::endl;
            if(adjMatrix[i][j].data.id > 0){
                std::cout << "| " << adjMatrix[i][j].data.data << " | ";
            }
        }
        std::cout << std::endl;
    }
} // End of printMatrix

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
    newVertex->next = nullptr;
    newVertex->prev = nullptr;
} // End of initializeVertex


