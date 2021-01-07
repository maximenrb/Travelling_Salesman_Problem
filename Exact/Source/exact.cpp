//
// Created by Max on 22/04/2020.
//

#include "exact.h"


void backtrackRecursive(const Graph& graph, vector<unsigned int>& bestPath, unsigned int& bestDistance, unsigned int previousDistance, set<unsigned int> verticesSet, unsigned int previousVertex, vector<unsigned int> tempPath) {

    // Add the starting vertex in the path and remove it in the set
    tempPath.push_back(previousVertex);
    verticesSet.erase(previousVertex);

    // Check if all vertices has been visited
    if(verticesSet.empty()) {

        // Add the distance between the last vertex in the path and the finishing vertex (same as starting)
        previousDistance += graph.getDistance(previousVertex, 1);

        // Check if this distance is smaller than the best distance
        if(previousDistance < bestDistance) {
            bestDistance = previousDistance;
            bestPath = tempPath;

            // Add the finishing vertex in the path (same as starting)
            bestPath.push_back(1);
        }

    } else {
        // For each visited which is not visited
        for(auto& vertex : verticesSet) {

            // Add the distance between the last vertex in the path and the new chosen one
            unsigned int actualDistance = previousDistance + graph.getDistance(previousVertex, vertex);

            if(actualDistance >= bestDistance) {
                // If this distance is higher than the best one (best distance for a total path), return to the previous function call
                return;

            } else {
                // Else, do a recursive call and indicated the chosen vertex ("vertex") has visited
                backtrackRecursive(graph, bestPath, bestDistance, actualDistance, verticesSet, vertex, tempPath);
            }
        }
    }
}


void backtrackSolving(const Graph& graph, vector<unsigned int>& path) {
    vector<unsigned int> tempPath;
    set<unsigned int> set;  // This set is used to know visited vertices

    unsigned int bestDistance = numeric_limits<unsigned int>::max();

    // Add all vertices (in the graph) to the set
    for(unsigned int i = 1; i <= graph.getNbVertices(); i++) {
        set.insert(i);
    }

    // Initial call of the recursive function
    backtrackRecursive(graph, path, bestDistance, 0, set, 1, tempPath);
}