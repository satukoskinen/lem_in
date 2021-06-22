#!/bin/sh

##############
### config ###
##############

CFLAGS="-Wall -Wextra -Werror -g" #-fsanitize=address" #compiler flags
#CFLAGS="-g"
INCLUDES="-I . -I inc" #ft_printf.h location
LDFLAGS="-L . -l core" #-fsanitize=address" #static library and its location

path_to_testdir="print"

#######################
### test norminette ###
#######################

#printf "\nTest norme... "
#norminette . > norm_output
#grep -B 1 "Error" norm_output > norm_errors
#if [ -s norm_errors ]
#then
#	printf "Norme errors:\n"
#	cat norm_errors
#	exit 1
#else
#	printf "Norme OK\n"
#fi

#rm -f norm_output norm_errors

#################
### test make ###
#################

#make fclean && make && make clean
#if [ $? != 0 ]
#then
#	exit 1
#fi

#make all && make re && make fclean && make && make clean
#if [ $? != 0 ]
#then
#	printf "make error\n"
#	exit 1
#fi


###################
### basic tests ###
###################

for f in $path_to_testdir/printf_test/src/*.test
do
	mv "$f" "${f%.test}"
done

rm -f test_exe

printf "\nBasic tests...\n\n"

test_srcs="$path_to_testdir/printf_test/src/test*.c"
gcc -o test_exe $CFLAGS $path_to_testdir/printf_test/src/main.c $test_srcs $INCLUDES $LDFLAGS
if [ $? != 0 ]
then
	printf "compilation error"
	exit 1
fi

run_test () {
	local test_name=$1
	local user_output="user_output_$test_name"
	local test_output="test_output_$test_name"
	local diff="diff_$test_name"

	printf "Run %-30s" "$test_name..."
	{ ./test_exe ft_printf $test_name > $user_output; } 2> err_output
	if [ $? != 0 ]
	then
		printf "seg fault: run './test_exe ft_printf $test_name' for more info"
		cat err_output
		exit 1
	fi
	./test_exe printf $test_name > $test_output
	diff --text --suppress-common-lines -p $user_output $test_output > $diff
	if [ -s $diff ]
	then
		printf "error, see $diff\n"
	#	exit 1
	else
		printf "diff OK\n"
		rm $diff $user_output $test_output
	fi
}

run_pointer_test () {
	local test_name=$1
	local output="ptr_output"
	local user_output="user_output_$test_name"
	local test_output="test_output_$test_name"
	local diff="diff_$test_name"

	printf "Run %-30s" "$test_name..."
	{ ./test_exe ft_printf $test_name > $output; } 2> err_output
	if [ $? != 0 ]
	then
		printf "seg fault: run './test_exe ft_printf $test_name' for more info"
		cat err_output./
		exit 1
	fi
	line_count=$(cat $output | wc -l | sed "s/ //g")
	head -n $(( $line_count / 2 )) $output > $user_output
	tail -n $(( $line_count / 2 )) $output > $test_output
	diff --text --suppress-common-lines -p $user_output $test_output > $diff
	if [ -s $diff ]
	then
		printf "error, see $diff\n"
	#	exit 1
	else
		printf "diff OK\n"
		rm $output $user_output $test_output $diff
	fi
}

for test in $test_srcs
do
	test_name="${test#$path_to_testdir/printf_test/src/}"
	test_name="${test_name%.c}"
	if [ $test_name == "test_pointer" ]
	then
		run_pointer_test $test_name
	else
		run_test $test_name
	fi
done

for f in $path_to_testdir/printf_test/src/*.[ch]
do
	mv "$f" "${f}.test"
done

###################
### test leaks ###
###################

echo ""
read -n 1 -p "Test leaks with valgrind [v] or leaks [l]? " leaks
if [ $leaks == "v" ]
then
	printf "\n\nTesting leaks with valgrind...\n\n"
	./test_exe ft_printf all valgrind > valgrind_output
elif [ $leaks == "l" ]
then
	printf "\n\nTesting leaks with leaks...\n\n"
	./test_exe ft_printf test_all leaks > leaks_output
	grep -a -e "nodes malloced" -A 1 leaks_output
else
	echo ""
fi

rm -f valgrind_output leaks_output err_output
