#include "Dijkstra.h"



Dijkstra::Dijkstra() {
    /* do nothing */
}

Dijkstra::Dijkstra(unsigned size, const vector<vector<double>>& graph) {
    size_ = size;

    // check if already finish doing for `next_`
    string save = "../data/Djikstras.save";
    //next_ = fileToIntVector(save, size_);
    //if (!next_.empty()) return;

    
    initialise(graph);
}

vector<int> Dijkstra::getShortestPath(int source, int destination) {

    //double for distance, int for destination
    typedef std::pair<double, int> DistPair;
    std::priority_queue<DistPair> pq;
    //push source
    pq.push(std::make_pair(0, source));
    std::vector<bool> visited;
    //initial visited map
    for (unsigned i = 0; i < size_; i++) {
        visited[i] = false;
    }

    while (pq.top().second != destination) {
        int curr = pq.top().second;
        pq.pop();
        std::vector<int> adj;
        for(unsigned i = 0; i < size_; i++){
            if(dist[curr][i]!= INF && curr != i){
                adj.push_back(i);
            }
        }

        for(unsigned i = 0; i< adj.size(); i++){
            //ignore visited vertices
            if(visited[adj[i]]){
                continue;
            }
            else{
                int adjV = adj[i];
                
                if (dist[source][adjV] > dist[source][curr] + dist[curr][adjV]) {
                    dist[source][adjV] = dist[source][curr] + dist[curr][adjV];
                    prev_[adjV] = curr;
                    pq.push(std::make_pair(dist[source][adjV],adjV));
                    
                }
            }
        }
        visited[curr] = true;
    }
    std::vector<int> path;
    //if there is no path, return empty;
    if(prev_[destination] == -1){
        return path;
    }
    // Start to find the path
    path.push_back(destination);

    while (destination != source) {
        destination = prev_[destination];
        path.insert(path.begin(),destination);
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
 * @param prev_ record previous vertices
 */
void Dijkstra::initialise(const vector<vector<double>>& graph) {
    dist = graph;
    //initial prev
    for (unsigned i = 0; i < size_; i++){
        prev_.push_back(-1);
    }
    /*for (unsigned i = 0; i < size_; i++) {
        for (unsigned j = 0; j < size_; j++) {
            // check if edge not exist
            if (dist[i][j] == INF)
                next_[i][j] = -1;
            else
                next_[i][j] = j;
        }
    }*/
    cout << "initialising Dijkstra" << endl;

    
    /*for (unsigned k = 0; k < size_; k++) {
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
    }*/
    // after calc, save it, so maybe can used in next time
    
    //vectorToFile("../data/Dijkstra.save", next_);
}
