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
    adjList = {};
    adjMatrix = {0, std::vector<Node>(0)};
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

    return edgeW;
} // End of getEdgeWeight

void Graph::printEdgesAndWeights(){
    std::cout << "Vertices: " << std::endl;
    for(int i = 0; i < adjList.size(); i++){
        std::cout << "Vertex: " << i << ":";
        adjList[i].printList();
    }

    std::cout << std::endl;
    std::cout << "Edges: ";

    std::cout << "\nEdge's Weight: ";
    
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
            LinkedList List;
            List.addNode(newVertex->data.id, &newVertex->data.data, newVertex->edge.weight);
            adjList.push_back(List);
            addedVertex = true;
        } else {
            addedVertex = newLocation(root, newVertex);
        }
    }
    return addedVertex;
} // End of addVertex

bool Graph::newLocation(Node *root, Node *newVertex) {
    int randInsert = (rand() % 2) + 1;
    if(randInsert == 1){ // Making the new node adjacent to a previous node
        randInsert = (rand() % adjList.size()) + 1;
        adjList[randInsert].addNode(newVertex->data.id, &newVertex->data.data, newVertex->edge.weight);
        newVertex->edge.weight = genEdgeWeight();
        edgeCount++;
    } else { // Just adding to another list
        count++;
        LinkedList List;
        List.addNode(newVertex->data.id, &newVertex->data.data, newVertex->edge.weight);
        adjList.push_back(List);
    }
    return true;
} // End of newLocation

int Graph::genEdgeWeight() {return (rand() % 40);} // End of genEdgeWeight

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
    Data data;
    for(int i =0; i < count; i++){
        adjList[i].getNode(id, &data);
            if(data.id == id) {
                temp.data.id = data.id;
                temp.data.data = data.data;
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
    newVertex->edge.weight = 0;
    newVertex->next = nullptr;
    newVertex->prev = nullptr;
} // End of initializeVertex


