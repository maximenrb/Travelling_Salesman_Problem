//
// Created by pinea on 24/04/2020.
//


#include "grasp.h"


void initializeWeight(const Graph& graph, vector<pair<unsigned int,unsigned int>>& weight) {
    unsigned int index, weightValue = 0;

    for (int vertex1 = 1; vertex1 <= graph.getNbVertices(); vertex1++) {
        index = vertex1;

        for (int vertex2 = 1; vertex2 <= graph.getNbVertices(); vertex2++) {
            weightValue += graph.getDistance(vertex1, vertex2);
        }

        weight.emplace_back(index, weightValue);
        weightValue = 0;
    }
}


void adaptGreedyFunction(const Graph& graph, vector<pair<unsigned int,unsigned int>>& weight, unsigned int& solution) {
    for (int j = 0; j < weight.size(); j++) {
        if (weight[j].first == solution){
            weight.erase(weight.begin()+j);
        }
    }

    for (pair<unsigned int, unsigned int>& i : weight) {
        i.second -= graph.getDistance(i.first, solution);
    }
}


vector<unsigned int> makeRCL(const Graph& graph, const float& alpha, const vector<pair<unsigned int,unsigned int>>& weight) {
    vector<unsigned int> RCL;
    unsigned int maxWeight = 0;

    for (pair<unsigned int, unsigned int> i : weight) {
        if (maxWeight < i.second){
            maxWeight = i.second;
        }
    }

    float actualCost, cost = alpha * (float)maxWeight;

    for (auto & i : weight) {

        actualCost = (float)(i.second);

        if( actualCost >= cost ) {
            RCL.push_back(i.first);
        }
    }

    return RCL;
}


void constructGreedyRandomizedSolution(const Graph& graph, vector<unsigned int>& path, const float& alpha) {
    vector<pair<unsigned int,unsigned int>> weight;
    unsigned int solution;

    path.clear();
    initializeWeight(graph, weight);

    random_device rd;   // Obtain a random number from hardware
    mt19937 eng(rd());  // Seed the generator

    while( path.size() < graph.getNbVertices() ) {
        vector<unsigned int> RCL = makeRCL(graph, alpha, weight);

        uniform_int_distribution<> distribution(0, RCL.size()-1);   // Define the range
        solution = RCL[ distribution(eng) ];    // Choose a random solution in RCL

        path.push_back(solution);

        adaptGreedyFunction(graph, weight, solution);
    }
}


void grasp(const Graph& graph, unsigned int& bestDistance, vector<unsigned int>& bestPath, const float& alpha, const unsigned int& maxIteration) {
    vector<unsigned int> path;
    unsigned int iteration = 0, distance = 0;

    while (iteration < maxIteration) {
        constructGreedyRandomizedSolution(graph, path, alpha);

        path.push_back(path[0]);

        localSearch(graph, path, numeric_limits<unsigned int>::max());
        distance = distanceCalculation(graph, path);

        if(distance < bestDistance) {
            bestDistance = distance;
            bestPath = path;
        }

        iteration++;
    }
}