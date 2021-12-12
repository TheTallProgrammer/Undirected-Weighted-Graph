/*********************
Name: Logan Falkenberg
Final Project
Purpose: This is the main file for the graph class. It contains all methods for the full functionality of a graph.
**********************/

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
} // End of constructor

Graph::~Graph(){
    clearGraph();
} // End of destructor

bool Graph::isEmpty(){
    bool isEmpty = false;
    if (count == 0)
        isEmpty = true;
    return isEmpty;
} // End of isEmpty

int Graph::numOfVertices(){return count;} // End of getNumVertices

int Graph::numOfEdges(){return edgeCount;} // End of numOfEdges

void Graph::printAdjList(){
    for(int i = 0; i < adjListLabels.size(); i++){
        std::cout << "\t|Label ID: " << adjListLabels[i] << "| Vertex: " ;
        if(adjList.size() > 0){
            adjList[i].printList();
        }
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
    bool addedEdgeOne = false, addedEdgeTwo = false, hasVOne = false, hasVTwo = false, addedEdges = false;
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
        if(vertexOneID != vertexTwoID) { // Make sure that the two vertices aren't duplicate ids
            Node *vertexOne;
            Node *vertexTwo;
            vertexOne = adjList[position].getNode(vertexOneID);
            vertexTwo = adjList[positionTwo].getNode(vertexTwoID);
            addedEdgeOne = adjList[position].addNode(vertexTwo->data.id, &vertexTwo->data.data, weight);
            addedEdgeTwo = adjList[positionTwo].addNode(vertexOne->data.id, &vertexOne->data.data, weight);
            if (addedEdgeOne && addedEdgeTwo) {
                edgeCount++;
                addedEdges = true;
            }
        }
    }
    return addedEdges;
} // End of addEdge

bool Graph::removeEdge(int vertexOneID, int vertexTwoID){
    bool removedEdgeOne = false, removedEdgeTwo = false, hasVOne = false, hasVTwo = false, removedEdges = false;
    int position = 0, positionTwo = 0;
    for(int i = 0; i < adjListLabels.size(); i++){
        if(adjListLabels[i] == vertexOneID){
            hasVOne = true;
            position = i;
        }
        if(adjListLabels[i] == vertexTwoID) {
            positionTwo = i;
            hasVTwo = true;
        }
    }
    if(hasVOne && hasVTwo){
        if(vertexOneID != vertexTwoID) { // Make sure that the two vertices aren't duplicate ids
            removedEdgeOne = adjList[position].deleteNode(vertexTwoID);
            removedEdgeTwo = adjList[positionTwo].deleteNode(vertexOneID);
            if (removedEdgeTwo && removedEdgeOne) {
                if (edgeCount > 0) {
                    edgeCount--;
                }
                removedEdges = true;
            }
        }
    }
    return removedEdges;
} // End of removeEdge

bool Graph::removeVertex(int id){
    bool removedVertex = false, containsID = false;
    int idPos = 0, edges = 0;
    for(int i = 0; i < adjListLabels.size(); i++){
        if(adjListLabels[i] == id){
            idPos = i;
            containsID = true;
        }
    }
    if(containsID){
        edges = adjList[idPos].getCount()-1;
        edgeCount = edgeCount - edges;
        adjList[idPos].clearList();
        for(int i =0 ; i < adjList.size(); i++){
            removedVertex = adjList[i].deleteNode(id);
            if(removedVertex){
                edgeCount--;
            }
        }
        // Erase the specific vertex that the label is at
        adjListLabels.erase(adjListLabels.begin() + idPos);
        adjList.erase(adjList.begin()+idPos);
        count--;
        if(edgeCount < 0){
            edgeCount = 0;
        }
        removedVertex = true;
    }
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

void Graph::clearGraph() {
    for(int i = 0; i < adjList.size();i++){
        adjList[i].clearList();
    }
    adjList.clear();
    adjListLabels.clear();;
    count = 0, edgeCount = 0;
} // End of clearGraph

void Graph::initializeVertex(int *id, string *data, Node *newVertex){
    newVertex->data.id = *id;
    newVertex->data.data = *data;
    newVertex->edge.weight = 0;
    newVertex->next = nullptr;
    newVertex->prev = nullptr;
} // End of initializeVertex


