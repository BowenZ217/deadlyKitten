1. Project Introduction

   In this project, we assumed we are an airline company and hopes to increase their profits by setting up routes to several major airports around the world. And the company wants to find the shortest routes that could pass through these predefined cities and return to the starting point.  

2. Dataset

   We use the OpenFlight dataset. The subfiles include information about routes, airport, and other Geographic Information. We can use this information to get the location of the airport and the distance between.

3. Introduce classes defined

   1. Graph
   2. GraphTraversal
   3. Airport: vertice id, country, city, location
   4. Flight: edges, source and destination
   5. Djikstra's
   6. FloydWarshall
   7. Utils: read and write files. Formula to convert latitude and longitude distance to actual distance.

4. Data Structure

   1. Modified the data structure of the original scenario. Our original plan was to store Edge classes in each entry of the 2-d vector. However, during the implementation we found that storing classes in 2-d vector was too slow and space-consuming, so we simplified to storing only the distance between two airports (vertices).
   2. Besides that we use a vector to store pointers of Airport and the index of the vector is the same as the order in the 2-d vector. In this case, when we use the indices to calculate the shortest path, we can use the coordinates to extract the corresponding airport information directly from the vector.

   

   

5. Read data

6. Write data

7. BFS iterator

8. FloydWarshall Algorithm

