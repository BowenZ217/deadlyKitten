# Team Proposal

## Leading Question

DeadlyKitten Airlines is an ambitious new airline company. It hopes to increase their profits by setting up routes to several major airports around the world. In addition, the planes take off from the city where the airline's factory is located, and after flying through a certain number of airports, they need to return to the original factory for overhaul. The company cannot open up new routes, and can only follow the paths that already exist. Therefore, it wants to find the shortest routes that could pass through these predefined cities and return to the starting point. Considering that each aircraft may have a different set of cities to arrive at, the company will have hundreds of aircraft, and the destination may change in the future, it is necessary to develop search algorithms that can efficiently find the shortest paths between dozens of cities/airports given.

To reach the company's goals, our analysts plan to utilize the OpenFlight dataset. The sub dataset “routes.dat” covers the source airports and destinations and can form the graph in which we will run the algorithms. In addition, we have another sub dataset “airport.dat”, which contains the longitude and latitude of each airport. After merging these two datasets, the distance of each route can be calculated. To make the problem solvable we will estimate the actual distance of routes using the Euclidean distance in latitude and longitude.

Based on the shortest paths, we further want to calculate the betweenness centrality to measure the importance of airports over the world.

From this, our target goals are to:

- find the shortest path that a plane can take to reach all of it’s destinations
- calculate the betweenness centrality/figure out which airports are the most important
- implement traversals (bfs, dfs) and different search algorithms (dijkstra's, flowd-warshall, kruskal, and prim's) and compare their time complexities in respect to our problem
- test how other algorithms (such as A* search) impact the time complexity of solving our problem

## Dataset Acquisition

The dataset we are using is the [Open Flights](https://openflights.org/data.html) database of every airport, airline and route in the world. Generally, it consists of three sub data sets that relate to airport, airline and route. To find the shortest path and most important airports, we mainly use airport and route data. The airport data has about 20000 entries and route data has about 60000 entries which are considerably large. If we find in subsequent implementations that we cannot handle such a large amount of data, we will narrow the route data within a particular country. Otherwise, we’ll be using the entire dataset.

## Data Format

Our input dataset consists of three files, which were obtained from Open Flights. We plan to filter out some unwanted information from the input database, such as `IATA` and `ICAO`, so that our dataset will be easier to process.

### Files informations

#### [airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)

format example:

```dat
[Airport ID],[Name],[City],[Country],[Latitude],[Longitude],[Altitude]
1,"Goroka Airport","Goroka","Papua New Guinea",-6.081689834590001,145.391998291,5282
```

Description:

`Airport ID` Unique OpenFlights identifier for this airport.

`Name` Name of airport. May or may not contain the City name.

`City` Main city served by airport. May be spelled differently from Name.

`Country` Country or territory where the airport is located.

`Latitude` Decimal degrees, usually to six significant digits. Negative is South, positive is North.

`Longitude` Decimal degrees, usually to six significant digits. Negative is West, positive is East.

`Altitude` In feet.

---

#### [airlines.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airlines.dat) (~400 KB)

format example:

```dat
[Airport ID],[Name],[Alias]
1,"Private flight",\N
324,"All Nippon Airways","ANA All Nippon Airways"
```

Description:

`Airline ID` Unique OpenFlights identifier for this airline.

`Name` Name of the airline.

`Alias` Alias of the airline. For example, All Nippon Airways is commonly known as "ANA". If there is not a alias, use `\N`

---

#### [routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat) (~2 MB)

format example:

```dat
[Airline],[Airline ID],[Source airport],[Source airport ID],[Destination airport],[Destination airport ID],[Stops]
2B,410,AER,2965,KZN,2990,0
```

Description:

`Airline` 2-letter (IATA) or 3-letter (ICAO) code of the airline.

`Airline ID` Unique OpenFlights identifier for airline (from Airline).

`Source airport` 3-letter (IATA) or 4-letter (ICAO) code of the source airport.

`Source airport ID` Unique OpenFlights identifier for source airport (see Airport)

`Destination airport` 3-letter (IATA) or 4-letter (ICAO) code of the destination airport.

`Destination airport ID` Unique OpenFlights identifier for destination airport (from `airports.dat`)

`Stops` Number of stops on this flight ("0" for direct)

## Data Correction

We will check the data in advance from the following aspects in Python and mysql.

1. data integrity of sources: check if there is null data in records from the sources. According to our goal about path planning among a specific set of main cities, we will exclude unrelated data ahead of operating. So non related airports or routes missing are acceptable in sources, and the null data can be dropped in this case without leading to loss of information. Then for the name or code missing, we will use queries to find them and fill null.
2. correction: check the geographical data of an airport, including the rationality of latitude, longitude, city, and altitude to avoid errors.
3. consistency across data tables, including checking the consistent correspondence among the airport code, name, and the location information in source tables.
4. rationality: for the relatively important cities ( we probably select as a vertical of the shortest path problem), we will check the routes' information to avoid inaccuracy, such as the rationality of the frequency of the city being passed.

## Data Storage

Adjacency Matrix for distance
$O(n^2)$, where $n$ is the number of vertices(airports) in our dataset.
We use airports as nodes in the directed graph, and calculate the distance between each airport as the weight of each edge using the airport dataset

Vector for airport information
$O(n)$

## Algorithm

### Breadth First Search (BFS)

Compared to depth first search (DFS), we consider BFS as a more feasible method in this case. According to the datasets, due to a wide number of airport options, there are bound to be different routes with multiple stops in between from one place to another during finding the shortest path. It is very possible that the stack is filled with all the vertices in the graph and requires much more memory to store potential paths than BFS does. And as for time complexity, we need to explore each of a huge number of edges at once,  which leads to an impressively complicated condition. So it is practical to use BFS in this case.
Firstly,  we will model  the airport network as a graph and initialize the BFS queue with the given location as the starting point. Considering the complexity of the airport network, we can choose a more specific area to implement or set a limit of stops, which can limit the number of searches between two airports. Then we can perform the breadth first traversal, and keep going until the queue is empty or until the maximum number of stops has been exhausted.
Optionally, we can combine BFS with Floyd-Warshall Algorithm to explore a solution. After working out the shortest path matrix by Floyd-Warshall, we can utilize BFS to reach a total route planning.

### Dijkstra's Algorithm

After calculating the distances information based on the dataset. We will model the connections among given airports set as a graph. The weight of edges represents the distance between two nodes. If two nodes are not connected directly, the initial distance will be infinite. From a given start airport, we will start checking the distance between it with the adjacent airport, and use the distance to update edge weight. Then we will select the node that is closest to the source node based on the current known distances and analyze the new node to update the shortest path. Sequentially, we will work out the shortest path.

### Floyd-Warshall Algorithm

Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. As mentioned in data storage, we will set up adjacency matrix of dimension n*n, which is filled with the distance between two vertices. Sequentially, we can use the previous matrix to generate a new matrix in each step. In the kth step, let k be the intermediate vertex in the shortest path from source to destination, then each element of matrix (suppose as Aij) will be `A[i][k] + A[k][j]` if `A[i][j]` > the sum of `A[i][k]` and `A[k][j]`. Consequently, we will work out the shortest path between each pair of vertices. Once we get the result, the overall shortest path can be easily generated by a search algorithm.

### Betweenness centrality

Betweenness centrality is a measure of the centrality of a node in the network. It is often used to find intermediate nodes that often need to be accessed in a path. To calculate the betweenness centrality, we need to iterate through all pairs of nodes in the network. For each pair of nodes, we will use efficient algorithms we implemented earlier to derive the shortest path that passes through them. After we compute all shortest paths, for each node, we compute the centrality based on how many paths that need to access that node. Calculating centrality is a very time consuming task, because it has to find the shortest path for all pairs of airports. Thus, we plan to assume our network unweighted when calculating the shortest path. If it’s still too complex, we will first divide airports into different countries and find the center within each country. Then, we find the final few important airports based on the centers of each country. The time complexity of choosing 2 from n elements is O(n^2). The eventual time complexity to compute betweenness centrality depends on the algorithm we select to find the shortest path.

## Timeline

As a team, identify a list of tasks such as data acquisition, data processing, completion of each individual algorithm, production of final deliverables, etc... and write a proposed timeline for the completion of these tasks. You are not required to adhere strictly to this timeline but it should represent a reasonable set of benchmarks to strive for. For example, stating that you will finish all graph algorithms over the span of a single week is not reasonable. At least one proposed task must be completed before the mid-project checkin -- part of the mid-project grade will be based on whether or not this target goal was met.
