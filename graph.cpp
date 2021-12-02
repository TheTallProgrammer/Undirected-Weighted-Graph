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
    count = 0, edgeCount = 0, rowInt = 0, colInt = 0;
    adjMatSize = count*count;
    const int initialSize = 0;
    vertices = {};
    edges = {};
    edgeWeight = {};
    adjMatrix = {initialSize, std::vector<Node>(initialSize)};
    srand (time(NULL));
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

int Graph::getEdgeWeight(std::pair<int,int> *vertexIds) {
    int edgeW = 0;
    for(int i =0; i < edges.size();i++){
        if(vertexIds->first == edges[i].first && vertexIds->second == edges[i].second){
            edgeW = edgeWeight[i];
        }
    }
    return edgeW;

} // End of getEdgeWeight

void Graph::printEdgesAndWeights(){
    std::cout << "Vertices: ";
    for(int i = 0; i < vertices.size();i++){
        std::cout << "{" << vertices[i].data.id << "},";
    }
    std::cout << std::endl;
    std::cout << "Edges: ";
    for(int i =0; i < edges.size();i++){
        std::cout << "{" << edges[i].first << "," << edges[i].second << "},";
    }
    std::cout << "\nEdge's Weight: ";
    for(int i =0; i < edgeWeight.size();i++){
        std::cout << "{" << edgeWeight[i] << "},";
    }
    std::cout << std::endl;
} // End of printEdgesAndWeights

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
    vertices.push_back(*newVertex);
    addEdge(&temp->data.id, &newVertex->data.id);
//    addToMatrix(newVertex);
    return true;
} // End of newLocation

bool Graph::addEdge(int *vertexOne, int *vertexTwo){
    bool addedEdge = false;
    std::pair<int, int> edge;
    edge.first = *vertexOne;
    edge.second = *vertexTwo;
    edges.push_back(edge);
    edgeWeight.push_back(genEdgeWeight());
    edgeCount++;
    return addedEdge;
} // End of addEdge

int Graph::genEdgeWeight() {
    return (rand() % 40) ;
} // End of genEdgeWeight

void Graph::addToMatrix(Node *newVertex){
    for(int i = 0; i < adjMatSize; i++){
        for(int j = 0; j < adjMatSize; j++){

        }
    }
} // End of add to list

void Graph::printMatrix(){
    std::cout << "count: " << count << std::endl;
    for(int i =0; i < count-1; i++){
        std::cout << "loop 1" << std::endl;
        for(int j = 0; j < count-1; j++){
            std::cout << "loop 2" << std::endl;
            if(adjMatrix[i][j].data.id > 0){
                std::cout << adjMatrix[i][j].data.data << " ";
            }
        }
        std::cout << std::endl;
    }
} // End of printMatrix

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


