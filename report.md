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

### Test Genration

To ensure the shortest path algorithm is correct. We wrote a python sricpt to generate random graphs with different numbers of vertices and edges. It then calculates the shortest path between all pairs of vertices by the Dijkstra algorithm using package networkx and saves the results in an output file.

### Details

`[shortest-path]` test cases are testing the `getShortestPath` method of the `Graph` class, which returns the shortest path between two vertices in a graph. It compares the output to the correct answers stored in files by `compareVector` function.
