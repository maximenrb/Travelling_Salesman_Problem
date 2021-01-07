//
// Created by Max on 22/04/2020.
//

#ifndef GRAPH_PROJECT_LOCALSEARCHHEURISTIC_H
#define GRAPH_PROJECT_LOCALSEARCHHEURISTIC_H

#include "../../Graph.h"

#include <algorithm>

bool permuteEdges(const Graph& graph, vector<unsigned int>& path);
void localSearch(const Graph& graph, vector<unsigned int>& path, const unsigned int& maxIteration);

#endif //GRAPH_PROJECT_LOCALSEARCHHEURISTIC_H
