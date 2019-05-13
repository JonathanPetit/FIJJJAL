# Pathfinding

The pathfinding is the plotting of the shortest route between two points. This algorithm should find on a map with obstacles the best way to a point A to a point B.

## A*

The A* algorithm is the process of finding a path between multiple points, called Nodes. Every nodes between the start and the end point have a weigth. The goal of the A* is to find the best path with all nodes who have the smallest cost (travelled distance, shortest time, ...).

The search of the smallest cost function is called ***heuristic***.

## In this case

The goal of the pathfinding in this drone code is the find the shortest way to go on the delivery point. Our pathfinding take the start and the end coordonates on parameters. It's search the futur neigthbour node who have the smallest cost (travelled distance) until reach to end point.

The pathfinding take the location (coordonates) of the start and the end point. It build map with this location to search the way. The A* function check all nodes to get the final path. This algorithm begin with the start node check the best futur node around. After the result node become the reference. 

The result of the pathfinding is a string with the direction to go to the end node.

## Code and functions
1. ***Node***
* `void calculateFValue(const loc_t& locDest)` The f_value is for heuristic. It's the remaining distance between the node and the arrival. The heuristic select the node which have the smallest value.
* `void updateGValue(const int & i)` The g_value is the distance already travalled. This function update this value of the node. It is to make an order in all nodes.

2. ***Pathfinding***
* `void buildMap(const loc_t &loc_start , const loc_t &loc_finish)` Build map and set different variable for the pathfinding.
* `void addObstacles(loc_t obstacle)` Add obstacles to the map.
* `string aStar()` This function is the algorithm to make the best path. More details in the code.
* `void draw(string path)` Draw the result path of the A* function. This function is only for debugging and demonstration.


4. ***Struct***
All structs (location) are in **struct.h**

For more informations, the code is comment.

## Use and Output of main.cpp

Example of the pathfinding is in the main.cpp.
```shell
$ g++ -o path *.cpp
$ ./pathfinding
```

## Improvements
* The pathfinding must have a "step" parameter because if we have a big map, the search of the path take more times. If we have a step parameter the map will be small and the useless checkpoint will be remove.
* For now, the result of the A* is a string with the direction. This result should be a array (path) with checkpoints (x, y, direction). 
* Make a module with checkpoint array in parameter and the result is a array with the moving instruction for the drone.