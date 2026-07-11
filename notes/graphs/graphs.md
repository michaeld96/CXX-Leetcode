# Graphs

This is a little snippet of notes to remember when dealing with graph problems.

## Complete Graph

Some methods to tell if a graph is complete is:
- If a graph has $n$ vertices, then the degree (number of edges that vertex has) will be $n-1$.
- If the number of edges is $\frac{n(n-1)}{2}$ where $n$ is the number of vertices.

## Representing Edges


### Adjacent List  
To represent edges we use a data structure called an adjacency list. It is a 2D list where the 
first dimension is the node and the second dimension is all the nodes that this one is connected to.
Be careful here as it depends if a graph is directed or not. 

More on adjacency lists [here](https://www.geeksforgeeks.org/dsa/adjacency-list-meaning-definition-in-dsa/).

### Adjacent Matrix

This is another way to represent edges. The difference here is that the matrix is $n \times n$ where
$n$ is the number of vertices in the graph. Each row corresponds with a vertex and each column 
represents if an edge exists by a boolean or integer value of $1$ for existence $0$ otherwise. 

## Traversing a Graph

When traversing a graph one uses DFS or BFS. Both DFS and BFS require a visited list to avoid cycles.
