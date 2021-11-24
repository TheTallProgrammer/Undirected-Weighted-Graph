#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
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

    // -----------End of creating test data-----------

    bool didInsert = false;
    bool didRemove = false;
    std::string data;
    int rNumCase = 0;
    int rNumIndex = 0;
    int id = 0;
    int iterationCount = 1;

    // create your hash graph object here
    Graph graph;

    // show it is empty by calling getCount and printTable
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // try and put ALL the test data into the graph and show what happens
    // Testing insert/remove methods
    std::cout << "\n**TESTING INSERT/REMOVE**" << std::endl;
    for(int i =0; i < testdatasize; i++){
        didInsert = graph.addVertex(ids[i], &strs[i]);
        std::cout << "insert of id " << ids[i] << " successful? ";
        if(didInsert == true){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    std::string dataString = "";

    for(int i =0; i < testdatasize; i++){
        didRemove = graph.removeVertex(ids[i]);
        std::cout << "removal of id " << ids[i] << " successful? ";
        if(didRemove == true){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }

        std::pair<int,int> vertexIds = std::make_pair(ids[i], ids[i]);
        didRemove = graph.removeEdge(&vertexIds);
        std::cout << "removal of id " << ids[i] << " successful? ";
        if(didRemove == true){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
    std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;

    // Main testing for loop
    std::cout << "\n**TESTING ALL METHODS**" << std::endl;
    for(int i =0; i < 1000; i++){
        // Picks random index
        rNumIndex = (rand() % testdatasize);
        rNumCase = (rand()%3)+1;
        int location = 0;
        std::pair<int,int> vertexIds;
        std::cout<<"\nIteration: " << iterationCount << std::endl;

        switch(rNumCase){
            case 1:
                std::cout << "insert of id " << ids[rNumIndex] << " successful? ";
                didInsert = graph.addVertex(ids[rNumIndex], &strs[rNumIndex]);
                if(didInsert == true){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
                std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
                break;

            case 2:
                didRemove = graph.removeVertex(ids[rNumIndex]);
                std::cout << "removal of id " << ids[rNumIndex] << " successful? ";
                if(didRemove == true){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }

                vertexIds = std::make_pair(ids[rNumIndex], ids[rNumIndex]);
                didRemove = graph.removeEdge(&vertexIds);
                std::cout << "removal of id " << ids[rNumIndex] << " successful? ";
                if(didRemove == true){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nCurrent amount of vertices: " << graph.numOfVertices() << std::endl;
                std::cout << "Current amount of edges: " << graph.numOfEdges() << std::endl;
                break;

            case 3:
                id = ids[rNumIndex];
                graph.getVertex(id);
                graph.getEdgeWeight();

                std::cout << "data from id: " << id << ": " << data << std::endl;
                break;
        }
        iterationCount++;
    }

    std::cout << "\n***************\nTESTS CONCLUDED\n***************" << std::endl;


    return 0;
}