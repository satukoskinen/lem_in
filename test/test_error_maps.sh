#!/bin/bash

map_dir="test/error_maps"

for map in $map_dir/*
do
	echo "./lem-in < $map"
	#leaks --atExit -- ./lem-in < $map
	./lem-in < $map
	echo ""
done
