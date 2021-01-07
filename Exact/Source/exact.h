//
// Created by Max on 22/04/2020.
//

#ifndef GRAPH_PROJECT_EXACT_H
#define GRAPH_PROJECT_EXACT_H

#include "../../Graph.h"

#include <set>
#include <limits>

void backtrackRecursive(const Graph& graph, vector<unsigned int>& bestPath, unsigned int& bestDistance, unsigned int previousDistance, set<unsigned int> verticesSet, unsigned int previousVertex, vector<unsigned int> tempPath);
void backtrackSolving(const Graph& graph, vector<unsigned int>& path);


#endif //GRAPH_PROJECT_EXACT_H
