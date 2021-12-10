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
    adjList = {}, adjListLabels = {};
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

void Graph::printAdjList(){
    for(int i = 0; i < adjList.size(); i++){
        std::cout << "\t|Label ID: " << adjListLabels[i] << "| Vertex: " ;
        adjList[i].printList();
        std::cout << std::endl;
    }
} // End of printEdgesAndWeights

bool Graph::addVertex(int id, string *data){
    bool addedVertex = false;
    if(id > 0 && data->length() > 0){
        Node *newVertex = new Node();
        initializeVertex(&id, data, newVertex);
        if(isEmpty()){
            root = newVertex;
            count++;
            LinkedList List;
            addedVertex = List.addNode(newVertex->data.id, &newVertex->data.data, newVertex->edge.weight);
            // adjListLabels is a parallel array vector that will determine where a new list goes in the adjList
            adjListLabels.push_back(newVertex->data.id);
            adjList.push_back(List);
        } else {
            addedVertex = newLocation(root, newVertex);
        }
    }
    return addedVertex;
} // End of addVertex

bool Graph::newLocation(Node *root, Node *newVertex) {
    bool containsID = false;
    bool didAdd = false;
    for(int i =0; i < adjListLabels.size(); i++) {
        if(adjListLabels[i] == newVertex->data.id) {
            containsID = true;
        }
    }
    if(!containsID){
        LinkedList List;
        didAdd = List.addNode(newVertex->data.id, &newVertex->data.data, newVertex->edge.weight);
        adjListLabels.push_back(newVertex->data.id);
        adjList.push_back(List);
        count++;
        containsID = true;
    }
    return didAdd;
} // End of newLocation

bool Graph::addEdge(int vertexOneID, int vertexTwoID, int weight){
    bool addedEdge = false, hasVOne = false, hasVTwo = false;
    int position = 0, positionTwo = 0;
    for(int i = 0; i < adjListLabels.size(); i++){
        if(adjListLabels[i] == vertexOneID){
            hasVOne = true;
            position = i;
        }
        if(adjListLabels[i] == vertexTwoID){
            positionTwo = i;
            hasVTwo = true;
        }
    }
    // This means that an edge can be created because the two vertices exist
    if(hasVOne && hasVTwo){
        Node *vertexTwo;
        vertexTwo = adjList[positionTwo].getNode(vertexTwoID);
        adjList[position].addNode(vertexTwo->data.id, &vertexTwo->data.data, weight);
        addedEdge = true;
        edgeCount++;
    }
    return addedEdge;
} // End of addEdge

int Graph::genEdgeWeight() {return (rand() % 40) + 1;} // End of genEdgeWeight

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

bool Graph::getVertex(int id, Data &data){
    Node *tempNode;
    bool gotVertex = false;
    for(int i =0; i < count; i++){
        if(adjListLabels[i] == id){
            tempNode = adjList[i].getNode(id);
            if(tempNode->data.id == id) {
                data.id = tempNode->data.id;
                data.data = tempNode->data.data;
                gotVertex = true;
            }
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
    newVertex->edge.weight = genEdgeWeight();
    newVertex->next = nullptr;
    newVertex->prev = nullptr;
} // End of initializeVertex


