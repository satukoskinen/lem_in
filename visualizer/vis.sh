#!/bin/bash

# Check command line arguments

if [ $# == 0 ]
then
	echo "Usage: bash vis.sh [-a ant_count] [-o output_name] input_file"
	exit 1
fi

html_output="graph_visualization.html"

optstring=":o:a"
while getopts $optstring arg;
do
	case $arg in
	o)
		html_output="$OPTARG.html"
		mv graph_visualization.html $html_output
		mv graph_visualization.txt "$OPTARG.txt"
		;;
	a)
		ant_count=$OPTARG
		echo $OPTARG
		for i in $@; do :; done
		sed -i '' "1s/.*/$ant_count/" $i
		;;
	esac
done

# Run lem-in and put output to a file

./lem-in < $i > graph_visualization.txt
if [ $? != 0 ]
then
	exit 1
fi

# Run visualizer (output always to graph_visualization.html)

source visualizer/venv-vis/bin/activate

python3 visualizer/visualize.py graph_visualization.txt --show-menu

deactivate

# Check for -o flag for renaming output files and open html in browser


case "$OSTYPE" in
  darwin*)  open $html_output ;; 
  linux*)   xdg-open $html_output ;;
  msys*)    start $html_output ;;
  *)        echo "unknown: $OSTYPE" ;;
esac
