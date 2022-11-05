#pragma once

#include "Node.h"

class Graph {
    public:
        // constructors

        /**
         * @brief Default constructor
         * 
         */
        Graph();

    private:
        // helper functions
        double calcWeight(int source_id, int destination_id);
};