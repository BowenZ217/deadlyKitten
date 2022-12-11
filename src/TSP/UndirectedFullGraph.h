#pragma once

#include "Graph.h"
#include <limits.h>
#include <stdexcept>

class UndirectedFullGraph {
    private:
        struct Path {
            long double weight_;
            vector<string> path_;

            Path() : weight_(INT_MAX / 100) { };

            /**
             * @brief Construct a new Path with its weight and city it needs
             * 
             * @param weight 
             * @param path 
             */
            Path(long double weight, const vector<string>& path) : weight_(weight), path_(path) { };
        };
    public:
        // constructors

        /**
         * @brief Default constructor
         * 
         */
        UndirectedFullGraph() : g_(NULL), size_(0) { /* do nothing */ };

        UndirectedFullGraph(Graph* g) : g_(g), size_(0) { /* do nothing */ };

        UndirectedFullGraph(Graph* g, const vector<string>& vertexes);
        
        UndirectedFullGraph(const vector<vector<double>>& g);

        void addVertex(const string& name);

        bool vertexExist(const string& name) const;

        // getter
        int nameToIndex(const string& name) const;

        string indexToName(int idx) const;

        long double getPathWeight(const string& source, const string& destination) const;

        long double getPathWeight(int sourceIdx, int destinationIdx) const;

        vector<string>& getPath(const string& source, const string& destination);

        vector<string>& getPath(int sourceIdx, int destinationIdx);

        bool isEmpty() { return size_ == 0; };

        void printWeight();
    private:
        vector<vector<Path>> weights_;
        unordered_map<string, int> name_to_idx_;
        unordered_map<int, string> idx_to_name_;
        Graph* g_;
        vector<string> not_exist_;
        int size_;
};
