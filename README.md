# Lem-in

![alt test](https://github.com/satukoskinen/lem_in/blob/ddc144eff875d2fdf5ff5d9692cb75f4a5389148/pic/subject_3_flow2.png "Network")

A [42 school](https://en.wikipedia.org/wiki/42_(school)) project completed as a part of studies at [Hive Helsinki](https://www.hive.fi/en/).

Authors:

Satu Koskinen https://github.com/satukoskinen

Julius Koskela https://github.com/juliuskoskela

- [Lem-in](#lem-in)
	- [Project Summary](#project-summary)
	- [Input](#input)
	- [Algorithm](#algorithm)
		- [Transforming the Graph](#transforming-the-graph)
		- [The Edmonds-Karp Algorithm](#the-edmonds-karp-algorithm)
		- [Optimising Path Use](#optimising-path-use)
	- [Output](#output)
	- [Compiling and Running the Program](#compiling-and-running-the-program)
	- [Additional Tools](#additional-tools)
		- [Visualizer](#visualizer)
		- [Validator](#validator)
		- [Test scripts](#test-scripts)
	- [Relevant Reading](#relevant-reading)

## Project Summary

You are given an "ant farm", a network of rooms with links connecting the rooms. Each network will have a source and a destination (sink) room. The task is to optimize the flow of ants through the network from source to sink with any given number of ants.

[Subject](https://github.com/satukoskinen/lem_in/blob/master/lem-in.en.pdf) pdf.

Uses the [core](https://github.com/juliuskoskela/core) library.

## Input

Input to the program is comprised of the amount of ants followed by rooms (nodes) and links (edges) connecting the rooms. The source and sink nodes are designated by preceding ``##start`` and ``##end`` commands. Each node has a unique name and coordinates. Each [undirected edge](https://mathinsight.org/definition/undirected_graph) link is saved as two directed edges between the nodes, producing a [directed graph](https://en.wikipedia.org/wiki/Directed_graph).

```c

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

The assignment can be interpreted as a special case of finding the [maximum flow](https://en.wikipedia.org/wiki/Maximum_flow_problem) of a graph. The goal, however, is not only to find the maximum flow through the network (in this case, to be precise, the maximum amount of [vertex-disjoint paths](https://courses.helsinki.fi/sites/default/files/course-material/4671514/max-flow-reductions.pdf)), but to determine the optimal combinations of paths through which to move the given amount of ants.

To solve the problem, the program proceeds as follows:

1. Parse the input and save it as a directed graph
2. Transform the input graph into the form required by the max flow algorithm and the restrictions imposed by the subject
3. Run the [Edmonds-Karp algorithm](https://en.wikipedia.org/wiki/Edmonds???Karp_algorithm) on the transformed graph to find the possible path combinations up to the maximum flow
4. Given the number of ants, determine the optimal combination of paths to use and how many ants to send down each individual path
5. Print rounds of moves that move all ants from source to sink along the determined paths

### Transforming the Graph

In order to apply the max flow algorithm on the graph, the input graph needs to go through two different transformations.

In a typical formulation of computing a max flow through a flow network, only the edges between the nodes have capacity constraints that specify how much flow can simultaneously pass through an edge. On a given path from source to sink, the maximum amount of flow that can be sent through that one path is therefore determined by the edge with the smallest capacity. However, in this particular application, both the edges _and_ the nodes have capacity constraints: there can be at most one ant at a time in a node, which implies that the edges also have a capacity of 1. Given this requirement, what we want to find is the maximum amount of _vertex disjoint paths_ from the source node to the sink node. Here, "vertex disjoint" means that paths do not share any nodes.

![Basic input graph](pic/bottleneck_graph.png)

To ensure that the paths found by the max flow algorithm will be vertex disjoint, the following transformation is applied: each of the nodes ``n`` of the input graph is split into to two nodes, ``n_in`` and ``n_out``. All the incoming edges of the original node ``n`` will be connected to the ``n_in`` node, and all outgoing edges of ``n`` will be connected to ``n_out``. In addition, an edge from ``n_in`` to ``n_out`` is added. This operation transforms the node capacities into edge capacities, making it possible to employ a "regular" max flow algorithm that is only concerned with edge capacities.

![Transformed input graph](pic/bottleneck_transformed_graph.png)

The second transformation relates to the particular maximum flow algorithm that is employed, the Edmonds-Karp algorithm. The algorithm relies on so-called _reverse edges_. These are constructed by adding for every edge ``u -> v`` in the graph a corresponding reverse edge going in the opposite direction, ``v -> u``, with a capacity of 0.

### The Edmonds-Karp Algorithm

The Edmonds-Karp algorithm is an algorithm that finds a maximum flow for a given network of nodes, connected by edges with capacities. All edges of the graph are associated with a flow that is initialized to 0. The algorithm operates by repeating a search for an _augmenting flow_ in the graph until no more augmenting flows are found. If an augmenting flow is found (a path from the source to the sink along which, for all edges ``e``, ``current flow through e < capacity of e``), the flows of the edges and their corresponding reverse edges along the path are updated.

What guarantees that the Edmonds-Karp algorithm always finds the maximum flow is the use of reverse edges. Whenever flow is added to an edge, the negative of the same amount is added its reverse edge: intuitively, this makes it possible to change the already found paths by _reversing_ or canceling flow on an edge. In addition, Edmonds-Karp searches for augmenting paths with a breadth-first search, ensuring that at each iteration it will find the shortest possible augmenting path.

In this case, we run the Edmonds-Karp algorithm on the transformed graph with a slight modification. Normally, Edmonds-Karp only returns the value of the maximum flow. Our implementation of the algorithm returns an array that contains the combinations of paths that the algorithm has found at each iteration of searching for an augmenting path. This means that for a graph with a max flow of n (n disjoint paths), our result is an array that contains n combinations of paths, the amount of paths ranging from 1 to n. This is done so that we can later optimize the path use for different amounts of ants.

### Optimising Path Use

The goal of the project is to minimize the rounds needed to move the ants from the source to the sink. At each round, each ant in the graph can be moved once, with no collisions among the ants. The amount of ants to send through the network thus determines how many paths should be used, and the relative lengths of the paths in a specific set of paths determines how many ants should be sent down each path.

The choice of the set of paths and ants per path is done as follows: started from the path combination with least amount of paths (one, shortest path of the network), the overall "cost" of moving ants (number of rounds needed) is calculated for each combination of paths, assuming that all the paths in the combination are used. That is, if the max flow is n, first the cost of moving the ants is calculated for using the 1 shortest path, then the combination of 2 shortest paths, and so on. Among these, the paths with the lowest overall cost are chosen.

## Output

If the input file does not have the correct form, the program displays ``ERROR`` on the stderr. Otherwise, it will print the contents of the input file, followed by rounds of moves to guide the ants from source to sink. Each line of output corresponds to one round. Each move in a round is designated by ``L<ant_number>-<destination-node-id>``.

For example, the example input given above would produce the following output:

```c

// Input part

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

// Output part

L1-2 L2-3
L1-4 L3-2 L2-5 L4-3
L1-0 L3-4 L5-2 L2-6 L4-5 L6-3
L3-0 L5-4 L7-2 L2-0 L4-6 L6-5 L8-3
L5-0 L7-4 L9-2 L4-0 L6-6 L8-5
L7-0 L9-4 L10-2 L6-0 L8-6
L9-0 L10-4 L8-0
L10-0

```

## Compiling and Running the Program

Running ``make`` in the root of the repository compiles the program and produces an executable named ``lem-in``. Its usage options can be seen by running ``./lem-in -h`` or ``./lem-in --help``. The simplest way to run it is with ``./lem-in < input_file``, piping the input file to the standard input of the program.

## Additional Tools

### Visualizer

We have set up a simple Python script to create a visualization of the graph and paths that have been used. It makes use of the ``networkx`` and ``pyvis`` libraries. To run it, you need to have at least Python3.3.x, pip and venv installed. Running the script ``vis_env.sh`` from the ``visualizer`` directory sets up a new virtual environment in which it installs the packages needed by the Python program. Then, you can run the visualizer by running ``visualizer/vis.sh input_file`` from the root of the repository where the input file is equivalent to one you would pass on to the lem-in program. The script runs lem-in with the input file and passes the output to the Python program, which creates a visualization of it as an html file (``graph_visualization.html`` by default) that the script then opens in the browser.

Alternatively, the Python program can be directly run with e.g. ``python3 visualizer/visualize.py output_file`` where output_file contains the output of the lem-in program. The generic usage is the following (assuming that ``vis_env.sh`` has been run):
```
source visualizer/venv_vis/bin/activate
python3 visualizer/visualize.py output_file [--width img_width] [--height img_height] [--show-menu]
deactivate
```

![Part of a visualization of a larger input map](pic/big_2.png)

In the resulting visualization, the nodes and edges that belong to a path that is used to move the ants are coloured red, and unused nodes and edges are blue. Source and sink node names have been replaced with ``S`` and ``T``, respectively, and are colored violet. By giving the ``--show-menu`` option, the "physics" setup of the visualization can be altered in the browser.

### Validator

The validator program goes through the output produced by the lem-in program and checks that the output is valid: all ants are moved from source to destination, ants do not collide (get moved to the same node), and proper paths that connect the source node to the sink node are used. It can be compiled and run from the root of the repository as follows:
```sh
make -C validator
./lem-in < input_file | ./validator/lem_in_validator #or ./validator/lem_in_validator < output_file
```

### Test scripts

There are three test scripts in the ``test`` directory that can be run from the root of the repository. ``test_error_maps.sh`` runs all the invalid input files from the ``test/error_maps`` directory, ``test_valid_maps.sh`` runs all valid input files from a particular directory (by default ``test/generator_maps``) and ``test_superposition_maps.sh`` runs the map/input generator program, runs it, and then passes the result to the validator. Note that the ``generator`` executable in the ``test`` directory only works on macOS.  

## Relevant Reading

[Maximum flow problem](https://en.wikipedia.org/wiki/Maximum_flow_problem)

- [Edmonds-Karp algorithm](https://en.wikipedia.org/wiki/Edmonds???Karp_algorithm)

- [Ford-Fulkerson algorithm](https://en.wikipedia.org/wiki/Ford???Fulkerson_algorithm)

[Vertex-disjoint paths](https://courses.helsinki.fi/sites/default/files/course-material/4671514/max-flow-reductions.pdf)
