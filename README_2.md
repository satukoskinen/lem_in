# Lem-in

## Project summary

You are given an "ant farm", a network of rooms with links connecting the rooms. Each network will have a source and a destination (sink) room. The task is to optimize the flow of ants through the network from source to sink with any given number of ants.

## Input

Input to the program is comprised of the amount of ants followed by rooms (nodes) and links (edges) connecting the rooms. The source and sink nodes are designated by preceding ``##start`` and ``##end`` commands. Each node has a unique name and coordinates. Each (undirected) link is saved as two directed edges between the nodes, producing a directed graph.

```
10 // Number of ants
##start // Next line is the source node.
1 23 3 // Room ID, X, Y
2 16 7
#comment // Comments are discarded
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end // Next line is the sink node.
0 9 5
0-4 // Edges connecting Room ID - Room ID
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```

## Algorithm

The assignment can be interpreted as a special case of finding the maximum flow of a graph. The goal, however, is not only to find the maximum flow through the network (in this case, to be precise, the maximum amount of vertex-disjoint paths), but to determine the optimal combinations of paths through which to move the given amount of ants.

To solve the problem, the program proceeds as follows:

1. Parse the input and save it as a directed graph
2. Transform the input graph into the form required by the max flow algorithm and the restrictions imposed by the subject
3. Run the Edmonds-Karp maximum flow algorithm on the transformed graph to find the possible path combinations up to the maximum flow
4. Given the number of ants, determine the optimal combination of paths to use and how many ants to send down each individual path
5. Print rounds of moves that move all ants from source to sink along the determined paths

### Transforming the graph

In order to apply the max flow algorithm on the graph, the input graph needs to go through two different transformations.

In a typical formulation of computing a max flow through a flow network, only the edges between the nodes have capacity constraints that specify how much flow can simultaneously pass through an edge. On a given path from source to sink, the maximum amount of flow that can be sent through that one path is therefore determined by the edge with the smallest capacity. However, in this particular application, both the edges _and_ the nodes have capacity constraints: there can be at most one ant at a time in a node, which implies that the edges also have a capacity of 1. Given this requirement, what we want to find is the maximum amount of _vertex disjoint paths_ from the source node to the sink node. Here, "vertex disjoint" means that paths do not share any nodes.

To ensure that the paths found by the max flow algorithm will be vertex disjoint, the following transformation is applied: each of the nodes ``n`` of the input graph is split into to two nodes, ``n_in`` and ``n_out``. All the incoming edges of the original node ``n`` will be connected to the ``n_in`` node, and all outgoing edges of ``n`` will be connected to ``n_out``. In addition, an edge from ``n_in`` to ``n_out`` is added. This operation transforms the node capacities into edge capacities, making it possible to employ a "regular" max flow algorithm that is only concerned with edge capacities.

The second transformation relates to the particular maximum flow algorithm that is employed, the Edmonds-Karp algorithm. The algorithm relies on so-called _reverse edges_. These are constructed by adding for every edge ``u -> v`` in the graph a corresponding reverse edge going in the opposite direction, ``v -> u``, with a capacity of 0.

### The Edmonds-Karp algorithm

The Edmonds-Karp algorithm is an algorithm that finds a maximum flow for a given network of nodes, connected by edges with capacities. All edges of the graph are associated with a flow that is initialized to 0. The algorithm operates by repeating a search for an _augmenting flow_ in the graph until no more augmenting flows are found. If an augmenting flow is found (a path from the source to the sink along which, for all edges ``e``, ``current flow through e < capacity of e``), the flows of the edges and their corresponding reverse edges along the path are updated.

What guarantees that the Edmonds-Karp algorithm always finds the maximum flow is the use of reverse edges. Whenever flow is added to an edge, the negative of the same amount is added its reverse edge: intuitively, this makes it possible to change the already found paths by _reversing_ or canceling flow on an edge. In addition, Edmonds-Karp searches for augmenting paths with a breadth-first search, ensuring that at each iteration it will find the shortest possible augmenting path.

In this case, we run the Edmonds-Karp algorithm on the transformed graph with a slight modification. Normally, Edmonds-Karp only returns the value of the maximum flow. Our implementation of the algorithm returns an array that contains the combinations of paths that the algorithm has found at each iteration of searching for an augmenting path. This means that for a graph with a max flow of n (n disjoint paths), our result is an array that contains n combinations of paths, the amount of paths ranging from 1 to n. This is done so that we can later optimize the path use for different amounts of ants.

### Optimising the path use

The goal of the project is to minimize the rounds needed to move the ants from the source to the sink. At each round, each ant in the graph can be moved once, with no collisions among the ants. The amount of ants to send through the network thus determines how many paths should be used, and the relative lengths of the paths in a specific set of paths determines how many ants should be sent down each path.

The choice of the set of paths and ants per path is done as follows: started from the path combination with least amount of paths (one, shortest path of the network), the overall "cost" of moving ants (number of rounds needed) is calculated for each combination of paths, assuming that all the paths in the combination are used. That is, if the max flow is n, first the cost of moving the ants is calculated for using the 1 shortest path, then the combination of 2 shortest paths, and so on. Among these, the paths with the lowest overall cost are chosen.

## Output

If the input file does not have the correct form, the program displays ``ERROR`` on the stderr. Otherwise, it will print the contents of the input file, followed by rounds of moves to guide the ants from source to sink. Each line of output corresponds to one round. Each move in a round is designated by ``L<ant_number>-<destination-node-id>``.

For example, the example input given above would produce the following output:

```
10
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment

L1-2 L2-3
L1-4 L3-2 L2-5 L4-3
L1-0 L3-4 L5-2 L2-6 L4-5 L6-3
L3-0 L5-4 L7-2 L2-0 L4-6 L6-5 L8-3
L5-0 L7-4 L9-2 L4-0 L6-6 L8-5
L7-0 L9-4 L10-2 L6-0 L8-6
L9-0 L10-4 L8-0
L10-0
```

## Compiling and running the program

Running ``make`` in the root of the repository compiles the program and produces an executable named ``lem-in``. Its usage options can be seen by running ``./lem-in -h`` or ``./lem-in --help``. The simplest way to run it is with ``./lem-in < input_file``.

## Relevant reading:

[Maximum flow problem](https://en.wikipedia.org/wiki/Maximum_flow_problem)

- [Edmonds-Karp algorithm](https://en.wikipedia.org/wiki/Edmonds–Karp_algorithm)

- [Ford-Fulkerson algorithm](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm)

[Vertex-disjoint paths](https://courses.helsinki.fi/sites/default/files/course-material/4671514/max-flow-reductions.pdf)
