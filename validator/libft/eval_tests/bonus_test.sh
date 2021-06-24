for f in eval_tests/bonus_tests/*.test
do
	mv "$f" "${f%.test}"
done
echo "BONUS norm check"
~/.norminette/norminette.rb -R CheckForbiddenSourceHeader ft_lstnew.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
ft_lstpushback.c ft_lstsize.c ft_isspace.c > norm_check
cat norm_check | egrep 'Error|Warning' > norm_errors
if [ -s norm_errors ]
then
	cat norm_check
else
	echo "OK"
fi
echo "BONUS make check"
make fclean && make all && make re && make clean > make_check
if [ -s make_check ]
then
	cat make_check
else
	echo "OK"
fi
echo "BONUS tests"
cp libft.h eval_tests/
gcc -Wall -Wextra -Werror -o test_bonus eval_tests/bonus_tests/*.c -L. -lft
./test_bonus
rm -f norm_check norm_errors make_check test_bonus libft.a eval_tests/libft.h
for f in eval_tests/bonus_tests/*
do
	mv "$f" "${f}.test"
done