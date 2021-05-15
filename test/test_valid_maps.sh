#!/bin/bash

output_dir="valid_test_output"
test_map_dir="test/other_maps"

mkdir -p $output_dir

make
make re -C lem_in_validator
if [ $? != 0 ]
then
	echo "Compiling lem_in_validator failed"
	exit 1
fi

for map in $test_map_dir/*
do
	echo "----------------------------------------------"
	echo $map
	subdir="$output_dir/$map"
	mkdir -p $subdir
	if [ $? != 0 ]
	then
		echo "Generating a map failed"
		exit 1
	fi
	output="$subdir/output"
	time ./lem-in < $map > $output
	if [ $? != 0 ]
	then
		echo "Error occurred"
		exit 1
	fi
	./lem_in_validator/lem_in_validator < $output
	echo "----------------------------------------------"
done