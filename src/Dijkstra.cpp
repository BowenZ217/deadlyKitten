#include "Dijkstra.h"


Dijkstra::Dijkstra() {
    size_ = -1;
    source_ = -1;
}

Dijkstra::Dijkstra(unsigned size, const vector<vector<double>>& graph, int source) {
    size_ = size;
    source_ = -1;
    graph_ = graph;
    
    setSource(source);
}

void Dijkstra::setSource(int source) {
    // check if need to reset
    if (source_ == source) return;

    source_ = source;
    initialise();

    // double for distance, int for destination
    typedef std::pair<double, int> DistPair;
    std::priority_queue<DistPair, std::vector<DistPair>, std::greater<DistPair>> pq;

    // push source
    pq.push(std::make_pair(0, source_));
    
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        std::vector<std::pair<int, double>>::iterator it;
        // search adjecent airport
        for (it = adjAirport[curr].begin(); it != adjAirport[curr].end(); ++it){
            int next = (*it).first;
            double cost = (*it).second;
            if (dist_[next] > dist_[curr] + cost) {
                dist_[next] = dist_[curr] + cost;
                prev_[next] = curr;
                pq.push(std::make_pair(dist_[next],next));
            }
        }
    }
}

vector<int> Dijkstra::getShortestPath(int destination) {
    std::vector<int> path;
    
    // if there is no path, return empty;
    if (prev_[destination] == -1){
        return path;
    }
    // Start to find the path
    path.push_back(destination);

    while (destination != source_) {
        destination = prev_[destination];
        path.insert(path.begin(), destination);
    }
    
    return path;
}

vector<double> Dijkstra::getShortestDistance() {
    return dist_;
}

//shortest path to given airport
double Dijkstra::getShortestDistance(int destination) {
    return dist_[destination];
}

// helper function
/**
 * @brief Initialize the required data
 *          (Mark `-1` if edge not exist)
 * 
 * @param graph Initial graph
 * @param source index of source airpot
 */
void Dijkstra::initialise() {
    // clean data
    dist_.clear();
    prev_.clear();
    adjAirport.clear();

    // initial
    dist_.resize(size_, INF);
    prev_.resize(size_, -1);

    // initial adjAirport
    for (unsigned i = 0; i < graph_.size(); i++) {
        vector<std::pair<int, double>> temp;
        for (unsigned j = 0; j < graph_[i].size(); j++){
            if (graph_[i][j] != INF){
                double cost = graph_[i][j];
                temp.push_back(std::make_pair(j,cost));  
            }
        }
        adjAirport.push_back(temp);
    }
    dist_[source_] = 0;
}
