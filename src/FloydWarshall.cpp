#include "FloydWarshall.h"

FloydWarshall::FloydWarshall() {
    /* do nothing */
}

FloydWarshall::FloydWarshall(unsigned size, const vector<vector<double>>& graph) {
    size_ = size;

    // check if already finish doing for `next_`
    string save = "../data/FloydWarshall.save";
    next_ = fileToIntVector(save, size_);
    if (!next_.empty()) return;

    // if not, it is O(n^3)
    initialise(graph);
}

vector<int> FloydWarshall::getShortestPath(int source, int destination) {
    vector<int> path;
    // If there's no path between, return empty
    if (next_[source][destination] == -1)
        return path;
 
    // Start to find the path
    path.push_back(source);
    while (source != destination) {
        source = next_[source][destination];
        path.push_back(source);
    }

    return path;
}

// helper function

/**
 * @brief Initialize the required data
 *          (Mark `-1` if edge not exist)
 * 
 * @param graph Initial graph
 * @param dist data need to initialize
 */
void FloydWarshall::initialise(const vector<vector<double>>& graph) {
    vector<vector<double>> dist = graph;
    next_ = vector<vector<int>>(size_, vector<int>(size_));

    // Initialize the values in `next_`
    for (unsigned i = 0; i < size_; i++) {
        for (unsigned j = 0; j < size_; j++) {
            // check if edge not exist
            if (dist[i][j] == INF)
                next_[i][j] = -1;
            else
                next_[i][j] = j;
        }
    }
    cout << "initialising FloydWarshall" << endl;

    // similar as pseudocode from wikipedia
    for (unsigned k = 0; k < size_; k++) {
        cout << "(" << k << "/" << size_ << ")" << endl;
        for (unsigned i = 0; i < size_; i++) {
            for (unsigned j = 0; j < size_; j++) {
                // check if edge not exist
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                // if find one is smaller
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_[i][j] = next_[i][k];
                }
            }
        }
    }
    // after calc, save it, so maybe can used in next time
    vectorToFile("../data/FloydWarshall.save", next_);
}
