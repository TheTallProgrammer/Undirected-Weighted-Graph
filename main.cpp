#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    const int testdatasize = 10;
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }

    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    srand(time(NULL));

    bool didInsert;
    bool didRemove = false;
    std::string data;
    int rNumCase = 0;
    int rNumIndex = 0, rNumIndex2 = 0;
    int id = 0;
    int iterationCount = 1;
    Data tempData;
    bool gotVertex = false;
    int randIndex;
    bool addedEdge = false;

    // create your hash graph object here
    Graph graph;
    // ================== ================== START OF INITIAL TESTS ================== ==================

    std::cout << "\n================== ================== START OF INITIAL TESTS ================== ==================" << std::endl;

    // show it is empty by calling getCount and printTable
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
    std::cout << "is graph empty? ";
    if(graph.isEmpty()){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    // ================== ================== ADDING VERTEX ================== ==================

    std::cout << "\n**TESTING INSERT*" << std::endl;
    for(int i =0; i < testdatasize; i++){
        didInsert = graph.addVertex(ids[i], &strs[i]);
        std::cout << "insert of vertex with id " << ids[i] << " successful? ";
        if(didInsert){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== FINDING VERTEX DATA ================== ==================

    std::cout << "\nFinding specific vertex. Successful? ";
    gotVertex = graph.getVertex(ids[0], tempData);
    if(gotVertex){
        std::cout << "Yes. Got vertex: " << tempData.id << " : " << tempData.data << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    // ================== ================== ADDING EDGE ================== ==================

    std::cout << "\n**TESTING ADDING EDGE**" << std::endl;
    for(int i =0; i < testdatasize; i++){
        randIndex = (rand() % testdatasize-1);
        std::cout << "Attempting to add edge between vertex " << ids[i] << " and vertex " << ids[randIndex] << ". Successful? ";
        addedEdge = graph.addEdge(ids[i], ids[randIndex], (rand()%50)+1);
        if(addedEdge){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== CLEARING GRAPH ================== ==================

    std::cout << "\n**Clearing the graph**" << std::endl;
    graph.clearGraph();

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== ADDING VERTEX ================== ==================

    std::cout << "\n**TESTING INSERT**" << std::endl;
    for(int i =0; i < 3; i++){
        didInsert = graph.addVertex(ids[i], &strs[i]);
        std::cout << "insert of vertex with id " << ids[i] << " successful? ";
        if(didInsert){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    // ================== ================== ADDING EDGE ================== ==================

    std::cout << "\n**TESTING ADDING EDGE**" << std::endl;
    for(int i =0; i < testdatasize; i++){
        randIndex = (rand() % testdatasize-1);
        std::cout << "Attempting to add edge between vertex " << ids[i] << " and vertex " << ids[randIndex] << ". Successful? ";
        addedEdge = graph.addEdge(ids[i], ids[i+1], (rand()%50)+1);
        if(addedEdge){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== REMOVING EDGE ================== ==================

    std::cout << "\nRemoving Edge" << std::endl;
    std::cout << "Attempting to remove edge between vertex " << ids[0] << " and vertex " << ids[1] << ". Successful? ";
    didRemove = graph.removeEdge(ids[0], ids[1]);
    if(didRemove){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    std::cout << "Attempting to remove edge between vertex " << ids[1] << " and vertex " << ids[2] << ". Successful? ";
    didRemove = graph.removeEdge(ids[1], ids[2]);
    if(didRemove){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== REMOVING VERTEX ================== ==================

    std::cout << "\nRemoving specific vertex" << std::endl;
    std::cout << "Attempting to remove vertex " << ids[1] << ". Successful? ";
    didRemove = graph.removeVertex(ids[1]);
    if(didRemove){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== CLEARING GRAPH ================== ==================

    std::cout << "\n**Clearing the graph**" << std::endl;
    graph.clearGraph();

    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // ================== ================== END OF INITIAL TESTS ================== ==================




    // ================== ================== STARTING MAIN TEST LOOP ================== ==================

    randIndex = (rand() % testdatasize);
    // Main testing for loop
    std::cout << "\n================== ================== INITIATING LOOP TESTING ================== ==================" << std::endl;
    for(int i =0; i < 100; i++){
        // Picks random index
        rNumIndex = (rand() % testdatasize);
        rNumIndex2 = (rand() % testdatasize);
        rNumCase = (rand()%5)+1;
        std::cout<<"\nIteration: " << iterationCount;

        switch(rNumCase){
            case 1: // ADD VERTEX
                std::cout << " case 1" << std::endl;
                didInsert = graph.addVertex(ids[rNumIndex], &strs[rNumIndex]);
                std::cout << "insert of vertex with id " << ids[rNumIndex] << " successful? ";
                if(didInsert){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nPrinting adjacency list:" << std::endl;
                graph.printAdjList();
                std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
                std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
                std::cout << "\n================== ================== ================== ==================" << std::endl;
                break;

            case 2: // ADD EDGE
                std::cout << " case 2" << std::endl;
                addedEdge = graph.addEdge(ids[rNumIndex], ids[rNumIndex+1], (rand()%99)+1);
                std::cout << "Attempting to add edge between vertex " << ids[rNumIndex] << " and vertex " << ids[rNumIndex2] << ". Successful? ";
                if(addedEdge){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nPrinting adjacency list:" << std::endl;
                graph.printAdjList();
                std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
                std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
                std::cout << "\n================== ================== ================== ==================" << std::endl;
                break;

            case 3: // REMOVE VERTEX
                std::cout << " case 3" << std::endl;
                didRemove = graph.removeVertex(ids[rNumIndex]);
                std::cout << "Attempting to remove vertex " << ids[rNumIndex] << ". Successful? ";
                if(didRemove){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nPrinting adjacency list:" << std::endl;
                graph.printAdjList();
                std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
                std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
                std::cout << "\n================== ================== ================== ==================" << std::endl;
                break;

            case 4: // REMOVE EDGE
                std::cout << " case 4" << std::endl;
                std::cout << "Attempting to remove edge between vertex " << ids[rNumIndex] << " and vertex " << ids[rNumIndex2] << ". Successful? ";
                didRemove = graph.removeEdge(ids[rNumIndex], ids[rNumIndex+1]);
                if(didRemove){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nPrinting adjacency list:" << std::endl;
                graph.printAdjList();
                std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
                std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
                std::cout << "\n================== ================== ================== ==================" << std::endl;
                break;

            case 5: // FIND VERTEX DATA
                std::cout << " case 5" << std::endl;
                gotVertex = graph.getVertex(ids[rNumIndex], tempData);
                if(gotVertex){
                    std::cout << "Yes. Got vertex: " << tempData.id << " : " << tempData.data << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\n================== ================== ================== ==================" << std::endl;
                break;
        }
        iterationCount++;
    }

    std::cout << "\n================== ================== CLEARING GRAPH ================== ==================" << std::endl;
    graph.clearGraph();
    std::cout << "\nPrinting adjacency list:" << std::endl;
    graph.printAdjList();
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    std::cout << "\n================== ================== TESTS CONCLUDED ================== ==================" << std::endl;


    return 0;
}