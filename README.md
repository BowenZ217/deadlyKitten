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

## Presentation Video Link
TBD

## Written Report
TBD

## Running Instruction
TBD
### check out the code
```
git clone https://github.com/BowenZ217/deadlyKittenAirline.git
```
### calculate shortest path with given start point

### generate airports‘ centrality

## File List
### Graph constructor
1. Airport.h & cpp
containing the information of airports: airport_id_, index_, name_, country_, city_, latitude_, and longitude.

2. Flight.h & cpp
containing the information of flights: airline_id, source_id, destination_id

3. Graph.h & cpp
constructing a graph by using the airportFile, routeFile, and airlineFile: aiport_index as vertices, flight_index as edges.
graph[source][destination] = distance from source to destination. (INF for no edges)

### Graph traversal
1. src/graphTraversal/BFS.h & cpp
create a BFS object to traversal the graph. 
2. src/graphTraversal/DFS.h & cpp
create a DFS object to traversal the graph. 

### FloydWarshall Implementation
FloydWarshall.h & cpp
After initializing, a weight matrix is generated and saved as FloydWarshall.save. Then using the matrix to get the shortest path with shorter time.

### Dijkstra's Implementation
Dijstra.h & cpp
calculating the shortest path With given start airport.

### Betweenness Centrality Implementation
Centrality.h & cpp
If an airport is passed by shortest path with high frequency, it is an important transit point in the whole graph.
calculating the frequency by using the matrix generated in FloydWarshall, we can know the significance of each airports.

## Test Case

* [CS 225 Final Project](https://courses.engr.illinois.edu/cs225/fa2022/pages/final_project.html)
