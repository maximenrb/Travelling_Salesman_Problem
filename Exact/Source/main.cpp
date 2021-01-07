//
// Created by Max on 05/05/2020.
//

#include "../../generalFuncs.h"
#include "exact.h"   // Exact algorithms

#include <chrono>       // std::chrono::system_clock


void execBackTracking(const Graph& graph, const string& instance) {
    vector<unsigned int> path;

    // Start chronometer in order to calculate execution time
    auto start = chrono::high_resolution_clock::now();

    backtrackSolving(graph, path);

    // Stop chronometer and calculate duration
    auto stop = chrono::high_resolution_clock::now();
    auto duration = stop - start;

    // Print output and execution time of the algorithm
    cout << "Execution time : " << (chrono::duration <double, milli> (duration).count())/1000 << " s" << endl;
    printPath("Back-tracking path is : ", path);
    cout << "Back-tracking distance is : " << distanceCalculation(graph, path) << endl << endl;

    exportInFile("../Instances/", "exact", instance, graph, path);
}


int main() {
    string instance;

    // Ask instance name at the user
    cout << "Enter instance name (without extension) : ";
    cin >> instance;

    // Create graph instance and fill it with the instance
    Graph graph("../Instances/", instance);
    graph.printNbVertices();

    execBackTracking(graph, instance);

    return 0;
}