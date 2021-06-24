#!/bin/bash

output_dir="gen_test_output"

mkdir -p $output_dir

repeat=10

make
make re -C validator
if [ $? != 0 ]
then
	echo "Compiling lem_in_validator failed"
	exit 1
fi

for (( i=0; i < $repeat; i++ ))
do
	echo "----------------------------------------------"
	echo $i
	subdir="$output_dir/$i"
	mkdir -p $subdir
	map="$subdir/map_$i"
	./test/generator --big-superposition > $map
	if [ $? != 0 ]
	then
		echo "Generating a map failed"
		exit 1
	fi
	grep "Here" -m 1 $map
	output="$subdir/output_$i"
	time ./lem-in < $map > $output
	if [ $? != 0 ]
	then
		echo "Error occurred"
		exit 1
	fi
	./validator/lem_in_validator < $output
	echo "----------------------------------------------"
done
