# deadlyKittenAirline

## Group Name

deadlyKitten

## Group member names and NetIDs

* Peter Zhu (bowenz12)
* Siqi Du (siqidu3)
* Zhicheng Tang (zt17)
* Jordan Alwan (jzalwan2)

## Project Introduction

DeadlyKitten Airlines is an ambitious new airline company. It hopes to increase their profits by setting up routes to several major airports around the world. In addition, the planes take off from the city where the airline's factory is located, and after flying through a certain number of airports, they need to return to the original factory for overhaul. The company cannot open up new routes, and can only follow the paths that already exist. Therefore, it wants to find the shortest routes that could pass through these predefined cities and return to the starting point.

Considering that each aircraft may have a different set of cities to arrive at, the company will have hundreds of aircraft, and the destination may change in the future, it is necessary to develop search algorithms that can efficiently find the shortest paths between dozens of cities/airports given.

## System Overview

To reach the company's goals, our analysts plan to utilize the OpenFlight dataset. The sub-dataset “routes.dat” covers the source airports and destinations and can form the graph in which we will run the algorithms.

In addition, we have another sub dataset “airport.dat”, which contains the longitude and latitude of each airport. After merging these two datasets, the distance of each route can be calculated. To make the problem solvable we will estimate the actual distance of routes using the Euclidean distance in latitude and longitude.

Based on the shortest paths, we further want to calculate the betweenness centrality to measure the importance of airports over the world.

## Presentation Video

[video](https://drive.google.com/file/d/1mRAOeos71ml_qIHjO8uC0evkSkPjY4WI/view?usp=sharing)

## Written Report

[Report](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/doc/report.md)

## Running Instruction

### check out the code

To setup this project, clone the repository locally using the command, then cd into the newly made directory

```bash
git clone https://github.com/BowenZ217/deadlyKittenAirline.git

cd deadlyKittenAirline
```

### if it is the first time to build after clone, you need to run

```bash
mkdir build

cd build

cmake ..
```

### to build code, you need to run

```bash
make
```

in the terminal.

### open **input.txt** in the root folder

In input.txt:

* you can use true/false in each state to control if run this part, example :

```file
shortest path (Floyd Warshall) state: false
```

it will not call FloydWarshall

* Also, you can costumize the number of centrlity output and the start/end airports used to generate shortest path in this file.  

```file
example: centrality(nmber of top): 5
```

it will output top 5 important airports

### to run code, you need to run

```bash
./main
```

in the terminal

* **Warning**: If the data is too large, `FloydWarshall` can take over 1 hour to run.

### output

results will export automatically in terminal window or you can open the **output.txt** which is located in your root folder.

## Testing Instruction

### to test code, you need to run

```bash
./test
```

in the terminal

### Test Case List

* File io stream

    TEST_CASE("Test read file", "[utils]")

    TEST_CASE("Test write file", "[utils]")

* Graph shortest path calculate in graphs with different complexity

    TEST_CASE("Test FW Shorest Path V5 E12", "[shortest-path]")

    TEST_CASE("Test FW Shortest Path V10 E30", "[shortest-path]")

    TEST_CASE("Test FW Shortest Path V15 E50", "[shortest-path]")

    TEST_CASE("Test Dijkstra Shorest Path V5 E12", "[shortest-path]")

    TEST_CASE("Test Dijkstra Shortest Path V10 E30", "[shortest-path]")

    TEST_CASE("Test Dijkstra Shortest Path V15 E50", "[shortest-path]")

* Centrality in graphs with different complexity

    TEST_CASE("Test Centrality V5E12", "[Centrality]")

    TEST_CASE("Test Centrality V10E30", "[Centrality]")

    TEST_CASE("Test Centrality V15E50", "[Centrality]")

* TSP with the obvious best path

    TEST_CASE("Test Genetic Algorithms", "[GA]")

## File List

### data

* raw data of airpots, airlins, and routes (from openflight.org)

* [FloyWarshall.save_](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/data/FloydWarshall.save_) FloydWarshall generating shortest path matrix

* [data_cleaning.ipynb](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/data/data_cleaning.ipynb)generate randomly graph and its shortest-path for test code

* Example of airport file:

|    |    |    |    |    |    |    |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| [Airport ID] | [Name] | [City] | [Country] | [Latitude] | [Longitude] | [Altitude] |
| 1 | "Goroka Airport" | "Goroka" | "Papua New Guinea" | -6.081689834590001 | 145.391998291 | 5282 |

* Example of route file:

|    |    |    |
| ----------- | ----------- | ----------- |
| [Airport ID] | [Name] | [Alias] |
| 1 | "Private flight" | \N |
| 324 | "All Nippon Airways" | "ANA All Nippon Airways" |

* Example of airline file:

|    |    |    |    |    |    |    |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| [Airline] | [Airline ID] | [Source airport] | [Source airport ID] | [Destination airport] | [Destination airport ID] | [Stops] |
| 2B | 410 | AER | 2965 | KZN | 2990 | 0 |

### doc

* includinding our [team files](https://github.com/BowenZ217/deadlyKittenAirline/tree/main/doc) (team contract, proposal, and log)
and [written report](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/doc/report.md).

### src

1) Graph constructor

    * [Airport.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Airport.h) & [Airport.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Airport.cpp)

        containing the information of airports: `airport_id_, index_, name_, country_, city_, latitude_, and longitude`

    * [Flight.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Flight.h) & [Flight.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Flight.cpp)

        containing the information of flights: `airline_id, source_id, destination_id`

    * [Graph.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Graph.h) & [Graph.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Graph.cpp)

        constructing a graph by using the airportFile, routeFile, and airlineFile: aiport_index as vertices, flight_index as edges.

        `graph[source][destination]` = distance from source to destination. (INF for no edges)

2) Graph traversal

    * [BFS.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/graphTraversal/BFS.h) & [BFS.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/graphTraversal/BFS.cpp)
    create a BFS object to traversal the graph.

3) FloydWarshall Implementation

    * [FloydWarshall.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/FloydWarshall.h)

    * [FloydWarshall.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/FloydWarshall.cpp)

        After initializing, a weight matrix is generated and saved as FloydWarshall.save. Then using the matrix to get the shortest path with shorter time.

4) Dijkstra's Implementation

    * [Dijstra.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Dijkstra.h)

    * [Dijstra.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Dijkstra.cpp)

        calculating the shortest path With given start airport.

5) Betweenness Centrality Implementation

    * [Centrality.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Centrality.h)

    * [Centrality.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Centrality.cpp)

        If an airport is passed by shortest path with high frequency, it is an important transit point in the whole graph.
        calculating the frequency by using the matrix generated in FloydWarshall, we can know the significance of each airports.

6) Travel Salesman Problem Solving

    * [TSP](https://github.com/BowenZ217/deadlyKittenAirline/tree/main/src/TSP)

    generate shortest route with a set of airports with genetic algorithm.

### Test

* [test_data](https://github.com/BowenZ217/deadlyKittenAirline/tree/main/test_data)

    The information of test examples
    we generate 3 graphs with different complexity randomly and their shortest path solutions by [test.ipynd](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/test.ipynb).

* [tests](https://github.com/BowenZ217/deadlyKittenAirline/tree/main/tests)

    Test cases for io stream, FloydWarshall's algorithm, Dijkstra's algorithm, and centrality calculator.

## Referance

[CS 225 Final Project](https://courses.engr.illinois.edu/cs225/fa2022/pages/final_project.html)
