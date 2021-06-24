#!/usr/bin/env python
# coding: utf-8

import sys
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from pyvis.network import Network

START_COLOR="#284ced"
SINK_COLOR="#f0700e"
PATH_NODE_COLOR="#ff2a6d"
PATH_EDGE_COLOR="#ff2a6d"
OTHER_COLOR="#05d9e8"
BACKGROUND_COLOR="#01012b"
NODE_FONT_COLOR="#d1f7ff"
IMG_HEIGHT_DEFAULT="750px"
IMG_WIDTH_DEFAULT="750px"

def	plot_nx(G, nodes):
		plt.gca().invert_yaxis()
		plt.gca().invert_xaxis()
		nx.draw(G, nodes, with_labels = True)

def	get_img_dimensions():
	img_height = IMG_HEIGHT_DEFAULT
	img_width = IMG_WIDTH_DEFAULT
	for i in range(0, len(sys.argv)):
		if sys.argv[i] == "--height" and i != len(sys.argv) - 1:
			img_height = "{}px".format(sys.argv[i + 1])
		elif sys.argv[i] == "--width" and i != len(sys.argv) - 1:
			img_width = "{}px".format(sys.argv[i + 1])
	return (img_height, img_width)

def	open_file():
	if (len(sys.argv) < 2):
		print("Pass lem-in output file as argument")
		sys.exit(1)
	try:
		file = open(sys.argv[1])
	except FileNotFoundError:
		print("Cannot open file {}".format(sys.argv[1]))
		sys.exit(1)
	return file

def	parse_graph(file):
	nodes = dict()
	edges = []
	ant_paths = dict()
	start_node = None
	sink_node = None

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
	file.close()
	paths = ant_paths.values()
	unique_paths = list(set(tuple(x) for x in paths))

	G = nx.Graph()
	G.add_nodes_from(nodes.keys())
	nx.set_node_attributes(G, nodes, 'pos')
	G.add_edges_from(edges)
	return G, unique_paths, start_node, sink_node

def	set_node_attribute(nt, node_id, attribute, value):
	node = nt.get_node(node_id)
	node[attribute] = value

def	set_node_name(nt, node_id, name):
	node = nt.get_node(node_id)
	node["label"] = name

def	set_node_color(nt, node_id, color):
	node = nt.get_node(node_id)
	node["color"] = color

def	set_node_size(nt, node_id, size):
	node = nt.get_node(node_id)
	node["size"] = size

def	get_node_color(nt, node_id):
	node = nt.get_node(node_id)
	if "color" in node.keys():
		return node["color"]
	else:
		return None

def	set_colors(nt, unique_paths, start_node, sink_node):
	set_node_color(nt, start_node, START_COLOR)
	set_node_color(nt, sink_node, SINK_COLOR)
	for edge in nt.edges:
		edge["color"] = OTHER_COLOR
	for path in unique_paths:
		for i in range(1, len(path)):
			node = nt.get_node(path[i])
			node["color"] = PATH_NODE_COLOR
			for edge in nt.edges:
				if ((edge["from"] == path[i - 1] and edge["to"] == path[i]) or
					(edge["to"] == path[i - 1] and edge["from"] == path[i])):
						edge["color"] = PATH_EDGE_COLOR
	set_node_color(nt, start_node, START_COLOR)
	set_node_color(nt, sink_node, SINK_COLOR)

def	main():
	file = open_file()
	graph, unique_paths, start_node, sink_node = parse_graph(file)
	img_height, img_width = get_img_dimensions()
	network = Network(height=img_height, width=img_width)
	network.font_color=NODE_FONT_COLOR
	network.bgcolor=BACKGROUND_COLOR
	network.from_nx(graph)
	set_colors(network, unique_paths, start_node, sink_node)
	set_node_name(network, start_node, "S")
	set_node_name(network, sink_node, "T")
	set_node_size(network, start_node, 20)
	set_node_size(network, sink_node, 20)

	if "--show-menu" in sys.argv:
		network.show_buttons(filter_=['physics'])
	network.show("graph_visualization.html")

if __name__ == "__main__":
	main()
