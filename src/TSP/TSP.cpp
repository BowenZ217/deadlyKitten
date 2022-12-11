#include "TSP.h"

TSP::TSP(Graph* g, const vector<string>& vertexes) {
    reset(g, vertexes);
}

// seter
void TSP::reset(Graph* g, const vector<string>& vertexes) {
    vertex_num_ = vertexes.size();
    individual_num_ = 60;
    gen_num_ = 400;
    mutate_prob_ = 0.25;
    g_ = g;

    un_f_g_ = UndirectedFullGraph(g, vertexes);
}

/**
 * @brief Set Vertexes need to pass
 * 
 * @param vertexes Name of vertexes to pass through
 */
void TSP::resetVertexes(const vector<string>& vertexes) {
    vertex_num_ = vertexes.size();
    un_f_g_ = UndirectedFullGraph(g_, vertexes);
}

// geter
/**
 * @brief Find the Shortest Path pass through all airports
 * 
 * @return name of vertexes need to go through (in order)
 */
vector<string> TSP::getShortestPath() {
    vector<string> path;

    // calc
    GA ga(&un_f_g_, vertex_num_, individual_num_, gen_num_, mutate_prob_);
    ga.train();
    vector<int> result_idx = ga.getLastResult();

    // 
    vector<string> temp;
    int num = result_idx.size() - 1;

    for (int i = 0; i < num; ++i) {
        temp = un_f_g_.getPath(result_idx[i], result_idx[i + 1]);
        temp.pop_back();
        for (const auto& curr : temp)
            path.push_back(curr);
    }
    temp = un_f_g_.getPath(result_idx[num], result_idx[0]);
    for (const auto& curr : temp)
        path.push_back(curr);
    
    return path;
}
