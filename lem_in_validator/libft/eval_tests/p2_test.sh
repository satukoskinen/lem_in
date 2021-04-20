for f in eval_tests/p2_tests/*.test
do
	mv "$f" "${f%.test}"
done
echo "PART 2 norm check"
~/.norminette/norminette.rb -R CheckForbiddenSourceHeader ft_itoa.c ft_memalloc.c ft_memdel.c \
ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
ft_putstr_fd.c ft_putstr.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c \
ft_strsub.c ft_strtrim.c > norm_check
cat norm_check | egrep 'Error|Warning' > norm_errors
if [ -s norm_errors ]
then
	cat norm_check
else
	echo "OK"
fi
echo "PART 2 make check"
make fclean && make all && make re && make clean > make_check
if [ -s make_check ]
then
	cat make_check
else
	echo "OK"
fi
echo "PART 2 tests"
cp libft.h eval_tests/
gcc -Wall -Wextra -Werror -o test_part2 eval_tests/p2_tests/[^p]*.c -L. -lft
./test_part2
./eval_tests/p2_tests/put_tests.sh
rm norm_check norm_errors make_check test_part2 libft.a eval_tests/libft.h
for f in eval_tests/p2_tests/*
do
	mv "$f" "${f}.test"
done