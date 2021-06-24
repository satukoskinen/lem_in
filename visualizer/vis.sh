#!/bin/bash

# Check command line argument

if [ $# != 1 ]
then
	echo "Usage: bash vis.sh input_file"
	exit 1
fi

# Run lem-in and put output to a file

./lem-in < $1 > graph_visualization.txt
if [ $? != 0 ]
then
	exit 1
fi

# Run visualizer (output always to graph_visualization.html)

source visualizer/venv-vis/bin/activate

python3 visualizer/visualize.py graph_visualization.txt

deactivate

# Check for -o flag for renaming output files and open html in browser

HTML=".html"
TXT=".txt"
if [[ $2 == "-o" ]];
then
	html_output="$3$HTML"
	mv graph_visualization.html $html_output
	mv graph_visualization.txt "$3$TXT"
else
	html_output="graph_visualization.html"
fi

case "$OSTYPE" in
  darwin*)  open $html_output ;; 
  linux*)   xdg-open $html_output ;;
  msys*)    start $html_output ;;
  *)        echo "unknown: $OSTYPE" ;;
esac
