//
// Created by Max on 19/04/2020.
//

#ifndef GRAPH_PROJECT_GRAPH_H
#define GRAPH_PROJECT_GRAPH_H

#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Graph {
private:
    vector<vector<unsigned int>> matrix;
    unsigned int nbVertices = 0;


public: // Constructors
    Graph() = default;
    Graph(const string& directory, const string& instance);


public: // Getters
    unsigned int getDistance(unsigned int i, unsigned int j) const;
    unsigned int getNbVertices() const;


public: // Functions
    void splitString(const string& str, char delimiter, vector<unsigned int>& node);

    /*!
     *  \brief Fill the matrix with a .in file. Don't put the extension in the instance string
     *  \param directory : Put "" if the file is in the main directory
     */
    void generateWithFile(const string& directory, const string& instance);

    void printNbVertices();
    void printMatrix();


    unsigned int getValueOfMatrix(unsigned int x, unsigned int y) const;
};


#endif //GRAPH_PROJECT_GRAPH_H
