#!/bin/bash

# Check Python version

if ! hash python3; then
    echo "python is not installed"
    exit 1
fi

ver=$(python3 -V 3>&1 | sed 's/.* \([0-9]\).\([0-9]\).*/\1\2/')

if [ "$ver" -lt "38" ]; then
    echo "This script requires python 3.8 or greater"
    exit 1
fi

# Initialize the environment

cd visualizer
python3 -m venv venv-vis
source venv-name/bin/activate
pip3 install -r requirements.txt
cd ..

# Run lem-in and put output to a file

./lem-in -f $1 > graph_visualization.txt

# Run visualizer (output always to graph_visualization.html)

python3 visualizer/test.py graph_visualization.txt

# Check for -o flag for renaming output files and open html in browser

HTML=".html"
TXT=".txt"
if [ $2 = "-o" ];
then
	mv graph_visualization.html "$3$HTML"
	mv graph_visualization.txt "$3$TXT"
	xdg-open "$3$HTML"
else
	xdg-open "graph_visualization.html"
fi

# Deactivate

deactivate
