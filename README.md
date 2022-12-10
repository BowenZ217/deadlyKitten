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
TBD

## Written Report
[Report](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/report.md)

## Running Instruction
### check out the code
```
git clone https://github.com/BowenZ217/deadlyKittenAirline.git
```
### to build code, you need to run:
 ```make
make
```
in the terminal.

### Functions
1. input departure and destination for searching shortest path

    Open **input.txt**
    
    given start & destination: input airport name, use comma to split (example: Goroka Airport,Thule Air Base)

2. find the shortest path among major airports (greedy algorithm)

    do nothing: default function    

3. find the optimal shortest path among major airports (genetic algorithem)

    do nothing: default function    


### to run code, you need to run:
 ```main
./main
```
in the terminal

#### output
results will export automatically in terminal window or you can open the **output** folder which is located in your root folder.

output_given.txt

output_greedy.txt

output_genetic.txt

## Testing Instruction
### to test code, you need to run:
 ```test
./test
```
in the terminal



### Test Case List

* File io stream

    TEST_CASE("Test datToVector", "[utils]")

* graph shortest path calculate in graphs with different complexity

    TEST_CASE("Test FW Shorest Path V5 E12", "[shortest-path]") 

    TEST_CASE("Test FW Shortest Path V10 E30", "[shortest-path]") 

    TEST_CASE("Test FW Shortest Path V15 E50", "[shortest-path]") 

    TEST_CASE("Test Dijkstra Shorest Path V5 E12", "[shortest-path]") 

    TEST_CASE("Test Dijkstra Shortest Path V10 E30", "[shortest-path]") 

    TEST_CASE("Test Dijkstra Shortest Path V15 E50", "[shortest-path]") 

* centrality in graphs with different complexity
    
    TEST_CASE("Test Centrality V5E12", "[Centrality]") 

    TEST_CASE("Test Centrality V10E30", "[Centrality]") 

    TEST_CASE("Test Centrality V15E50", "[Centrality]") 



## File List
### Graph constructor
* [Airport.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Airport.h) & [Airport.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Airport.cpp)

    containing the information of airports: airport_id_, index_, name_, country_, city_, latitude_, and longitude.

* [Flight.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Flight.h) & [Flight.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Flight.cpp)

    containing the information of flights: airline_id, source_id, destination_id

* [Graph.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Graph.h) & [Graph.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Graph.cpp)

    constructing a graph by using the airportFile, routeFile, and airlineFile: aiport_index as vertices, flight_index as edges.

    graph[source][destination] = distance from source to destination. (INF for no edges)

### Graph traversal


* [BFS.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/graphTraversal/BFS.h) & [BFS.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/graphTraversal/BFS.cpp)
create a BFS object to traversal the graph. 

* DFS.h & cpp (unfinished)
create a DFS object to traversal the graph. 

### FloydWarshall Implementation
* [FloydWarshall.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/FloydWarshall.h)
* [FloydWarshall.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/FloydWarshall.cpp)

    After initializing, a weight matrix is generated and saved as FloydWarshall.save. Then using the matrix to get the shortest path with shorter time.

### Dijkstra's Implementation
* [Dijstra.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Dijkstra.h)
* [Dijstra.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Dijkstra.cpp)

    calculating the shortest path With given start airport.

### Betweenness Centrality Implementation
* [Centrality.h](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Centrality.h)
* [Centrality.cpp](https://github.com/BowenZ217/deadlyKittenAirline/blob/main/src/Centrality.cpp)

    If an airport is passed by shortest path with high frequency, it is an important transit point in the whole graph.
    calculating the frequency by using the matrix generated in FloydWarshall, we can know the significance of each airports.





[CS 225 Final Project](https://courses.engr.illinois.edu/cs225/fa2022/pages/final_project.html)
