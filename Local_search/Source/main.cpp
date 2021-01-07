//
// Created by Max on 05/05/2020.
//

#include "localSearchHeuristic.h"
#include "../../Constructive/Source/constructiveHeuristic.h"
#include "../../generalFuncs.h"

#include <chrono>

void execLocalSearch(const Graph& graph, const string& instance) {
    vector<unsigned int> path;
    unsigned int maxIteration;

    // Ask max number of iteration
    cout << "Enter max iterations (recommend number of vertices) : ";
    cin >> maxIteration;

    // Verify if input is a number, else ask again
    while(!cin) {
        cout << "> Not a number !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter max iterations (recommend number of vertices) : ";
        cin >> maxIteration;
    }

    // Call the constructive heuristic algorithm in order to build the initial path
    constructiveHeuristic(graph, path);

    // Start chronometer in order to calculate execution time
    auto start = chrono::high_resolution_clock::now();

    localSearch(graph, path, maxIteration);

    // Stop chronometer and calculate duration
    auto stop = chrono::high_resolution_clock::now();
    auto duration = stop - start;

    // Print output and execution time of the algorithm
    cout << "Execution time : " << (chrono::duration <double, milli> (duration).count())/1000 << " s" << endl;
    printPath("Local Search path is : ", path);
    cout << "Local Search distance is : " << distanceCalculation(graph, path) << endl << endl;

    exportInFile("../Instances/", "local_search", instance, graph, path);
}


int main() {
    string instance;

    // Ask instance name at the user
    cout << "Enter instance name (without extension) : ";
    cin >> instance;

    // Create graph instance and fill it with the instance
    Graph graph("../Instances/", instance);
    graph.printNbVertices();

    execLocalSearch(graph, instance);

    return 0;
}