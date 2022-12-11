#include "UndirectedFullGraph.h"


UndirectedFullGraph::UndirectedFullGraph(Graph* g, const vector<string>& vertexes) : g_(g) {
    weights_.clear();
    name_to_idx_.clear();
    size_ = 0;
    not_exist_.clear();

    for (const auto& curr_v : vertexes) {
        addVertex(curr_v);
    }
}

UndirectedFullGraph::UndirectedFullGraph(const vector<vector<double>>& g) {
    not_exist_.clear();
    weights_.clear();

    size_ = g.size();
    for (const auto& row : g) {
        vector<Path> temp;
        for (const auto& col : row) {
            temp.push_back(Path(col, not_exist_));
        }
        weights_.push_back(temp);
    }
}

void UndirectedFullGraph::addVertex(const string& name) {
    weights_.push_back(vector<Path>(size_ + 1));
    vector<string> path;
    for (const auto& curr_v : name_to_idx_) {
        path = g_->getShortestPath(curr_v.first, name);
        if (path.empty()) throw std::invalid_argument("vertex can not be connected");
        weights_[curr_v.second].push_back(Path(g_->calcRealDistance(path), path));
        
        path = g_->getShortestPath(name, curr_v.first);
        if (path.empty()) throw std::invalid_argument("vertex can not be connected");
        weights_[size_][curr_v.second] = Path(g_->calcRealDistance(path), path);
    }
    name_to_idx_[name] = size_;
    idx_to_name_[size_] = name;
    size_++;
}

bool UndirectedFullGraph::vertexExist(const string& name) const {
    return name_to_idx_.find(name) != name_to_idx_.end();
}

int UndirectedFullGraph::nameToIndex(const string& name) const {
    auto it = name_to_idx_.find(name);

    if (it == name_to_idx_.end()) return -1;
    return it->second;
}

string UndirectedFullGraph::indexToName(int idx) const {
    auto it = idx_to_name_.find(idx);

    if (it == idx_to_name_.end()) return "";
    return it->second;
}

long double UndirectedFullGraph::getPathWeight(const string& source, const string& destination) const {
    auto source_it = name_to_idx_.find(source);
    auto destination_it = name_to_idx_.find(destination);

    if (source_it == name_to_idx_.end() || destination_it == name_to_idx_.end()) return -1;

    return weights_[source_it->second][destination_it->second].weight_;
}

long double UndirectedFullGraph::getPathWeight(int sourceIdx, int destinationIdx) const {
    if (sourceIdx < 0 || destinationIdx < 0 || sourceIdx >= size_ || destinationIdx >= size_)
        return -1;
    return weights_[sourceIdx][destinationIdx].weight_;
}

vector<string>& UndirectedFullGraph::getPath(const string& source, const string& destination) {
    auto source_it = name_to_idx_.find(source);
    auto destination_it = name_to_idx_.find(destination);

    if (source_it == name_to_idx_.end() || destination_it == name_to_idx_.end()) return not_exist_;
    
    return weights_[source_it->second][destination_it->second].path_;
}

vector<string>& UndirectedFullGraph::getPath(int sourceIdx, int destinationIdx) {
    if (sourceIdx < 0 || destinationIdx < 0 || sourceIdx >= size_ || destinationIdx >= size_)
        return not_exist_;
    return weights_[sourceIdx][destinationIdx].path_;
}

void UndirectedFullGraph::printWeight() {
    if (weights_.size() == 0) {
        cout << "empty\n";
        return;
    }
    cout << "\n\n--------------------------\n\n";
    cout << "size = " << weights_.size() << endl;
    cout << "weight = \n";
    for (const auto& curr_r : weights_) {
        for (const auto& curr_c : curr_r) {
            cout << curr_c.weight_ << " , ";
        }
        cout << "[end]\n";
    }
    cout << "\n\n--------------------------\n\n";
}
