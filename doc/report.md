[toc]

# Algorithm Summary

## Floyd-Warshall

The floyd-Warshall algorithm we implemented is an algorithm for finding the shortest paths in a weighted graph. Out implementation includes a `FloydWarshall` class that has a constructor which takes the size of the graph and the graph itself represented as a 2D vector of edge weights. The constructor initializes the required data, and checks if the calculations have already been done and saved to a file. If not, it calls the helper function uses a nested loop structure to calculate the shortest paths between all pairs of vertices. The results are generated in one go and saved to a file for future test. 

The `getShortestPath` method takes a source and destination vertex, and returns the shortest path between them using the data calculated in the constructor.

 The `initialise` method is  a helper function that initializes the required data and performs the calculations for the shortest paths using the Floyd-Warshall algorithm. 

## Dijkstra

We also defined a class for Dijkstra algorithm. It has a constructor which takes the size of the graph, the graph itself and the source node. The graph is represented as a 2D vector. The constructor initializes the input data and calls the `ShortestPath` method to perform the calculations.

 The `ShortestPath` method uses a priority queue to continually search for the next node with the smallest distance from the source node. It updates the distances and previous nodes for all adjacent nodes and adds them the to the priority queue. 

The `getShortestPath` method takes a source and destination node, and returns the shortest path between them using the data calculated in teh `ShortestPath` method.

 The `initialise` method is a helper functino that initializes the required data structures and fills them with the initial values from the input graph. It also constructs a list of adjacent nodes and their distances for each node in the graph.

## Betweenness Centrality

The algorithm works by first generating all possible combinations of vertices in the graph, and then computing the shortest path between each pair of vertices. For each airport that appears in one of the shortest paths, its frequency is updated in a hash map. At the end of the calculation, the airports with the highest frequency are considered the most central.



# Test Cases Explanation

## Utils Test

This test case is testing the `filteToVector` function which will be used later to test shortest path algorithms. The function reads data from a file and returns it as a two demensional vector and compares it with the hard-coded correct answer with `compareVector` function.



## Shortest Path Test

### Test Generation

To ensure the shortest path algorithm is correct. We wrote a python sricpt to generate random graphs with different numbers of vertices and edges. It then calculates the shortest path between all pairs of vertices by the Dijkstra algorithm using package networkx and saves the results in an output file.

### Details

`[shortest-path]` test cases are testing the `getShortestPath` method of the `Graph` class, which returns the shortest path between two vertices in a graph. It compares the output to the correct answers stored in files by `compareVector` function.



##  Centrality

### Test Generation

The graphs used to test centrality are also generaged from a python script. Then we calculates the shortest path of all pairs of vertices uisng package networks and count the frequency of each vertex. Those frequencies are used as the correct answer to test our implementation.

### Details

`Centrality` test cases are testing the `calculate_centrality` method of `Centrality` class, which calculates the frequencies of vertices appear in the shortest paths of all combination of source and destination. It iterates over the expected frequency vector, retrieves the actual frequency for each airport in the graph, and checks that the actual frequency calculated matches the expected frequency.



# Answering the Leading Questions

In our project we determined the shortest paths between various airports using shortest paths found by Dijkstras algorithm and Floyd-Warshall algorithm. These shortest paths provide the airline with a set of efficient routes that it can use to connect different airports. Using these shortest routes, we were able to calculate the betweenness centrality of each airport in the network. This allowed us to measure the importance of each airport in the graph, and identify which airports to invest our routes. 

The problem we proposed is a typical traveling salesman problem, where we are given a list of cities and the distances between each pair of cities. The goal is to find the shortest possible route that visits each city exactly once and returns to the origin city. However, the algorithm we implemented only works for one source and destination city. Thus, we decided to combine the greedy algorithm with the shortest path algorithm to solve the problem. We selected ten of the most central airports in the world and started from the most central airport. We then found the shortest path between the remaining nine airports and let the first destination be the one that has the minimum shortest path to the starting point. We repeated this process, only finding the local optimal solution at each iteration, until we finished the traveling.
