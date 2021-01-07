//
// Created by Max on 22/04/2020.
//

#include "localSearchHeuristic.h"


bool permuteEdges(const Graph& graph, vector<unsigned int>& path) {

    // For each vertex in the graph until the penultimate (not included)
    for (unsigned int vertex1 = 0; vertex1 < graph.getNbVertices() - 2; ++vertex1) {

        // For each vertex starting at vertex1 + 2, until the last one (not included)
        for (unsigned int vertex2 = vertex1 + 2; vertex2 < graph.getNbVertices(); ++vertex2) {

            // If distance (A,B) + (C,D) is higher than (A,C) + (B,D)
            if(graph.getDistance(path[vertex1], path[vertex1 + 1]) + graph.getDistance(path[vertex2], path[vertex2 + 1]) >
               graph.getDistance(path[vertex1], path[vertex2]) + graph.getDistance(path[vertex1 + 1], path[vertex2 + 1]) ) {

                // Swap two vertices in the path : B and C
                swap(path[vertex1 + 1], path[vertex2]);

                // Invert the order of the path between the 2 swap vertices
                reverse(path.begin()+(vertex1 + 2), path.begin() + vertex2 );

                // Return true in order to inform that a permutation has been executed
                return true;
            }
        }
    }

    // Return false if there is no possible permutation reducing the path length
    return false;
}


void localSearch(const Graph& graph, vector<unsigned int>& path, const unsigned int& maxIteration) {
    bool permutation = true;
    unsigned int iteration = 0;

    // While a permutation is possible, or we have not reach the max number of iteration
    while(permutation && iteration < maxIteration) {

        // Call the function in order to permute 2 edges
        permutation = permuteEdges(graph, path);

        iteration++;
    }
}