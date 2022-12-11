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

        /**
         * @brief Construct a empty Undirected Graph
         * 
         * @param g other graph information
         */
        UndirectedFullGraph(Graph* g) : g_(g), size_(0) { /* do nothing */ };

        /**
         * @brief Constructer using other graph an the vertex it need to contain
         * 
         * @param g other graph information
         * @param vertexes vertex it need to contain
         */
        UndirectedFullGraph(Graph* g, const vector<string>& vertexes);
        
        /**
         * @brief Constructer only used for test case (alow us to set weight directly)
         * 
         * @param g weight informaion
         */
        UndirectedFullGraph(const vector<vector<double>>& g);

        /**
         * @brief add new vertex (using weight calc from `g_` we get in Constructer)
         * 
         * @param name vertex name
         */
        void addVertex(const string& name);

        /**
         * @brief check if vertex exist
         * 
         * @param name vertex name
         */
        bool vertexExist(const string& name) const;

        // getter
        /**
         * @brief transfor name to index
         * 
         * @param name vertex name
         * @return vertex index 
         */
        int nameToIndex(const string& name) const;

        /**
         * @brief transfor index to name
         * 
         * @param idx vertex index
         * @return vertex name 
         */
        string indexToName(int idx) const;

        /**
         * @brief Get the Path Weight using source and destination name
         * 
         * @param source source name
         * @param destination destination name
         * @return Path Weight
         */
        long double getPathWeight(const string& source, const string& destination) const;

        /**
         * @brief Get the Path Weight using source and destination index
         * 
         * @param sourceIdx source index
         * @param destinationIdx destination index
         * @return Path Weight
         */
        long double getPathWeight(int sourceIdx, int destinationIdx) const;

        /**
         * @brief Get the Path it take using source and destination name
         * 
         * @param source source name
         * @param destination destination name
         */
        vector<string>& getPath(const string& source, const string& destination);

        /**
         * @brief Get the Path it take using source and destination index
         * 
         * @param sourceIdx source index
         * @param destinationIdx destination index
         */
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
