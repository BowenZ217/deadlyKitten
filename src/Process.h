#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "cs225/PNG.h"

#include "Airport.h"
#include "Graph.h"
#include "graphTraversal/BFS.h"
#include "TSP/TSP.h"
#include "Centrality.h"
#include "utils.h"

using std::cout;
using std::endl;

/**
 * @brief process data for `main.cpp`
 * 
 * @param inputFileName file to read input
 * @param outputFileName file to store result
 */
void process(const string& inputFileName, const string& outputFileName);

void processFW(string& data, Graph& g, const string& source, const string& destination);

void processDij(string& data, Graph& g, const string& source, const string& destination);

void processCent(string& data, Graph& g, const string& num_of_top, const string& calc_shortest);

void processTSP(string& data, Graph& g, const string& vertexes);
