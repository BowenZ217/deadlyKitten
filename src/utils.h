#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>    /* M_PI */
#include <iostream>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

/**
 * @brief Transform the data the file to a 2d vector.
 * 
 * @param fileName Name of the file to be read from.
 * 
 * @return data in this file, in 2d vector
 */
vector<vector<string>> fileToVector(const string& fileName);

/**
 * @brief Transform the data the file to a 2d vector.
 * 
 * @param fileName Name of the file to be read from.
 * @param Size the number of elements contain in each vector
 * 
 * @return data in this file, in 2d vector
 */
vector<vector<string>> fileToVector(const string& fileName, unsigned size);

/**
 * @brief Transform the data the file to a 2d vector.
 * 
 * @param fileName Name of the file to be read from.
 * @param Size the number of elements contain in each vector
 * 
 * @return data in this file, in 2d vector
 */
vector<vector<int>> fileToIntVector(const string& fileName, unsigned size);

/**
 * @brief Save the data in 2d vector to a file
 * 
 * @param fileName Name of the file to be save.
 * @param data data need to save
 */
void vectorToFile(const string& fileName, const vector<vector<int>>& data);

/**
 * @brief read each line from terminal, input `e` to stop
 * 
 * @return vector of string for each line
 */
vector<string> readInput();

/**
 * @brief remove leading and trailing spaces from a string
 * 
 * @param s string need to trim
 * @return string without leading and trailing spaces
 */
string trim(const string& s);

/**
 * @brief Calculate euclidean distance between two points 
 * 
 * @param latitude_1 latitude of first point
 * @param longitude_1 longitude of first point
 * @param latitude_2 latitude of second point
 * @param longitude_2 longitude of second point
 * 
 * @return distance
 */
long double calcDistance(long double latitude_1, long double longitude_1, long double latitude_2, long double longitude_2);

/**
 * @brief converting degrees to radians
 * 
 * @param degree input
 * 
 * @return radians of input
 */
long double degreeToRadians(const long double& degree);

/**
 * @brief Calculate distance between two points by using Haversine formula :
 * https://www.igismap.com/haversine-formula-calculate-geographic-distance-earth/
 * 
 * @param latitude_1 latitude of first point
 * @param longitude_1 longitude of first point
 * @param latitude_2 latitude of second point
 * @param longitude_2 longitude of second point
 * 
 * @return distance in km
 */
long double calcDistance_2(long double latitude_1, long double longitude_1, long double latitude_2, long double longitude_2);
