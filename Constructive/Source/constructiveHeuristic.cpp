//
// Created by Max on 22/04/2020.
//

#include "constructiveHeuristic.h"


void constructiveHeuristic(const Graph& graph, vector<unsigned int>& path) {
    vector<char> visitedNodes;
    unsigned int closestVertex = 0, closestDistance, actualDistance;

    // Set the size of the vertex (equal to the number of vertices)
    visitedNodes.resize(graph.getNbVertices(), false);

    // Add starting vertex in the path, and mark it as visited
    path.push_back(1);
    visitedNodes[0] = true;

    // Repeat until all vertices has been visited
    while(path.size() < graph.getNbVertices()) {
        closestDistance = numeric_limits<unsigned int>::max();

        for(int vertex = 1; vertex <= graph.getNbVertices(); vertex++) {

            // Do calculation only if vertex is not visited
            if(!visitedNodes[vertex - 1]) {
                actualDistance = graph.getDistance(path.back(), vertex);

                // Check if distance is shortest than the closest vertex in this while iteration
                if(actualDistance < closestDistance) {
                    closestDistance = actualDistance;
                    closestVertex = vertex;
                }
            }
        }

        // Add the closest vertex to the next one in the path, and mark it as visited
        path.push_back(closestVertex);
        visitedNodes[closestVertex - 1] = true;
    }

    // Add finishing vertex in the path (same as starting)
    path.push_back(1);
}