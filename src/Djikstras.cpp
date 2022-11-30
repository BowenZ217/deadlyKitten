#include "Djikstras.h"



Djikstras::Djikstras() {
    /* do nothing */
}

Djikstras::Djikstras(unsigned size, const vector<vector<double>>& graph, int source) {
    size_ = size;
    initialise(graph, source);
}

void Djikstras::setSource(int source) {
    prev_.resize(size_, -1);
    dist_.resize(size_, INF);
    source_ = source;

    dist_[source] = 0;

    /// @todo check if works !!!
    /*
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
        unsigned curr = pq.top().second;
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
     */
}

vector<int> Djikstras::getShortestPath(int destination) {
    std::vector<int> path;
    

    // if there is no path, return empty;
    if (prev_[destination] == -1)
        return path;
    
    // Start to find the path
    /** @todo 
    path.push_back(source_);
    int curr = source_;
    while (destination != source_) {
        destination = prev_[destination];
        path.insert(path.begin(),destination);
    }
     */

    return path;
}

// helper function

/**
 * @brief Initialize the required data
 *          (Mark `-1` if edge not exist)
 * 
 * @param graph Initial graph
 * @param source index of source airpot
 */
void Djikstras::initialise(const vector<vector<double>>& graph, int source) {
    graph_ = graph;

    setSource(source);
}
