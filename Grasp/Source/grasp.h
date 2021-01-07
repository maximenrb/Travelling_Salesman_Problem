//
// Created by pinea on 24/04/2020.
//

#ifndef GRAPH_PROJECT_GRASP_H
#define GRAPH_PROJECT_GRASP_H

#include "../../Graph.h"
#include "../../generalFuncs.h"

#include "../../Local_search/Source/localSearchHeuristic.h"

#include <random>
#include <map>


void initializeWeight(const Graph& graph, vector<pair<unsigned int,unsigned int>>& weight);

void adaptGreedyFunction(const Graph& graph, vector<pair<unsigned int,unsigned int>>& weight, unsigned int& solution);
vector<unsigned int> makeRCL(const Graph& graph, const float& alpha, const vector<pair<unsigned int,unsigned int>>& weight);
void constructGreedyRandomizedSolution(const Graph& graph, vector<unsigned int>& path, const float& alpha);
void grasp(const Graph& graph, unsigned int& bestDistance, vector<unsigned int>& bestPath, const float& alpha, const unsigned int& maxIteration);

#endif //GRAPH_PROJECT_GRASP_H
