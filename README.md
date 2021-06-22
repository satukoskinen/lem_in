# Lem-in

## Problem summary

You are given an "ant farm", a network of rooms with edges connecting the rooms. Each network
will have a source and a destination(sink) room. You are to optimize the flow
through the network with any given number of ants.

## Input

Input to the program will be in the following format:

```
##start // Next line is source node.
1 23 3 // Room ID, X, Y
2 16 7
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end // Next line is sink node.
0 9 5
0-4 // Edges connecting Room ID - Room ID
0-6
1-3
4-3
5-2
3-5
#another comment // Comments are discarded
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```

In the subject the rooms have a capacity, but in order to get the graph
algorithms to work we translate the capacity to be an attribute of an edge.

# Algorithm

To solve the problem we employ a a max flow algorithm. More spesifically we use
a modified version of the Edmonds Karp algorithm.

1. The first transformation is made when reading the input. We interpret each
   undirected edge as two edges to make the graph directed.
2. Second transformation is an operation called vertex disjoint paths. When we
   are creating augmenting flow paths, the paths can't share nodes. To prevent
   this we split each node into two nodes (in, out) and run the
   algorithm on this disjoint graph. We need to preserve the connection between
   the disjoint nodes and the original nodes.
3. We run the Edmonds Karp algorithm on the transformed graph, but with a slight
   modification. Normally Edmonds Karp just returns the max flow as an integer.
   However we return the different path combinations. This is done so that we
   can later optimize the path use for different amounts of ants.
4. After we have constructed the differet path combinations that constitute the
   max flow, we search for the optimal combination by ...SATU WRITES

Relevant reading:

[Edmonds Karp](https://en.wikipedia.org/wiki/Edmonds–Karp_algorithm)
[Ford Fulkerson](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm)
[Max Flow](https://en.wikipedia.org/wiki/Maximum_flow_problem)
[Vertex Disjoint Paths](https://courses.helsinki.fi/sites/default/files/course-material/4671514/max-flow-reductions.pdf)

# Output


