//
// Created by Max on 19/04/2020.
//

#include "Graph.h"


Graph::Graph(const string &directory, const string &instance) {
   this->generateWithFile(directory, instance);
}


unsigned int Graph::getDistance(unsigned int i, unsigned int j) const {
    // Do "i-1" and "j-1" because for instance the vertices 1 is located at position 0 in the matrix
    return this->matrix[i-1][j-1];
}


unsigned int Graph::getNbVertices() const {
    return this->nbVertices;
}


void Graph::splitString(const string& str, char delimiter, vector<unsigned int>& node) {
    stringstream ss(str);
    string temp;

    // Parse a line to a vector by the delimiter
    while ( getline(ss, temp, delimiter) ) {
        node.push_back(stoi(temp));
    }
}


void Graph::generateWithFile(const string &directory, const string& instance) {
    // Concatenate to get the filename with extension (and optional directory)
    string fileName = directory + instance + ".in";

    // Open the file
    ifstream file(fileName);

    if(file) {
        // Debug
        cout << "In generateWithFile() : Successfully open the file " << fileName << endl;

        string line;

        // Get the number of vertices in the first line
        getline(file, line);
        this->nbVertices = stoi(line);

        while( getline(file, line) ) {
            vector<unsigned int> node;

            // Parse each line by the delimiter and it to the node vector
            this->splitString(line, ' ', node);

            // Add the new line to the matrix
            this->matrix.push_back(node);
        }

        file.close();

    } else {
        // Debug
        cout << "In generateWithFile() : Unable to open the file " << fileName << endl;
        exit(EXIT_FAILURE);
    }
}


void Graph::printNbVertices() {
    cout << "Number of vertices : " << this->nbVertices << endl;
}


void Graph::printMatrix() {
    for (auto & i : this->matrix) {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}


unsigned int Graph::getValueOfMatrix(unsigned int x, unsigned int y) const{
    return this->matrix[x][y];
}