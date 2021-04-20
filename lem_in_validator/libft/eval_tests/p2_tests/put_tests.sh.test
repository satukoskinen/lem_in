for test in eval_tests/p2_tests/put*_test.c
do
	gcc -Wall -Wextra -Werror -L. -lft $test -o user_exe
	./user_exe > user_output
	test_name="ft_${test/eval_tests\/p2_tests\//}"
	test_output="${test/.c/_exe}"
	if [ -e ${test_output/test_exe/user_output} ]
	then
		chmod 755 ${test_output/test_exe/user_output}
		diff ${test_output/test_exe/user_output} $test_output > diff_output1
		if [ -s diff_output1 ]
		then
			echo "${test_name/_test/}:"
			echo "ERROR: diff fd_user_output test_output"
			cat -e diff_output1
		fi
	fi
	diff user_output $test_output > diff_output2
	if [ -s diff_output2 ]
	then
		echo "${test_name/_test/}:"
		echo "ERROR: diff user_output test_output"
		cat -e diff_output2
	else
		echo "${test_name/_test/}:	OK"
	fi
	rm -f user_exe user_output ${test_output/test_exe/user_output} diff_output1 diff_output2
done