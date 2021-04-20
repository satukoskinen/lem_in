for f in eval_tests/p1_tests/*.test
do
	mv "$f" "${f%.test}"
done
echo "PART 1 norm check"
~/.norminette/norminette.rb -R CheckForbiddenSourceHeader ft_atoi.c ft_bzero.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
ft_toupper.c libft.h > norm_check
cat norm_check | egrep 'Error|Warning' > norm_errors
if [ -s norm_errors ]
then
	cat norm_check
else
	echo "OK"
fi
echo "PART 1 make check"
make fclean && make all && make re && make clean > make_check
if [ -s make_check ]
then
	cat make_check
else
	echo "OK"
fi
echo "PART 1 tests"
cp libft.h eval_tests/
gcc -Wall -Wextra -Werror -o test_part1 eval_tests/p1_tests/*.c -L. -lft
./test_part1
rm norm_check norm_errors make_check test_part1 libft.a eval_tests/libft.h
for f in eval_tests/p1_tests/*
do
	mv "$f" "${f}.test"
done