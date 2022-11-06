#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <assert.h>     /* assert */
#include <algorithm>
#include <sstream>
#include <iostream>

using std::ifstream;
using std::vector;
using std::string;

/**
 * @brief Transform the data the file to a 2d vector.
 * 
 * @param fileName Name of the file to be read from.
 * @param Size the number of elements contain in each vector
 * 
 * @return data in this file, in 2d vector
 */
vector<vector<string>> datToVector(const string& fileName, unsigned size);

/**
 * @brief remove leading and trailing spaces from a string
 * 
 * @param s string need to trim
 * @return string without leading and trailing spaces
 */
string trim(const string& s);