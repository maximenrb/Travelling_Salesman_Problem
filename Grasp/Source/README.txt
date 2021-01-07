TSP - GRASP ALGORITHM
=====================


INSTANCES
---------

 * Put instances in the following directory : "../Instances"
 
 * Instances must respect the following format :  
	- The first line have the number n of vertices.
	- The next n lines contain the rows of the adjacency matrix (with the weights separated by one space) of the complete graph. Note that the matrix is symmetric.
	
 * Instances must have a .in extension. 
	Ex: 11.in
	
	
COMPILE
-------

 * In this directory, simply do :
    $ make


EXECUTE
-------

 * In this directory, do :
	$ ./grasp_algorithm
	
 * Name of the instance will be ask, enter it without extension. 
	Ex: "Enter instance name (without extension) :" 11

 * Rate number will be ask (alpha), it's a number between 0 and 1.
    Ex: "Enter rate number between 0 and 1 (ex: alpha = 0.8) :" 0.8

 * Max iteration will be ask.
    Ex: "Enter max iterations :" 200
	
	
OUTPUT
------

 * Program will print : 
	- Number of vertices of the instance
	- Execution time
	- Find path
	- Total distance of this path
	
 * Program will output in a file named "instance_grasp.out" in the directory "../Instances" with the following format :
	- The first one contains the number of the vertices separated by one space, representing in which order the cities should be visited.
	- The second line should contain the weight of the cycle.