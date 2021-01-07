# TSP - Exact Algorithm

## Instances

 * Put instances in the following directory : `../Instances`
 
 * Instances must respect the following format :  
	- The first line have the number n of vertices.
	- The next n lines contain the rows of the adjacency matrix (with the weights separated by one space) of the complete graph. Note that the matrix is symmetric.
	
 * Instances must have a .in extension. 
	Ex: 11.in
	
	
## Compile

In this directory, simply do :
```bash
$ make
```

## Execute

* In this directory, do :
```bash
$ ./exact_algorithm
```	

* Name of the instance will be ask, enter it without extension. Ex: 
```bash
Enter instance name (without extension) : 11
```
	
## Output

 * Program will print : 
	- Number of vertices of the instance
	- Execution time
	- Find path
	- Total distance of this path
	
 * Program will output in a file named `instance_exact.out` in the directory `../Instances` with the following format :
	- The first one contains the number of the vertices separated by one space, representing in which order the cities should be visited.
	- The second line should contain the weight of the cycle.
