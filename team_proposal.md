## Leading Question 
DeadlyKitten Airlines is an ambitious new airline company. It hopes to increase their profits by setting up routes to several major airports around the world. In addition, the planes take off from the city where the airline's factory is located, and after flying through a certain number of airports, they need to return to the original factory for overhaul. The company cannot open up new routes, and can only follow the paths that already exist. Therefore, it wants to find the shortest routes that could pass through these predefined cities and return to the starting point. Considering that each aircraft may have a different set of cities to arrive at, the company will have hundreds of aircraft, and the destination may change in the future, it is necessary to develop search algorithms that can efficiently find the shortest paths between dozens of cities/airports given. To reach the company's goals, our analysts plan to utilize the OpenFlight dataset. The sub-dataset “routes.dat” covers the source airports and destinations and can form the graph in which we will run the algorithms. In addition, we have another sub dataset “airport.dat”, which contains the longitude and latitude of each airport. After merging these two datasets, the distance of each route can be calculated. To make the problem solvable we will estimate the actual distance of routes using the Euclidean distance in latitude and longitude. 
Based on the shortest paths, we further want to calculate the betweenness centrality to measure the importance of airports over the world.

From this, our target goals are to:
-find the shortest path that a plane can take to reach all of it’s destinations
-calculate the betweenness centrality/figure out which airports are the most important
-implement traversals (bfs, dfs) and different search algorithms (dijkstra's, flowd-warshall, kruskal, and prim's) and compare their time complexities in respect to our problem
-test how other algorithms (such as A* search) impact the time complexity of solving our problem


## Dataset Acquisition
The dataset we are using is the [Open Flights](https://openflights.org/data.html) database of every airport, airline and route in the world. Generally, it consists of three sub data sets that relate to airport, airline and route. To find the shortest path and most important airports, we mainly use airport and route data. The airport data has about 20000 entries and route data has about 60000 entries which are considerably large. If we find in subsequent implementations that we cannot handle such a large amount of data, we will narrow the route data within a particular country. Otherwise, we’ll be using the entire dataset.

## Data Format
Our input dataset consists of three files, which were obtained from Open Flights. We plan to filter out some unwanted information from the input database, such as `IATA` and `ICAO`, so that our dataset will be easier to process.

## Data Correction

## Data Storage

## Algorithm 

## Timeline
