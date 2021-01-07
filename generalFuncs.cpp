//
// Created by Max on 22/04/2020.
//

#include "generalFuncs.h"

using namespace std;


// Calculate and return the distance of the path (Sum of the distance between each vertex)
unsigned int distanceCalculation(const Graph& graph, const vector<unsigned int>& path) {
    unsigned int distance = 0;

    for(unsigned int i = 1; i < path.size(); i++) {
        distance += graph.getDistance(path[i-1], path[i]);
    }

    return distance;
}


void printPath(const string& message, const vector<unsigned int>& path) {
    cout << message;
    std::copy(path.begin(), path.end(),ostream_iterator<unsigned int>(std::cout, " "));
    cout << endl;
}


void fillPathInOrder(const Graph& graph, vector<unsigned int>& path) {
    // Init path for the first distance calculation like this : {1, 2, 3, 4, 5...}
    for(unsigned int i = 1; i <= graph.getNbVertices(); i++) {
        path.push_back(i);
    }

    // Add finishing vertex (same as starting)
    path.push_back(1);
}


void exportInFile(const string& directory, const string& method, const string& instance, const Graph& graph, const vector<unsigned int>& path) {
    // Concatenate to get the filename with extension
    string filePath = directory + instance + "_" + method + ".out";

    // Open output file
    ofstream file(filePath);

    if(file) {
        // Debug
        cout << "In exportInFile() : Successfully open the file " << filePath << endl;

        // Output of the shortest path without last value (return to first vector)
        ostream_iterator<unsigned int> output_iterator(file, " ");
        copy(path.begin(), path.end()-1, output_iterator);

        // Output of the shortest distance
        file << endl << distanceCalculation(graph, path);

        // Close file
        file.close();

    } else {
        // Debug
        cout << "In exportInFile() : Unable to open the file " << filePath << endl;
    }
}


void createRandomGraph(unsigned int nbVertices, unsigned int minDist, unsigned int maxDist, const string& instanceName) {
    // Concatenate to get the filename with extension
    string filePath = "../Instances/random" + instanceName + ".in";

    // Open output file
    ofstream file(filePath);

    if(file) {
        // Debug output
        cout << "In exportInFile() : Successfully open the file " << filePath << endl;

        random_device rd;   // Obtain a random number from hardware
        mt19937 eng(rd());  // Seed the generator
        uniform_int_distribution<> distribution(minDist, maxDist);  // Define the range

        vector<vector<unsigned int>> matrix;

        for(unsigned int vertex1 = 0; vertex1 < nbVertices; vertex1++) {
            // Create new line for the matrix
            vector<unsigned int> line;

            // Add it to the matrix
            line.resize(nbVertices);
            matrix.push_back(line);

            for(unsigned int vertex2 = 0; vertex2 <= vertex1; vertex2++) {

                // If the 2 vertex numbers are different, put a random number in matrix
                // Else, leaves "0" added by default (For instance : for (1,1); (2,2)...
                if(vertex1 != vertex2)  {
                    unsigned int value = distribution(eng);

                    // Add value at 2 cases because we have a symmetric matrix (and an undirected graph)
                    matrix[vertex1][vertex2] = value;
                    matrix[vertex2][vertex1] = value;
                }
            }
        }

        // Output number of instance(s) in the file
        file << nbVertices << endl;

        ostream_iterator<unsigned int> output_iterator(file, " ");

        // Output the matrix line by line in the file
        for(auto& line : matrix) {
            copy(line.begin(), line.end(), output_iterator);
            file << endl;
        }

        // Close file
        file.close();

    } else {
        // Debug
        cout << "In exportInFile() : Unable to open the file " << filePath << endl;
    }
}