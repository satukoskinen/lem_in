#!/bin/bash

# Check command line arguments

if [ $# == 0 ]
then
	echo "Usage: bash vis.sh [-a ant_count] [-o output_name] input_file"
	exit 1
fi

for i in $@; do :; done
input_file=$i
html_output="graph_visualization.html"
lem_output="lem_output.txt"
optstring="o:a:"
OFLAG=0
while getopts $optstring arg;
do
	case $arg in
	o)
		html_output="${OPTARG}.html"
		OFLAG=1
		;;
	a)
		ant_count=${OPTARG}
		sed -i "1s/.*/$ant_count/" $input_file
		;;
	esac
done

# Run lem-in and put output to a file

./lem-in < $input_file > $lem_output

if [ $? != 0 ]
then
	exit 1
fi

# Run visualizer (output always to graph_visualization.html)

source visualizer/venv-vis/bin/activate

python3 visualizer/visualize.py $lem_output --width 1280 --height 720 ##--show-menu


if [ $OFLAG == 1 ]
then
	mv graph_visualization.html $html_output
fi

case "$OSTYPE" in
  darwin*)  open $html_output ;;
  linux*)   xdg-open $html_output ;;
  msys*)    start $html_output ;;
  *)        echo "unknown: $OSTYPE" ;;
esac
