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

    // create your graph object here
    Graph graph;
    // ================== ================== CHECKING GRAPH STATUS ================== ==================

    // show it is empty by calling getCount and printTable
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
    std::cout << "is graph empty? ";
    if(graph.isEmpty()){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    // ================== ================== STARTING MAIN TEST LOOP ================== ==================

    randIndex = (rand() % testdatasize);
    // Main testing for loop
    std::cout << "\n================== ================== INITIATING LOOP TESTING ================== ==================" << std::endl;
    for(int i =0; i < 300; i++){
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
                addedEdge = graph.addEdge(ids[rNumIndex], ids[rNumIndex2], (rand()%99)+1);
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
                std::cout << "ID SIZE: " << testdatasize << ", rNumIndex: " << rNumIndex << ", rNumIndex2: " << rNumIndex2 << ", adjList size: " << graph.numOfVertices() << std::endl;
                std::cout << "Attempting to remove edge between vertex " << ids[rNumIndex] << " and vertex " << ids[rNumIndex2] << ". Successful? " << std::endl;
                didRemove = graph.removeEdge(ids[rNumIndex], ids[rNumIndex2]);
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
                std::cout << "\nFinding specific vertex of id " << ids[rNumIndex] << " Successful? ";
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