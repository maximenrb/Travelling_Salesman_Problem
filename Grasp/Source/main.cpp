//
// Created by Max on 05/05/2020.
//

#include "grasp.h"

#include <chrono>

void execGRASP(const Graph& graph,const string& instance){
    unsigned int bestDistance = numeric_limits<unsigned int>::max();
    vector<unsigned int> bestPath;

    float alpha;
    unsigned int maxIteration;

    // Ask alpha number
    cout << "Enter rate number between 0 and 1 (ex: alpha = 0.8) : ";
    cin >> alpha;

    // Verify if input is a number, else ask again
    while(!cin || alpha < 0 || alpha > 1) {
        cout << "> Not a number OR not between 0 and 1 !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter rate number between 0 and 1 (ex: alpha = 0.8) : ";
        cin >> alpha;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Ask max number of iteration
    cout << "Enter max iterations : ";
    cin >> maxIteration;

    // Verify if input is a number, else ask again
    while(!cin) {
        cout << "> Not a number !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter max iterations : ";
        cin >> maxIteration;
    }

    auto start = chrono::high_resolution_clock::now();

    grasp(graph, bestDistance, bestPath, alpha, maxIteration);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = stop - start;

    cout << "Execution time : " << (chrono::duration <double, milli> (duration).count())/1000 << " s" << endl;
    printPath("Grasp path is : ", bestPath);
    cout << "Grasp distance is : " << distanceCalculation(graph, bestPath) << endl << endl;

    exportInFile("../Instances/", "grasp", instance, graph, bestPath);
}


int main() {
    string instance;

    // Ask instance name at the user
    cout << "Enter instance name (without extension) : ";
    cin >> instance;

    // Create graph instance and fill it with the instance
    Graph graph("../Instances/", instance);
    graph.printNbVertices();

    execGRASP(graph, instance);

    return 0;
}