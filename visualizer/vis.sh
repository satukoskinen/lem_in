#!/bin/bash

# Run lem-in and put output to a file

./lem-in -f $1 > graph_visualization.txt

# Run visualizer (output always to graph_visualization.html)

python3 visualizer/test.py graph_visualization.txt

# Check for -o flag for renaming output files and open html in browser

HTML=".html"
TXT=".txt"
if [[ $2 == "-o" ]];
then
	mv graph_visualization.html "$3$HTML"
	mv graph_visualization.txt "$3$TXT"
	xdg-open "$3$HTML"
else
	xdg-open "graph_visualization.html"
fi

