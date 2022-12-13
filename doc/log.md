# Development Log

## Date: 10/31/2022 -- 11/06/2022

### Weekly Goals 1

- team contract

- group meeting - determine project & algorithm

- Github Repo Creation

- project proposal

- data requisition

### Specific Tasks Completed (and by who) 1

- team contract : all

- group meeting: determine project topic and select uncovered algorithm : all

- Github Repo Creation : Peter Zhu(bowenz12)

- project proposal : all

### Problems Encountered 1

None

### Plans for next week 1

- group meeting at Thursday after lab

- utilize python to clean and further inspect data set

- shortest path algorithm test (use test batch)

- learn Dijkstra's algorithm and Floyd-Warshall algorithm

- try to optimize the data structure for nodes storage

### Optional: Questions for mentor 1

None

## Date: 11/5/2022 -- 11/11/2022

### Weekly Goals 2

1. Optimize the data structure to store the graph of airports.
2. Clean and merge data sets.
3. Data parsing.
4. Define and implement classes.
5. Set up test case.

### Specific Tasks Completed (and by who) 2

1. Decided to use a 2D-vector of tuples to store our graph data. The rows of the 2D vector will represent the starting airport, and the columns will represent the destination aiorport. The time complexity to find edges from one vertex/airport to another is constant $O(1)$. Also, because our graph is directed, we will not waste half of the matrix storing symmetrical values. In addition to this, because the number of edges is much greater than the number of vertices, the matrix will be dense and thus not waste much memory. We chose this data structure because it will store our data in an adjacency matrix which is useful for the mathematical computations that we would like to perform such as calculating the betweeness centrality via simulating thousands of traversals from one airport to another. (All group members)
2. Clean and merge data from different sources to match the routes with sources information and destination information, including longitude, latitude, country and timezone, etc. (zt17)
3. Define and implement classes, including graph, nodes, edges, and utils(for data parsing). (bowenz12)
4. Set up test case framework and implement a demo test example. (bowenz12)

### Problems Encountered 2

1. Initially we planned to use a map of vectors to store the information for our graph. In this map, the keys are vertices and the values are vectors of edges. However, because the time complexity to find edges is $O(n^2)$, we decided to use a 2D-vector of tuples to lower the complexity to $O(1)$.
2. Determine data size: the source files that we get our data from contain over 70 thousand records. We our concerned that this dataset might be too large to run our algorithms. Because of this, we plan to perform test runs on varying dataset sizes to see what dataset size is most optimal.

### Plans for next week 2

1. Data clean and rough/exploratory statistics.
2. Determine algorithm for shortest path.  
3. Implement the function for calculating distance between two nodes.  
4. Implement 2-D vector of tuples (described above)

### Optional: Questions for mentor 2

1. What is the reasonable size for data for implement?

## Date: 11/12/22 -- 11/18/22

### Weekly Goals 3

1. Data clean and rough/exploratory statistics.  
2. Determine algorithm for shortest path.  
3. Implement the function for calculating distance between two nodes.  
4. Implement 2-D vector of tuples (described above)

### Specific Tasks Completed (and by who) 3

1. We implement functions for calculating distance between two nodes both in Euclidean distance and in actual distance. When calculating actual distance, we use Haversine Formula to map latitude and longitude distance to actual distance. (bowenz12)
2. We determined to use dijkstra algorithm and floyd-warshall algorithm to find the shortest path. (All group members)
3. Significant progress on the implementation of the graph class (All group members)
4. Continued processing/cleaning on the input data set (All group members)

### Problems Encountered 3

1. After deleting a vertex from the graph, it would shift all the other vertices behind it forward one index, which would cause our (vertex to vector index) map to incorrectly store indices, unless we updated it. Updating our graph to accomadate this issue would be costly to runtime. So, instead we decided to just store a value that indicates the vertex is vacant. Then, the next time we try to add a vertex it will look for an index that has an empty vertex.
2. We were unsure as to whether or not we should store a tuple or a class within our 2D-vector representation of our graph. We ultimately decided to store flight objects (outlined in "flight.h") within our 2D-vector to represent the edges of the graph.

### Plans for next week 3

1. Find an algorithm outside of lecture material to find the shortest path.
2. Refine implementation of our graph classes
3. Once implementation is refined, implement a traversal around the graph.

### Optional: Questions for mentor 3

None

## Date: 11/18/22 -- 12/2/22

### Weekly Goals 4

1. Find an algorithm outside of lecture material to find the shortest path.
2. Refine implementation of our graph classes
3. Once implementation is refined, implement a traversal around the graph.

### Specific Tasks Completed (and by who) 4

1. Refined graph class (bowenz12)
2. implement Floyd Warshall algorithm (bowenz12)
3. implement BFS iterator (zt17)
4. implement Dijkstra's algorithm (siqidu3)

### Problems Encountered 4

None

### Plans for next week 4

1. Betweenness centrality algorithm - Zhicheng Tang
2. Written report- Zhicheng Tang, Jordan
3. Test cases: use small graphs to test validity - Bowen Zhu
4. Refine details - Bowen Zhu
5. Descriptive README. Siqi Du
6. DFS iterator - Jordan

### Optional: Questions for mentor 4

None
