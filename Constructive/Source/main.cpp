//
// Created by Max on 05/05/2020.
//

#include "../../generalFuncs.h"
#include "constructiveHeuristic.h"

#include <chrono>

void execConstructive(const Graph& graph, const string& instance) {
    vector<unsigned int> path;

    // Start chronometer in order to calculate execution time
    auto start = chrono::high_resolution_clock::now();

    constructiveHeuristic(graph, path);

    // Stop chronometer and calculate duration
    auto stop = chrono::high_resolution_clock::now();
    auto duration = stop - start;

    // Print output and execution time of the algorithm
    cout << "Execution time : " << (chrono::duration <double, milli> (duration).count())/1000 << " s" << endl;
    printPath("Constructive path is : ", path);
    cout << "Constructive distance is : " << distanceCalculation(graph, path) << endl << endl;

    exportInFile("../Instances/", "constructive", instance, graph, path);
}


int main() {
    string instance;

    // Ask instance name at the user
    cout << "Enter instance name (without extension) : ";
    cin >> instance;

    // Create graph instance and fill it with the instance
    Graph graph("../Instances/", instance);
    graph.printNbVertices();

    execConstructive(graph, instance);

    return 0;
}