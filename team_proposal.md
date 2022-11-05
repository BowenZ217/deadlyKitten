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
Our input dataset consists of three files, which were obtained from Open Flights. We plan to filter out some unwanted information from the input database, such as `IATA` and `ICAO`, so that our dataset will be easier to process. Files informations:

[airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)

format example:

[Airport ID],[Name],[City],[Country],[Latitude],[Longitude],[Altitude]
1,"Goroka Airport","Goroka","Papua New Guinea",-6.081689834590001,145.391998291,5282

Description:

`Airport ID` Unique OpenFlights identifier for this airport.   
`Name` Name of airport. May or may not contain the City name.   
`City` Main city served by airport. May be spelled differently from Name.   
`Country` Country or territory where the airport is located.   
`Latitude` Decimal degrees, usually to six significant digits. Negative is South, positive is North.   
`Longitude` Decimal degrees, usually to six significant digits. Negative is West, positive is East.   
`Altitude` In feet.   


[airlines.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airlines.dat) (~400 KB)

format example:

[Airport ID],[Name],[Alias]
1,"Private flight",\N
324,"All Nippon Airways","ANA All Nippon Airways"

Description:

`Airline ID` Unique OpenFlights identifier for this airline.
`Name` Name of the airline.
`Alias` Alias of the airline. For example, All Nippon Airways is commonly known as "ANA". If there is not a alias, use `\N`


[routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat) (~2 MB)

format example:

	[Airline],[Airline ID],[Source airport],[Source airport ID],[Destination airport],[Destination airport ID],[Stops]
	2B,410,AER,2965,KZN,2990,0

Description:

`Airline` 2-letter (IATA) or 3-letter (ICAO) code of the airline.
`Airline ID` Unique OpenFlights identifier for airline (from Airline).
`Source airport` 3-letter (IATA) or 4-letter (ICAO) code of the source airport.
`Source airport ID` Unique OpenFlights identifier for source airport (see Airport)
`Destination airport` 3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
`Destination airport ID` Unique OpenFlights identifier for destination airport (from `airports.dat`)
`Stops` Number of stops on this flight ("0" for direct)


## Data Correction

## Data Storage

## Algorithm 

## Timeline
