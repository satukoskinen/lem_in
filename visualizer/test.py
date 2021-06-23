#!/usr/bin/env python
# coding: utf-8

import sys
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from pyvis.network import Network

nodes = dict()
edges = []
ant_paths = dict()
start_node = None
sink_node = None

if (len(sys.argv) != 2):
	print("Pass lem-in output file as argument")
	sys.exit(1)
file = sys.argv[1]
try:
	file = open(sys.argv[1])
except:
	print("Cannot open file {}".format(sys.argv[1]))
	exit(1)

prev = None
for line in file:
	line = line.strip()
	if line == "":
		break
	node_elems = line.split(" ")
	if len(node_elems) == 3:
		nodes[node_elems[0]] = (int(node_elems[1]), int(node_elems[2]))
	if prev == "##start":
		start_node = node_elems[0]
	elif prev == "##end":
		sink_node = node_elems[0]
	else:
		edge_elems = line.split("-")
	if len(edge_elems) == 2:
		edges.append((edge_elems[0], edge_elems[1]))
		edges.append((edge_elems[1], edge_elems[0]))
	prev = line

for line in file:
	line = line.strip()
	moves = line.split(" ")
	for move in moves:
		move_elems = move.split("-")
		if move_elems[0] not in ant_paths.keys():
			ant_paths[move_elems[0]] = [start_node]
		ant_paths[move_elems[0]].append(move_elems[1])

paths = ant_paths.values()
unique_paths = list(set(tuple(x) for x in paths))

G = nx.Graph()
#G = nx.DiGraph()
G.add_nodes_from(nodes.keys())
nx.set_node_attributes(G, nodes, 'pos')
G.add_edges_from(edges)

# plt.gca().invert_yaxis()
# plt.gca().invert_xaxis()
# nx.draw(G, nodes, with_labels = True)

nt = Network(notebook=True)
nt.from_nx(G)

for path in unique_paths:
	for i in range(1, len(path)):
#		node = nt.get_node(path[i])
#		node["color"] = "red"
		for edge in nt.edges:
			if ((edge["from"] == path[i - 1] and edge["to"] == path[i]) or
				(edge["to"] == path[i - 1] and edge["from"] == path[i])):
				edge["color"] = "red"

#nt.show_buttons(filter_=['physics'])
nt.show("graph_visualization.html")
