# Development Log (Date: 11/5/2022 -- 11/11/2022)

## Weekly Goals
1. Optimize the data structure to store the graph of airports.
2. Clean and merge data sets.
3. Data parsing.
4. Define and implement classes.
5. Set up test case.

## Specific Tasks Completed (and by who)
1. Decided to use a 2D-vector of tuples to store our graph data. The rows of the 2D vector will represent the starting airport, and the columns will represent the destination aiorport. The time complexity to find edges from one vertex/airport to another is constant $O(1)$. Also, because our graph is directed, we will not waste half of the matrix storing symmetrical values. In addition to this, because the number of edges is much greater than the number of vertices, the matrix will be dense and thus not waste much memory. We chose this data structure because it will store our data in an adjacency matrix which is useful for the mathematical computations that we would like to perform such as calculating the betweeness centrality via simulating thousands of traversals from one airport to another. <All group members>
2. Clean and merge data from different sources to match the routes with sources information and destination information, including longitude, latitude, country and timezone, etc. <zt17>
3. Define and implement classes, including graph, nodes, edges, and utils(for data parsing). <bowenz12>
4. Set up test case framework and implement a demo test example.<bowenz12>


## Problems Encountered 
1. Initially we planned to use a map of vectors to store the information for our graph. In this map, the keys are vertices and the values are vectors of edges. However, because the time complexity to find edges is $O(n^2)$, we decided to use a 2D-vector of tuples to lower the complexity to $O(1)$.
2. Determine data size: the source files that we get our data from contain over 70 thousand records. We our concerned that this dataset might be too large to run our algorithms. Because of this, we plan to perform test runs on varying dataset sizes to see what dataset size is most optimal.

## Plans for next week
1. Data clean and rough/exploratory statistics.  
2. Determine algorithm for shortest path.  
3. Implement the function for calculating distance between two nodes.  
4. Implement 2-D vector of tuples (described above)

## Optional: Questions for mentor
1. What is the reasonable size for data for implement?   