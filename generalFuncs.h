//
// Created by Max on 22/04/2020.
//

#ifndef GRAPH_PROJECT_GENERALFUNCS_H
#define GRAPH_PROJECT_GENERALFUNCS_H

#include "Graph.h"

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <random>       // std::default_random_engine


unsigned int distanceCalculation(const Graph& graph, const vector<unsigned int>& path);
void printPath(const string& message, const vector<unsigned int>& path);
void fillPathInOrder(const Graph& graph, vector<unsigned int>& path);
void exportInFile(const string& directory, const string& method, const string& instance, const Graph& graph, const vector<unsigned int>& path);
void createRandomGraph(unsigned int nbVertices, unsigned int minDist, unsigned int maxDist, const string& instanceName);

#endif //GRAPH_PROJECT_GENERALFUNCS_H
