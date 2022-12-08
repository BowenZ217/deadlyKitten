# Floyd-Warshall

## Summary

The floyd-Warshall algorithm we implemented is an algorithm for finding the shortest paths in a weighted graph. Out implementation includes a `FloydWarshall` class that has a constructor which takes the size of the graph and the graph itself represented as a 2D vector of edge weights. The constructor initializes the required data, and checks if the calculations have already been done and saved to a file. If not, it calls the helper function uses a nested loop structure to calculate the shortest paths between all pairs of vertices. The results are generated in one go and saved to a file for future test. 

The `getShortestPath` method takes a source and destination vertex, and returns the shortest path between them using the data calculated in the constructor.

 The `initialise` method is  a helper function that initializes the required data and performs the calculations for the shortest paths using the Floyd-Warshall algorithm. 

## Tests



# Dijkstra

## Summary

We also defined a class for Dijkstra algorithm. It has a constructor which takes the size of the graph, the graph itself and the source node. The graph is represented as a 2D vector. The constructor initializes the input data and calls the `ShortestPath` method to perform the calculations.

 The `ShortestPath` method uses a priority queue to continually search for the next node with the smallest distance from the source node. It updates the distances and previous nodes for all adjacent nodes and adds them the to the priority queue. 

The `getShortestPath` method takes a source and destination node, and returns the shortest path between them using the data calculated in teh `ShortestPath` method.

 The `initialise` method is a helper functino that initializes the required data structures and fills them with the initial values from the input graph. It also constructs a list of adjacent nodes and their distances for each node in the graph.



# Betweenness Centrality

## Summary

The algorithm works by first generating all possible combinations of vertices in the graph, and then computing the shortest path between each pair of vertices. For each airport that appears in one of the shortest paths, its frequency is updated in a hash map. At the end of the calculation, the airports with the highest frequency are considered the most central.

## Test

