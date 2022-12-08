#include "Dijkstra.h"



Dijkstra::Dijkstra() {
    /* do nothing */
}

Dijkstra::Dijkstra(unsigned size, const vector<vector<double>>& graph, int source) {
    size_ = size;
    source_ = source;
    graph_ = graph;
    initialise(graph,source_);
    
    ShortestPath(source_);
    
}
void Dijkstra::setSource(int source){
    source_ = source;
}
void Dijkstra::ShortestPath(int source){
    dist_[source] = 0;
    //double for distance, int for destination
    typedef std::pair<double, int> DistPair;
    std::priority_queue<DistPair,std::vector<DistPair>,std::greater<DistPair>> pq;
    //push source
    pq.push(std::make_pair(0, source));
    
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        std::vector<std::pair<int, double>>::iterator it;
        //search adjecent airport
        for(it = adjAirport[curr].begin();it != adjAirport[curr].end(); ++it){
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
vector<int> Dijkstra::getShortestPath(int source, int destination){
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
 * @param source index of source airpot
 */
void Dijkstra::initialise(const vector<vector<double>>& graph,int source) {
    graph_ = graph;
    //initial prev
    for (unsigned i = 0; i < size_; i++){
        dist_.push_back(INF);
        prev_.push_back(-1);
    }
    //initial adjAirport
     for (unsigned i = 0; i < graph_.size(); i++) {
        vector<std::pair<int, double>> temp;
        for(unsigned j = 0; j < graph_[i].size(); j++){
            if(graph_[i][j] != INF){
                double cost = graph_[i][j];
                temp.push_back(std::make_pair(j,cost));  
            }
        }
        
            adjAirport.push_back(temp);
       
    }
    dist_[source] = 0;
    cout << "initialising Dijkstra" << endl;

}
