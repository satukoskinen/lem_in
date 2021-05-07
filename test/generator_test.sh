#!/bin/sh

dir="gen_test_output"

mkdir -p $dir

repeat=10

for (( i=0; i < $repeat; i++ ))
do
	echo "----------------------------------------------"
	echo $i
	subdir="$dir/$i"
	mkdir -p $subdir
	map="$subdir/map_$i"
	./test/generator --big-superposition > $map
	grep "Here" -m 1 $map
	output="$subdir/output_$i"
	time ./lem_in < $map > $output
	./lem_in_validator/lem_in_validator < $output
	echo "----------------------------------------------"
done
